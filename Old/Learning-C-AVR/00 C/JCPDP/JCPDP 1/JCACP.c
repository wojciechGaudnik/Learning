#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
//#include <inttypes.h>

//int power(int m, int n);

void binarnie (unsigned int n);

void jcacp(void){
    system("chcp 1250");
    // 0 - 48, 9 - 57, A - 65, Z - 90, a - 97, z - 122
    int i, j;
    char c1, c2, c3, c4;
    c1 = c2 = c3 = c4 = 0;
    i = j = 0;
    char s1[] = "g-hA-C";
    char s2[200] = {1};


    while(s1[i] != 0){
        if(c1 == 0 && ((s1[i] >= 48 && s1[i] <= 57) || (s1[i] >= 65 && s1[i] <= 90) || (s1[i] >= 97 && s1[i] <= 122)))
            c1 = s1[i];
        if(c2 == 0 && (c1 != s1[i] &&  ((s1[i] >= 48 && s1[i] <= 57) || (s1[i] >= 65 && s1[i] <= 90) || (s1[i] >= 97 && s1[i] <= 122))))
            c2 = s1[i];
        if(c3 == 0 && (c1 != s1[i] && c2 != s1[i] &&  ((s1[i] >= 48 && s1[i] <= 57) || (s1[i] >= 65 && s1[i] <= 90) || (s1[i] >= 97 && s1[i] <= 122))))
            c3 = s1[i];
        if(c4 == 0 && (c1 != s1[i] && c2 != s1[i] && c3 != s1[i] &&  ((s1[i] >= 48 && s1[i] <= 57) || (s1[i] >= 65 && s1[i] <= 90) || (s1[i] >= 97 && s1[i] <= 122))))
            c4 = s1[i];
        i++;
    }
    printf("c1 = %c\nc2 = %c\nc3 = %c\nc4 = %c\n", c1, c2, c3, c4);

    s2[0] = c1;
    for(i = 1; s2[i - 1] != c2; i++){
        s2[i] = c1 + i;
    }
    s2[i] = c3;
    i++;
    j = 1;
    for(;s2[i - 1] != c4; i++,j++){
        s2[i] = c3 + j;
    }

    printf("%s\n", s2);









    return;
}

void binarnie (unsigned int n){
    int i;
    putchar('0');
    putchar('b');
    for(i = 31; i >= 0 ; i--){
        putchar('0' + (((n >> i) & 0x01L)));
        if(i == 0) printf("\n");
    }
}

/*
    int c, i, biale, inne, cyfry[10];

    biale = inne = 0;
    for(i = 0; i < 10; i++)
        cyfry[i] = 0;
    while((c = getchar()) != EOF){
        switch(c){
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            cyfry[c -'0']++;
            break;
        case ' ': case '\n': case '\t':
            biale++;
            break;
        default:
            inne++;
            break;
        }
    }
    printf("Cyfry:\n");
    for(i = 0; i < 10; i++){
        printf("%d:\t%d\n",i, cyfry[i]);
    }
    printf("Bia�e: \t%d\n", biale);
    printf("Inne: \t%d\n", inne);
*/




/*
#define size 100000

    int tab[size];
    int i,c, low, high, mid;
    int x = 1399;
    tab[0] = 400;

    for(i = 1; i < size; i++)
        tab[i] = tab[i - 1] + 1;

    low = 0;
    high = size - 1;
    mid = size / 2;

    while(low <= high){
        if(tab[mid] == x){
            c = mid;
            break;
        }else if(tab[mid - 1] == x){
            c = mid - 1;
            break;
        }else if(tab[mid + 1] == x){
            c = mid + 1;
            break;
        }
        mid = (low + high) / 2;
        if(x < tab[mid])
            high = mid + 1;
        else if(x > tab[mid])
            low = mid + 1;
    }


    printf("x = %d   miejse = %d     tab[%d] = %d\n", x, c, c, tab[c]);
    printf("%d  %d\n",tab[0],size - tab[0]);
*/



/*
    unsigned int bit1, bit2, bit3, bit4, bitbuf, maska, maska2, maskabuf;
    int p, n, i;
    char c;
    p = 0;
    bit1 = 0b11111111111111110000000000000000;

    c = 'a';
    printf("%c %d\n", c, c);
    c = 'z';
    printf("%c %d\n", c, c);
    c = 'A';
    printf("%c %d\n", c, c);
    c = 'D';
    printf("%c %d\n", c, c);

    (c >= 'A' || c <= 'Z') ? c = c + ('a' - 'A') : printf("poza zakresem\n");
    printf("%c %d", c, c);
*/




