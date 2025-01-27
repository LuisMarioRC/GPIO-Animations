#include "globals.h"
#include <unistd.h>

void animacao_zigzag(uint8_t r, uint8_t g, uint8_t b) {
    for (int frame = 0; frame < 5; frame++) {
        npClear();
        for (int i = 0; i < LED_COUNT; i++) {
            int intensity = (i + frame) % 5 == 0 ? 255 : 0;
            npSetLED(i, intensity, intensity / 2, intensity / 3); // Tons de roxo
        }
        npWrite(); // Atualiza os LEDs
        sleep_ms(250);
    }
    npClear();
    npWrite(); // Garante que os LEDs sejam apagados ao final
}
