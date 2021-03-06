/*
  Space Invaders autorstwa Elliota Williamsa
  Ta wersja zapisuje dane w tablicach,
  przegląda ich elementy w funkcji.
*/

#include <avr/io.h>
#include <util/delay.h>
#define DELAYTIME 2                                              /* ms */

#define LED_PORT                PORTB
#define LED_DDR                 DDRB

uint8_t invaderData1[] = {
  0b01110000,
  0b00011000,
  0b11111101,
  0b10110110,
  0b00111100,
  0b00111100,
  0b00111100,
  0b10110110,
  0b11111101,
  0b00011000,
  0b01110000
};

uint8_t invaderData2[] = {
  0b00001110,
  0b00011000,
  0b10111101,
  0b01110110,
  0b00111100,
  0b00111100,
  0b00111100,
  0b01110110,
  0b10111101,
  0b00011000,
  0b00001110
};


void pause(void){
	uint8_t i;
	for (i=0; i<5; i++){
		_delay_ms(DELAYTIME);
	}
}

void POVDisplay(uint8_t povData[], uint8_t numberRows) {
  uint8_t i;
  for (i = 0; i < numberRows; ++i) {
    LED_PORT = povData[i];
    _delay_ms(DELAYTIME);
  }
  pause();
}

int main(void) {

  LED_DDR = 0xff;                       /* przełącz wszystkie diody na wyjścia */ 

  while (1) {                                                  /* pętla główna */

      POVDisplay(invaderData1, sizeof(invaderData1));
      POVDisplay(invaderData2, sizeof(invaderData2));

  }                                                    /* koniec pętli głównej */
  return (0);
}
