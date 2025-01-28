#ifndef ANIMACAO_H
#define ANIMACAO_H

#include <stdint.h>
#include "hardware/pio.h"  // Dependência da API do microcontrolador

#define FRAMES_ARY 5
#define NUM_PIXELS 25

// Função para rodar animação
void animacao_ary(PIO pio, uint sm);

// Função para definir intensidade de cores
uint32_t matrix_rgb(double b, double r, double g);

#endif // ANIMACAO_H