/*
    binarnie(bit1);
    //binarnie(bit1 - 0b1);
    //bit1 &= (bit1 - 1);
    //binarnie(bit1);


    for(i = 0; bit1 != 0; bit1 &= (bit1 - 0b1))
        p++;
    printf("%d\n",p);
    for(n = 0 ; n <= 10; n++){
        printf("You have %d item%s.\n", n, n == 1 ? "" : "s");
    }




    for(i = 0; bit1 != 0; bit1 >>= 1){ //liczenie 1 bitowych
        if(bit1 & 0b1) p++;
    }
    printf("%d",p);
*/



/*    for(i = 0; bit1 != 0; bit1 >>= 1){ liczenie 1 bitowych
        if(bit1 & 0b1) p++;
        binarnie(bit1);
        printf("%d\n\n",p);
    }
*/


/* przesuni�cie bitowe z przeniesieniem
   unsigned int bit1, bit2, bit3, bit4, bitbuf, maska, maska2, maskabuf;
    int p, n, i;


    p = 15;  // pozycja
    n = 60;  // ilo��
    bit1 = 0b11111111111111110000000000000000;
    bit2 = 0b00000000000000000000000000000001;
    for(;n > 0; n--){
        bit3 = bit2 & bit1;
        bit3 = bit3 << 31;
        bit1 = bit1 >> 1;
        bit1 = bit1 | bit3;
        binarnie(bit1);
    }
*/


/*
    p = 15;  // pozycja
    n = 5;  // ilo��
    bit1 = 0b10101010101010101010101010101010;
    binarnie(bit1);
    bit2 = bit3 = bitbuf = 0;
    maska = maska2 = 0;
    for(i = n; i >= 0; i--){
        maskabuf = 1 << (i - 1);
        maska = maska | maskabuf;
    }
    binarnie(maska);
    maska = maska << (p - n);
    binarnie(maska);
    bit2 = ~bit1;
    binarnie(bit2);
    bit3 = bit2 ^ maska;
    binarnie(bit3);
    bit3 = ~bit3;
    binarnie(bit3);
*/







/*    for(p = 0; p < 15; p++){



        bit3 = (bit1 >> (p + 1 - n)); // & ~(~0 << n));
        bit3 = ~(~0 << n);
        bit4 = bit2 & bit3;

        binarnie(bit4);
    }
*/




/*
    unsigned int bit1, bit2, bit3, bit4;;
    int p, n;


    p = 15; // pozycja
    n = 3; // ilo��
    for(p = 0; p < 15; p++){
        bit1 = 0b01010101010101010101010101010101;
        bit1 = 0b11111111000000000000000011111111;
        bit2 = (bit1 >> (p + 1 - n)); // & ~(~0 << n));
        bit3 = ~(~0 << n);
        bit4 = bit2 & bit3;
        printf("\n\n p = %d\n", p);
        printf(" n = %d\n", n);
        binarnie(bit1);
        binarnie(bit2);
        binarnie(bit3);
        binarnie(bit4);
    }
*/




/*
    char n, m;

    n = 0b00000001;
    m = 0b00001000;

    n = n << 2;

    m = m & ~0b00001000;

    binarnie(n);
    printf("\nm = ");
    binarnie(m);
    binarnie(n & m);
    n = n & 0b00000000;
    n = n | 0b00001111;

    binarnie(n);
    printf("\n%d\n", n);
*/


/*
    int i = 0;
    int j = 0;
    int x;
    char c;
    char tab[100];
    char tabbuf[100];

    printf("Wprowad� �a�cuch 1: ");
    while((c = getchar()) != '\n'){
        tab[i] = c;
        i++;
    }
    tab[i] = 0;
    i = 0;
    printf("Wprowad� �a�cuch 2: ");
        while((c = getchar()) != '\n'){
        tabbuf[i] = c;
        i++;
    }
    tabbuf[i] = 0;
    i = 0;
    printf("%s %s", tab, tabbuf);

    x = 0;

    while(tab[i] != 0 && x == 0){
        for(j = 0; tabbuf[j] != 0; j++){
            if(tab[i] == tabbuf[j]){
                printf("\nPierwsze wyst�pienie znaku z �2 w �1 jest w miejscu %d", i + 1);
                x++;
                break;
            }
        }
        i++;
    }
*/


