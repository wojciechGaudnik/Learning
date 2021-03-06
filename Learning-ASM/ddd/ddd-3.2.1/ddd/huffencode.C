// $Id: huffencode.C,v 1.14 2000/01/03 12:12:15 andreas Exp $ -*- C++ -*-
// Huffman-encode standard input

// Copyright (C) 1996-1998 Technische Universitaet Braunschweig, Germany.
// Written by Andreas Zeller <zeller@gnu.org>.
// 
// This file is part of DDD.
// 
// DDD is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
// 
// DDD is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public
// License along with DDD -- see the file COPYING.
// If not, write to the Free Software Foundation, Inc.,
// 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
// 
// DDD is the data display debugger.
// For details, see the DDD World-Wide-Web page, 
// `http://www.gnu.org/software/ddd/',
// or send a mail to the DDD developers <ddd@gnu.org>.

char huffencode_rcsid[] = 
    "$Id: huffencode.C,v 1.14 2000/01/03 12:12:15 andreas Exp $";

#include <limits.h>
#include <iostream.h>
#include <strstream.h>
#include <stdlib.h>
#include <stdio.h>

#include "assert.h"
#include "strclass.h"
#include "cook.h"
#include "DynArray.h"
#include "bool.h"

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif

// A node of the Huffman tree
struct HuffNode {
    bool isleaf;
    union {
	struct {		// Internal node:
	    HuffNode *left;	// Left child   (0)
	    HuffNode *right;	// Right child  (1)
	} i;
	struct {		// Leaf node:
	    char c;		// Character
	} l;
    };
    int sum;			// Sum of the weights in the leaves
    HuffNode *next;		// For queue usage
    int number;			// For print usage

    // Constructor - internal node
    HuffNode(HuffNode *l, HuffNode *r)
	: isleaf(false), sum(l->sum + r->sum), next(0)
    {
	i.left  = l;
	i.right = r;
    }

    // Constructor - leaf node
    HuffNode(char c, int s)
	: isleaf(true), sum(s), next(0)
    {
	l.c = c;
    }
};

// Insert NODE into QUEUE such that the node with maximum sum comes first
static void insert(HuffNode*& queue, HuffNode *node)
{
    if (queue == 0)
    {
	queue = node;
    }
    else if (queue->sum > node->sum)
    {
	node->next = queue;
	queue = node;
    }
    else
    {
	insert(queue->next, node);
    }
}

// Extract the node with minimum sum from QUEUE (i.e. the last)
static HuffNode *extract_min(HuffNode*& queue)
{
    HuffNode *node = queue;
    if (queue != 0)
	queue = queue->next;
    return node;
}

// Create a queue sorted according to occurrences of charatcer in S
static HuffNode *initial_queue(const string& s)
{
    int occurrences[UCHAR_MAX + 1];

    unsigned int c;
    for (c = 0; c < UCHAR_MAX + 1; c++)
	occurrences[c] = 0;
    for (int i = 0; i < int(s.length()); i++)
	occurrences[(unsigned char)s[i]]++;

    HuffNode *queue = 0;
    for (c = 0; c < UCHAR_MAX + 1; c++)
	if (occurrences[c] > 0)
	    insert(queue, new HuffNode(c, occurrences[c]));

    return queue;
}

// Return the length of QUEUE
static int length(HuffNode *queue)
{
    int len = 0;
    while (queue != 0)
    {
	len++;
	queue = queue->next;
    }

    return len;
}

// Create a Huffman tree from S
static HuffNode *huffman(const string& s)
{
    HuffNode *queue = initial_queue(s);
    int n = length(queue);

    for (int i = 0; i < n - 1; i++)
    {
	HuffNode *x = extract_min(queue);
	HuffNode *y = extract_min(queue);
	insert(queue, new HuffNode(x, y));
    }

    return extract_min(queue);
}

