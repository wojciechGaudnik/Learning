/* pomin2.c -- pomija pierwsze dwie z podanych liczb calkowitych */
#include <stdio.h>
int main(void)
{
   int n;

   printf("Podaj, prosze, trzy  liczby calkowite:\n");
   scanf("%*d %*d %d", &n);
   printf("Ostatnia podana liczba byla %d\n", n);
   return 0;
}