/*
    printf("Wprowad� �a�cuch do zmiany: ");
    scanf(" %s", tab);
    printf("Wprowad� jakie ci�gi usun��: ");
    scanf(" %s", tabbuf);
    x = strlen(tabbuf);

    for(i = 0; tab[i] != 0; i++){
        for(j = 0; tab[i + j] == tabbuf[j]; j++);
        if(x == j)
            for(j = 0;tab[i + j] != 0; j++){
                tab[i + j] = tab[i + j + x];
                if(tab[i + j + x + 1] == 0) tab[i + j + 1] = 0;
            }
    }
    printf("Tablica po usuni�ciu ci�g�w: %s\n", tab);
*/

/*
    int i = 0;
    int j = 0;
    char c;
    char tab[100];
    char x;

    scanf(" %s", tab);
    scanf(" %c", &x);
    for(i = j = 0; tab[i] != '\0'; i++){
        if(tab[i] != x)
            tab[j++] = tab[i];
    }
    tab[j] = '\0';



    printf("%s", tab);
*/



/*
    int liczba = 0;
    int i = 0;
    char c;
    char tab[100];

    while((c = getchar()) != EOF){
        tab[i] = c;
        i++;
    }
    tab[--i] = 0;

    for(i = 0; c != 0; i++){
        c = tab[i];
        if(c != 0){
            if(c >= '0' && c <= '9'){
                liczba = 16 * liczba + (tab[i] - '0');
            }
            if(c >= 'a' && c <= 'f'){
                liczba = 16 * liczba + (10 + (tab[i] - 'a'));
            }
            //i++;
        }
    }
    printf("%d\n", liczba);
    printf("%x\n", liczba);
*/

/*
    int i;
    unsigned long long j;
    i = -1l;
    j = 1ul;

    printf("%d  %lld", i, j);
    if(i < j) printf("ok");
    j = (unsigned long long) i;
    printf("%d  %lld", i, j);
*/

/*
    char  tab[20];
    int i;
    long long n;
    char c;
    i = 0;
    n = 0;

        while((c = getchar()) != EOF){
            tab[i] = c;
            i++;
        }

        for(i = 0; tab[i] >= '0' && tab[i] <= '9';i++)
            n = 10 * n + (tab[i] - '0');
        printf("Puść tą kurwę   %lld\n",n);
*/


/*
#define gran 200
    char tab[gran];
    int i;
    char c;

    for(i = 0; i < gran - 1 && (c = getchar()) != '\n' && c != EOF; ++i){
        tab[i] = c;
    }
    tab[i] = 0;
    printf("%s   teraz drugi raz\n", tab);

    i = 0;
    while((c = getchar()) != EOF){
        if(c != '\n')
            tab[i] = c;
            i++;

    }
    printf("%s\n", tab);
*/



/*
// lata przestępne !!!
    int rok;
    int i;
    for(i = 1980; i < 2020; i++){
        rok = i;
        if((rok % 4 == 0 && rok % 100 != 0) || rok % 400 == 0)
            printf("%d to rok przestępny\n", rok);
        else
            printf("%d to rok nie przestępny\n", rok);
    }
*/


/*

char tab[10];
int i;

    for(i = 0; i < 10; i++){
        tab[i] = 1;
    }
    *(tab + 0) = 'x';
    printf("%s\n",tab);
    strcpy(tab,"a");
    printf("%s\n",tab);
*/

/*
char tab[100];
size_t c;
int i = 0;

    while((c = getchar()) != EOF){
        tab[i] = c;
        i++;
    }

    printf("%x\n", *(tab + 0));

    c = strlen(tab);
    printf("%d\n", c);
*/



/*
    printf("char max: \t\t%d\t\t\tmin: %d\t\tbajtów: %d\n", CHAR_MAX, CHAR_MIN, sizeof(char));
    printf("short max: \t\t%d\t\t\tmin: %d\t\tbajtów: %d\n", SHRT_MAX, SHRT_MIN, sizeof(short));
    printf("int max: \t\t%d\t\tmin: %d\tbajtów: %d\n", INT_MAX, INT_MIN, sizeof(int));
    printf("long max: \t\t%ld\t\tmin: %ld\tbajtów: %d\n", LONG_MAX, LONG_MIN, sizeof(long));


    printf("unsigned char max: \t%u\t\t\tmin: %d\t\t\tbajtów: %d\n", UCHAR_MAX, 0, sizeof(unsigned char));
    printf("unsigned short max: \t%u\t\t\tmin: %d\t\t\tbajtów: %d\n", USHRT_MAX, 0, sizeof(unsigned short));
    printf("unsigned int max: \t%u\t\tmin: %d\t\t\tbajtów: %d\n", UINT_MAX, 0, sizeof(unsigned int));
    printf("unsigned long max: \t%lu\t\tmin: %d\t\t\tbajtów: %d\n", ULONG_MAX, 0, sizeof(unsigned long));
*/