// Write Huffman tree TREE on standard output
static void write_huffman(HuffNode *tree)
{
    static int tics = 0;

    if (tree == 0)
	return;

    if (tree->isleaf)
    {
	tree->number = tics++;
	cout << "static const HuffCode _huff" << tree->number 
	     << " = {0, (HuffCode *)'" << cook(tree->l.c) << "'};\n";
    }
    else
    {
	write_huffman(tree->i.left);
	write_huffman(tree->i.right);

	tree->number = tics++;
	cout << "static const HuffCode _huff" << tree->number 
	     << " = {&_huff" << tree->i.left->number 
	     << ", &_huff" << tree->i.right->number << "};\n";
    }
}

// Fill CODES[C] with a [01]+ string denoting the encoding of C in TREE
static void init_codes(string codes[UCHAR_MAX + 1], HuffNode *tree, 
		       string prefix = "")
{
    if (tree == 0)
	return;

    if (tree->isleaf)
    {
	codes[(unsigned char)tree->l.c] = prefix;
    }
    else
    {
	init_codes(codes, tree->i.left,  prefix + "0");
	init_codes(codes, tree->i.right, prefix + "1");
    }
}

// Convert a [01]+ string to a byte
static char bits_to_byte(const string& bits)
{
    unsigned char c = 0;

    for (int i = 0; i < int(bits.length()); i++)
	c = (c << 1) | (bits[i] == '0' ? 0 : 1);

    // clog << "bits_to_byte(" << cook(bits) << ") = " << int(c) << "\n";

    return (char)c;
}

// Number of bits per character
const int BITS_PER_CHAR = 8;

// Encode TEXT using the Huffman tree TREE
static string encode(const string& text, HuffNode *tree)
{
    string codes[UCHAR_MAX + 1];

    init_codes(codes, tree);

    if (tree != 0)
    {
	unsigned int c;
	cout << "// Encoding:\n";
	for (c = 0; c < UCHAR_MAX + 1; c++)
	{
	    if (codes[c] != "")
		cout << "// '" << cook((char)(unsigned char)c)
		     << "'\t" << codes[c] << "\n";
	}
    }

    ostrstream bit_encoding_os;
    int i;
    for (i = 0; i < int(text.length()); i++)
	bit_encoding_os << codes[(unsigned char)text[i]];
    string bit_encoding(bit_encoding_os);

    // cout << "\n// " << bit_encoding << "\n";

    ostrstream byte_encoding;
    for (i = 0; i < int(bit_encoding.length()) - BITS_PER_CHAR; 
	 i += BITS_PER_CHAR)
    {
	byte_encoding << bits_to_byte(bit_encoding.at(i, BITS_PER_CHAR));
    }
    byte_encoding << bits_to_byte(bit_encoding.from(i));

    return byte_encoding;
}

// Write encoded text BYTE_ENCODING on standard output
static void write_encoding(const string& byte_encoding)
{
    cout << "static const char hufftext[" 
	 << byte_encoding.length() + 1 << "] = \n\"";

    int p = 0;

    while (p < int(byte_encoding.length()))
    {
	if (p > 0 && p % 16 == 0)
	    cout << "\"\n\"";

	static char buffer[256];
	sprintf(buffer, "\\%03o", int((unsigned char)byte_encoding[p]));
	cout << buffer;

	p++;
    }

    cout << "\";\n";
}    

// Read the string S from standard input
static void read_input(string& s)
{
    ostrstream os;
    char c;

    while (cin.get(c))
	os << c;

    s = os;
}

// Main program.  Read a text from standard input, write huffman tree
// and encoded text on standard output.
int main()
{
    string text;

    read_input(text);
    HuffNode *tree = huffman(text);
    string encoding = encode(text, tree);

    if (tree != 0)
    {
	cout << "\n";
	write_huffman(tree);
	cout << "\n";
	cout << "static const HuffCode *const huffcode = &_huff" 
	     << tree->number << ";\n";
    }
    else
    {
	cout << "static const HuffCode *const huffcode = 0;\n";
    }

    cout << "static const int hufflength = " << text.length() << ";\n";

    write_encoding(encoding);

    return EXIT_SUCCESS;
}
