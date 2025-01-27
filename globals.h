#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdint.h>
#include "hardware/pio.h"

// Definições compartilhadas
#define LED_COUNT 25

extern PIO np_pio;
extern uint sm;

// Declaração de funções globais
void npClear();
void npWrite();
void npSetLED(const uint index, const uint8_t r, const uint8_t g, const uint8_t b);

// Declaração da função de animação
void animacao_ondas(uint8_t r, uint8_t g, uint8_t b);
/////void animacao_v(uint8_t r, uint8_t g, uint8_t b);
void animacao_v();

#endif // GLOBALS_H