/*
    i = 1234567UL;
    printf("%i\n",i);
    for(i = 0; i < 00; i++){
        printf("%d\n", i);
    }
    printf("%d\n", i);
*/

/*
char tab[500] = {0};
char tabbuf[500]  = {0};
char c;
int i = 0;
int j = 0;
int a = 0;
int b = 0;

    while((c = getchar()) != EOF){
        a++;
        if(a > 9){
            if(c != ' ' && c != '\t'){
                tab[i] = c;
                i++;
                continue;
            }
            if(c == ' '){
                tab[i] = '\n';
                a = 0;
                i++;
                continue;
            }

        }
        tab[i] = c;
        i++;
    }
    printf("%s", tab);    int i = 0;
    char c;
    char tab[100];

    while((c = getchar()) != EOF){
        tab[i] = c;
        i++;
    }
    tab[--i] = 0;
*/


/*
    printf("123456789123456789\n");
    printf("a\ta\ta\n\n");

    while((c = getchar()) != EOF){
        //tabbuf[i] = c;
        //i++;
        if(c == ' '){
            a++;
            continue;
        }
        if(a > 0 && a < 8){
            for(;a > 0; a--){
                tab[i] = ' ';
                i++;
            }
            a = 0;
            //i--;
        }
        if(a > 7 && c != ' '){
            j = a / 7;
            for(;j > 0; j--){
                tab[i] = '\t';
                if(j > 0) i++;
            }
            j = a % 7;
            for(;j > 1; j--){
                tab[i] = ' ';
                if(j > 0) i++;
            }

            //continue;
        }
        //j = a % 7;
        //if(j > 1) i = i - j + 1;
        a = 0;

        //if(c == '\t'){
        //    for(j = 0; j < 7; j++,i++){
        //        tab[i] = ' ';
        //    }
        //continue;
        //}
        tab[i] = c;
        i++;
    }
    printf("%s", tab);
*/




/*
int getline(char s[], int lim){
    int c,i;
    char b[20];
    for(i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
        b[i] = c;
    if(c == '\n'){
        //i++;
        b[i] = '\0';
    }

    //s[i] = '\0';
    c = 0;
    char x;
    for(i = strlen(b) - 1; i >= 0; i--){
        x = b[i];
        s[c] = x;
        c++;
    }
    s[c] = '\0';
    printf("%s\n", s);
    return c;
}

void copy(char to[], char from[]){
    int i;

    i = 0;
    while((to[i] = from[i]) != '0')
        i++;
}



#define MAXLINE 1000


    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while((len = getline(line, MAXLINE)) > 0 && printf("%d %s", len, line))
        if(len > max){
            max = len;
            copy(longest, line);
        }
    if(max > 0)
        printf("%s", longest);
*/







/*
#define MAXLINE 1000

int getline(char s[], int lim){
    int c,i;
    for(i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if(c == '\n'){
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]){
    int i;

    i = 0;
    while((to[i] = from[i]) != '0')
        i++;
}
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while((len = getline(line, MAXLINE)) > 0)
        if(len > max){
            max = len;
            copy(longest, line);
        }
    if(max > 0)
        printf("%s", longest);
*/



/*
int power(int base, int n){
    int p;
    for(p = 1; n > 0; n--)
        p *= base;
    return p;
}

    int liczba, potega;
    printf("Podaj liczbe i potege:");
    scanf(" %d %d", &liczba, &potega);
    printf("Wynik: %d\n", power(liczba,potega));
*/




/*
#define LOWER -30
#define UPPER 300
#define STEP 5

float zmiana(int celcius){
    return (((9.0/5.0) * (float)(celcius + STEP)) + 32.0);
}


    int celcius;

    printf("Celsjusz \tFahrenheit\n");
    for(celcius = LOWER; celcius < UPPER; celcius + STEP)
        printf("%d\t\t%6.2f\n", celcius += STEP, zmiana(celcius));
*/



/*
    int i;

    for(i = 0; i < 10; i++)
        printf("%d %d %d\n", i, power(2,i), power(-3,i));
*/



