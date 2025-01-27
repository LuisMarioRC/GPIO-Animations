#include "globals.h"
#include <unistd.h>

void desenha_seta(uint8_t r, uint8_t g, uint8_t b) {
    npClear();
    npSetLED(2, r, g, b);
    npSetLED(6, r, g, b);
    npSetLED(10, r, g, b);
    npSetLED(8, r, g, b);
    npSetLED(14, r, g, b);
    npSetLED(7, r, g, b);
    npSetLED(12, r, g, b);
    npSetLED(17, r, g, b);
    npSetLED(22, r, g, b);
    npWrite();
}

// Animações para  seta
void animacao_seta_1(uint8_t r, uint8_t g, uint8_t b) {
    desenha_seta(r, g, b);
    sleep_ms(200);
    desenha_seta(b, r, g);
    sleep_ms(200);
}

void animacao_seta_2(uint8_t r, uint8_t g, uint8_t b) {
    for (int i = 0; i < 3; i++) {
        desenha_seta(r, g, b);
        sleep_ms(100);
        desenha_seta(0, 0, 0);
        sleep_ms(100);
    }
}

void animacao_seta_3(uint8_t r, uint8_t g, uint8_t b){
    for (int i = 0; i < LED_COUNT; i++){
        npClear();
        npSetLED(i, r, g, b);
        npWrite();
        sleep_ms(50);
    }
}

void animacao_seta_4(uint8_t r, uint8_t g, uint8_t b){
    for (int i = LED_COUNT -1; i >= 0; i--){
        npClear();
        npSetLED(i, r, g, b);
        npWrite();
        sleep_ms(50);
    }
}

void animacao_seta_5(uint8_t r, uint8_t g, uint8_t b){
    for (int i = 0; i < LED_COUNT; i++){
        npSetLED(i, r, g, b);
    }
    npWrite();
    sleep_ms(500);
    npClear();
    npWrite();
    sleep_ms(500);
}
