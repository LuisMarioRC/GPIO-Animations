#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdint.h>
#include "hardware/pio.h"

// Definições compartilhadas
#define LED_COUNT 25
#define BUZZER_PIN 22

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

void animacao_zigzag(uint8_t r, uint8_t g, uint8_t b);
void desenha_coracao(uint8_t r, uint8_t g, uint8_t b);
void desenha_seta(uint8_t r, uint8_t g, uint8_t b);
void animacao_coracao_1(uint8_t r, uint8_t g, uint8_t b);
void animacao_coracao_2(uint8_t r, uint8_t g, uint8_t b);
void animacao_coracao_3(uint8_t r, uint8_t g, uint8_t b);
void animacao_coracao_4(uint8_t r, uint8_t g, uint8_t b);
void animacao_coracao_5(uint8_t r, uint8_t g, uint8_t b);
void animacao_seta_1(uint8_t r, uint8_t g, uint8_t b);
void animacao_seta_2(uint8_t r, uint8_t g, uint8_t b);
void animacao_seta_3(uint8_t r, uint8_t g, uint8_t b);
void animacao_seta_4(uint8_t r, uint8_t g, uint8_t b);
void animacao_seta_5(uint8_t r, uint8_t g, uint8_t b);
//
#endif // GLOBALS_H
