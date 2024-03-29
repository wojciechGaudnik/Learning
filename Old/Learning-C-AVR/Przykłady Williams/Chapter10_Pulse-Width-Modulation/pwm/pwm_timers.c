﻿                       /* PWM Demo with serial control over three LEDs */

// ------- Preambuła -------- //
#include <avr/io.h>                        /* Definiuje piny, porty, itd. */
#include <util/delay.h>                     /* Funkcje marnujące czas */
#include "pinDefines.h"
#include "USART.h"

static inline void initTimers(void) {
  // Timer 1 A,B
  TCCR1A |= (1 << WGM10);                      /* Szybki tryb PWM, 8-bitów */
  TCCR1B |= (1 << WGM12);                       /* Szybki tryb PWM, część 2. */
  TCCR1B |= (1 << CS11);                     /* Częstotliwość PWM = F_CPU/8/256 */
  TCCR1A |= (1 << COM1A1);                      /* Wyjście PWM na OCR1A */
  TCCR1A |= (1 << COM1B1);                      /* Wyjście PWM na OCR1B */

  // Timer 2
  TCCR2A |= (1 << WGM20);                             /* Szybki tryb PWM */
  TCCR2A |= (1 << WGM21);                       /* Szybki tryb PWM, część 2. */
  TCCR2B |= (1 << CS21);                     /* Częstotliwość PWM = F_CPU/8/256 */
  TCCR2A |= (1 << COM2A1);                      /* Wyjście PWM na OCR2A */
}

int main(void) {

  uint8_t brightness;

  // -------- Inicjalizacja --------- //

  initTimers();
  initUSART();
  printString("-- LED PWM Demo --\r\n");

  /* włącz tryb wyjścia na pinach z diodami LED, będą przełączane przez sprzęt PWM */
  LED_DDR |= (1 << LED1);
  LED_DDR |= (1 << LED2);
  LED_DDR |= (1 << LED3);

  // ------ Pętla zdarzeń ------ //
  while (1) {

    printString("\r\nWprowadz wspolczynnik wypelnienia PWM (0-255): ");
    brightness = getNumber();
    OCR2A = OCR1B;
    OCR1B = OCR1A;
    OCR1A = brightness;

  }                                                  /* Koniec pętli zdarzeń */
  return (0);                            /* Ta instrukcja nie zostanie wykonana */
}
