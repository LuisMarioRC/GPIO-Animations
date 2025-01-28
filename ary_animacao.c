#include <stdint.h>
#include "hardware/pio.h"

#define FRAMES_ARY 5
#define NUM_PIXELS 25

static bool desenho[FRAMES_ARY][NUM_PIXELS] = {{0, 0, 1, 0, 0,
                        0, 0, 1, 1, 0, 
                        1, 0, 1, 0, 0,
                        0, 0, 1, 0, 0,
                        0, 0, 1, 0, 0},
                        
                        {0, 0, 1, 0, 0,
                        0, 0, 0, 0, 0, 
                        0, 1, 1, 1, 0,
                        0, 0, 0, 0, 0,
                        0, 0, 1, 0, 0},

                        {0, 1, 1, 1, 0,
                        1, 0, 0, 0, 1, 
                        1, 0, 0, 0, 1,
                        1, 0, 0, 0, 1,
                        0, 1, 1, 1, 0},

                        {0, 0, 0, 0, 0,
                        0, 1, 1, 1, 0, 
                        0, 0, 0, 0, 0,
                        0, 1, 1, 1, 0,
                        0, 0, 0, 0, 0},

                        {0, 0, 0, 0, 0,
                        0, 1, 0, 1, 0, 
                        1, 0, 1, 0, 1,
                        0, 1, 0, 1, 0,
                        0, 0, 0, 0, 0}};

//rotina para acionar a matrix de leds - ws2812b
void animacao_ary(PIO pio, uint sm){
    uint32_t valor_led;
    for (int16_t j = 0; j < FRAMES_ARY; j++) {

        for (int16_t i = 0; i < NUM_PIXELS; i++) {
            valor_led = matrix_rgb(desenho[j][24-i], 0, 0);
            pio_sm_put_blocking(pio, sm, valor_led);

        }
    }
}

//rotina para definição da intensidade de cores do led
static uint32_t matrix_rgb(double b, double r, double g)
{
  unsigned char R, G, B;
  R = r * 255;
  G = g * 255;
  B = b * 255;
  return (G << 24) | (R << 16) | (B << 8);
}