/*    int c, i, j;
    int tab[20] = {0};
    i = 0;
    j = 0;
    //c = 0;
    //while((c = getchar()) == EOF) continue;
    while((c = getchar()) != EOF){
        if((c == ' ') || c == 10){
            ++tab[i];
            i = 0;
        }
        if(c != ' ') i++;
        j++;
    }

    printf("S這wa 1 literowe: %d\n", tab[1]);
    printf("S這wa 2 literowe: %d\n", tab[2]);
    printf("S這wa 3 literowe: %d\n", tab[3]);
    printf("S這wa 4 literowe: %d\n", tab[4]);
    printf("S這wa 5 literowe: %d\n", tab[5]);
    printf("S這wa 6 literowe: %d\n", tab[6]);
    printf("S這wa 7 literowe: %d\n", tab[7]);
    printf("S這wa 7 literowe: %d\n", tab[8]);
    printf("S這wa 7 literowe: %d\n", tab[9]);
    printf("S這wa 7 literowe: %d\n", tab[10]);
    printf("S這wa 7 literowe: %d\n", tab[11]);
    printf("S這wa 7 literowe: %d\n", tab[12]);
    printf("S這wa 7 literowe: %d\n", tab[13]);
    printf("S這wa 7 literowe: %d\n", tab[14]);
    printf("S這wa 7 literowe: %d\n", tab[15]);

    getchar();
*/





/*
    int i,c;
    int tab[10] = {0};

    while((c = getchar()) != EOF)
        if(c >= '0' && c <= '9')
            tab[c - '0'] = tab[c - '0'] + 1;


    for(i = 0; i < 10; i++){
        printf("i = %d     %d\n",i, tab[i]);
    }
*/



/*
FILE *fptr;
    int i, c, nl, nt, ns;
    nl = 0;
    ns = 0;
    nt = 0;
    fptr = fopen("d:\\text.txt", "w");

    while((c = getchar()) != EOF){
        if(c == '\t'){
            for(i = 0; i < 2; i++){
                    if(i == 0) {
                            c = 92;
                            putchar(c);
                            fputc(c,fptr);
                    }
                    if(i == 1) {
                            c = 't';
                            putchar(c);
                            fputc(c,fptr);
                    }

            }
        continue;
        }
        putchar(c);
        fputc(c,fptr);

    }
    printf("wierszy:%d\n", nl);
    printf("spacji:%d\n", ns);
    printf("tabulator闚:%d\n", nt);
    fclose(fptr);

    fptr = fopen("d:\\text.txt", "r");
    for(i = 0; i < 100; i++){
        c = fgetc(fptr);
        printf("z pliku %d    %c\n", c, c);
        //if(c < 0) i = 100;
    }
    fclose(fptr);
*/




/*

FILE *fptr;
    fptr = fopen("d:\\text.txt", "w");
    int c, i;
    //printf("Warto EOF: %d\n", EOF);

    for(i = 0; i < 10; i++){
        c = getchar();
        printf("getchar() != EOF:\t\t %d,\t\t c = %d\n", c != EOF, c);
        fputc(c,fptr);
    }
    fclose(fptr);


    fptr = fopen("d:\\text.txt", "r");
    for(i = 0; i < 100; i++){
        c = fgetc(fptr);
        printf("z pliku %d    %c\n", c, c);
        //if(c < 0) i = 100;
    }
    fclose(fptr);
*/

/*
#define LOWER 0
#define UPPER 300
#define STEP 10

    double a = -123456789.123456789;
    printf("%015.2f", a);

    int celcius;
    printf("Fahrenheit \tCelsjusz");
    for(celcius = UPPER; celcius > LOWER; celcius - STEP)
        printf("%d\t\t%6.2f\n", celcius -= STEP, (float)((float)5/9) * ((celcius + STEP) - 32));
*/


/*    int celcius;
    printf("Fahrenheit \tCelsjusz");
    for(celcius = LOWER; celcius < UPPER; celcius + STEP)
        printf("%d\t\t%6.2f\n", celcius += STEP, (float)((float)5/9) * ((celcius + STEP) - 32));





    printf("Celsjusz \tFahrenheit\n");
    for(celcius = LOWER; celcius < UPPER; celcius + STEP)
        printf("%d\t\t%6.2f\n", celcius += STEP, (((9.0/5.0) * (float)(celcius + STEP)) + 32.0) );
*/









/*
==================================================================================================================================
=================================================================================================================================
*/


/*
int power(int base, int n){
    int i,p;
    p = 1;
    for(i = 1; i <= n; i++)
        p = p * base;
    return p;
}
*/
