#include "czescb.h"
#include <stdio.h>
#include <stdlib.h>
/*
int liczba_rzutow = 0;
static int rzucaj(int scianki){
    int oczka;
    oczka = rand() % scianki + 1;
    ++liczba_rzutow;
    return oczka;
}

int rzucaj_n_razy(int rzuty, int scianki){
    int k;
    int suma = 0;
    if(scianki < 2){
        printf("Wymagane sa co najmniej 2 scianki. \n");
        return -2;
    }
    if(rzuty < 1){
        printf("Wymagany co najmniej 1 rzut.\n");
        return -1;
    }
    for(k = 0; k < rzuty; k++)
        suma += rzucaj(scianki);
    return suma;
}
*/



/*
#include <stdio.h>
extern int liczba;
static int suma = 0;        // -------------(LP. 4) ------------- zmienna static, ��czno�� wewn�trzna
void sumuj(int k);
void sumuj(int k){
    static int podsuma = 0; // -------------(LP. 5) ------------- zmienna static, brak ��czno�ci
    if(k <= 0){
        printf("Cykl petli: %d\n", liczba);
        printf("Podsuma: %d; Suma: %d\n", podsuma, suma);
        podsuma = 0;
    }else{
        podsuma += k;
        suma += k;
    }
}
*/
