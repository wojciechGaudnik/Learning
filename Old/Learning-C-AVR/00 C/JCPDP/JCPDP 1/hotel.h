#ifndef HOTEL_H_INCLUDED
#define HOTEL_H_INCLUDED

#define KONIEC          5
#define HOTEL1          80.00
#define HOTEL2          125.00
#define HOTEL3          155.00
#define HOTEL4          200.00
#define RABAT           0.95
#define GWIAZDKI        "************************************"

int menu(void);
int pobierz_noce(void);
void pokaz_cene(double hotel, int noce);


#endif // HOTEL_H_INCLUDED
