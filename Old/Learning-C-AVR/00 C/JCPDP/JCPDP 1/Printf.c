

/*
        unsigned szerokosc, dokladnosc;
        int liczba = 256;
        double waga = 242.5;

        printf("Jaka szeroko�� pola?\n");
        scanf(" %d", &szerokosc);
        printf("Liczba jest r�wna : %*d:\n", szerokosc, liczba);
        printf("Teraz podaj szeroko�� i dok�adno��: \n");
        scanf(" %d %d", &szerokosc, &dokladnosc);
        printf("Waga = %*.*f\n", szerokosc, dokladnosc, waga);
*/


/*
        int wiek;
        float majatek;
        char zwierzatko[30];

        printf("Podaj sw�j wiek, maj�tek i ulubione pupis.\n");
        scanf(" %d %f", &wiek, &majatek);
        scanf("%s", zwierzatko);
        printf("%d, %.0f z�, %s\n", wiek, majatek, zwierzatko);
*/



/*


        printf("Oto jeden ze sposob�w wy�wietlania ");
        printf("d�ugich �a�cuch�w. \n");
        printf("Oto inny spos�b wy�wietlania \
d�ugiego �a�cucha.\n");
        printf("Oto najnowszy spos�b wy�wietlania "
               "d�ugiego �a�cucha. (ANSI C)\n");
*/




/*
        int n = 100;
        int wz;

        wz = printf("Woda wrze w temp. %d C.\n", n);
        printf("Funkcja printf() wy�wietla %d znaki.\n", wz);
*/



/*
        long long i = 123456789;

        printf("%lld\n",i);
        printf("%lld\n\n\n", LONG_LONG_MAX);

        float n1 = 3.0;
        double n2 = 3.0;
        long n3 = 2000000000;
        long n4 = 1234567890;

        printf("%.1e %.1e %.1e %.1e\n", n1, n2, n3, n4);
        printf("%ld %ld\n", n3, n4);
        printf("%ld %ld %ld %ld", n1, n2, n3, n4);
*/





/*
#define STRONY 336
#define SLOWA 65618


        short num = STRONY;
        short mnum = -STRONY;

        printf("num jako short i unsigned short: %hd %hu\n", num, num);
        printf("-num jako short i unsigned short: %hd %hu\n", mnum, mnum);
        printf("num jako int i char: %d %c\n", num, num);
        printf("SLOWA jako int, short i char: %d %hd\n", SLOWA, SLOWA, SLOWA);
*/





/*
#define NOTATKA "Doskona�a gra aktor�w!"

        printf("[%2s]\n", NOTATKA);
        printf("[%25s]\n", NOTATKA);
        printf("[%25.5s]\n", NOTATKA);
        printf("[%-25.5s]\n", NOTATKA);
*/


/*
        printf("%x %X %#x\n", 31, 31, 31);
        printf("%x %X %x\n", 31, 31, 31);
        printf("**%d**% d**% d**\n", 42, 42, -42);
        printf("**%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6);
*/


/*
   const double CZYNSZ = 2345.67;

        printf("*%f*\n", CZYNSZ);
        printf("*%e*\n", CZYNSZ);
        printf("*%4.2f*\n", CZYNSZ);
        printf("*%3.1f*\n", CZYNSZ);
        printf("*%10.3f*\n", CZYNSZ);
        printf("*%10.3E*\n", CZYNSZ);
        printf("*%+4.2f*\n", CZYNSZ);
        printf("*%010.2f*\n", CZYNSZ);
*/



/*
        #define STRONY 732

        int i;
        size_t j;

        printf("*%d*\n", STRONY);
        printf("*%2d*\n", STRONY);
        printf("*%10d*\n", STRONY);
        printf("*%-10d*\n", STRONY);
        printf("%d\n", sizeof(i));
        printf("%d\n", sizeof(j));
*/





/*
#define PI 3.141593

        int liczba = 5;
        float likier = 13.5;
        int koszt = 3100;

        printf("%d kobiet wypi�o %.2f kieliszk�w likieru. \n", liczba, likier);
        printf("Warto�� pi to %.4f.\n", PI);
        printf("�egnaj! Zbyt droga jeste�, pani, by by� moja ");
        printf("(%c%d)\n", '$', 2 * koszt);
*/



/*
        int fahr, celsius;
        int lower, upper, step;

        lower = 0;
        upper = 300;
        step = 20;

        fahr = lower;
        while (fahr <= upper){
            celsius = 5 * (fahr-32) / 9;
            printf("%d\t%d\n", fahr, celsius);
            fahr += step;
        }

        for (fahr=0; fahr <= 300; fahr += 20){
            printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
        }
*/




/*
float pensja;
      printf("Podaj miesi�czne wynagrodzenie, na jakie zas�ugujesz:");
      printf("_________ zl\b\b\b\b\b\b\b\b\b\b\b\b");
      scanf("%f", &pensja);
      printf("\n\t%.2f zl miesi�cznie to %.2f zl rocznie.",pensja, pensja * 12);
      printf("\rHo, ho!\n");
*/


/*
  float a,b;

        b = 2.0e20 + 1.0;
        a = b - 2.0e20;
        printf("%f \n", a);

*/




/*float aboat = 32000.0;
        double abet = 2.14e9;
        long double dip = 5.32e-5;

        printf("%f mo�na przedstawi� jako %e\n", aboat, aboat);
        printf("albo jako %a w szestnastkowym zapisie pot�gowym\n", aboat);

        printf("%f mo�na przedstawi� jako %e\n", abet, abet);
        printf("%f mo�na przedstawi� jako %e\n", dip, dip);
*/



/*
        int32_t me32;

        me32 = 45933945;
        printf("Po pierwsze, zalozmy, ze int32_t jest typu int: ");
        printf("me32 = %d\n", me32);
        printf("Nast�pnie nie czy�my �adnych za�o�e�.\n");
        printf("W zamian skorzystamy z \"macro\" z pliku inttypes.h: ");
        printf("me32 = %" PRId32 "\n", me32);
*/



/*
 unsigned char ch;

        printf("Wpisz jakis znak.\n");
        scanf(" %c", &ch);
        printf("Kod znaku %c to %d.\n", ch, ch);

        for (ch=0; ch <= 200; ch++){
                printf("Kod znaku %c to %d.\n", ch, ch);
        }
*/


/*
unsigned int un = 3000000000;
        short koniec = 200;
        long duza = 65537;
        long long bardzoduza = 12345678908642;

        printf("un = %u, lecz nie %d\n", un, un);
        printf("koniec = %hd, i %d\n", koniec, koniec);
        printf("duza = %ld, lecz nie %hd\n", duza, duza);
        printf("bardzoduza = %lld, lecz nie %ld\n", bardzoduza, bardzoduza);
*/

/*
float ciezar;
        float wartosc;

        printf("Czy jeste� tyle wart ile .....\n");
        printf("Podaj wag� w KG:");
        scanf(" %f", &ciezar);

        wartosc = 4250.0 * ciezar * 32.151;

        printf("Warto�� w z�ocie: %.2f zl\n", wartosc);

*/
