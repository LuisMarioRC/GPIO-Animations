#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "globals.h"

#include "ws2818b.pio.h"

#define LED_COUNT 25
#define LED_PIN 7

struct pixel_t {
    uint8_t G, R, B;
};
typedef struct pixel_t pixel_t;
typedef pixel_t npLED_t;

npLED_t leds[LED_COUNT];
PIO np_pio;
uint sm;

#define LINE1 14
#define LINE2 15
#define LINE3 16
#define LINE4 17

#define COL1 18
#define COL2 19
#define COL3 20
#define COL4 21

const char key_mapping[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

void setup_keypad() {

gpio_init(LINE1); gpio_set_dir(LINE1, GPIO_OUT);

gpio_init(LINE2); gpio_set_dir(LINE2, GPIO_OUT);

gpio_init(LINE3); gpio_set_dir(LINE3, GPIO_OUT);

gpio_init(LINE4); gpio_set_dir(LINE4, GPIO_OUT);



gpio_init(COL1); gpio_set_dir(COL1, GPIO_IN); gpio_pull_down(COL1);

gpio_init(COL2); gpio_set_dir(COL2, GPIO_IN); gpio_pull_down(COL2);

gpio_init(COL3); gpio_set_dir(COL3, GPIO_IN); gpio_pull_down(COL3);

gpio_init(COL4); gpio_set_dir(COL4, GPIO_IN); gpio_pull_down(COL4);

}



char read_keypad() {

for (int row = 0; row < 4; row++) {

gpio_put(LINE1, row == 0);

gpio_put(LINE2, row == 1);

gpio_put(LINE3, row == 2);

gpio_put(LINE4, row == 3);



for (int col = 0; col < 4; col++) {

if (gpio_get(COL1 + col)) {

return key_mapping[row][col];

}

}

}

return '\0';

}



void npInit(uint pin) {

uint offset = pio_add_program(pio0, &ws2818b_program);

np_pio = pio0;



sm = pio_claim_unused_sm(np_pio, false);

if (sm < 0) {

np_pio = pio1;

sm = pio_claim_unused_sm(np_pio, true);

}



ws2818b_program_init(np_pio, sm, offset, pin, 800000.f);



for (uint i = 0; i < LED_COUNT; ++i) {

leds[i].R = 0;

leds[i].G = 0;

leds[i].B = 0;

}

}



void npSetLED(const uint index, const uint8_t r, const uint8_t g, const uint8_t b) {

leds[index].R = r;

leds[index].G = g;

leds[index].B = b;

}



void npClear() {

for (uint i = 0; i < LED_COUNT; ++i)

npSetLED(i, 0, 0, 0);

}



void npWrite() {

for (uint i = 0; i < LED_COUNT; ++i) {

pio_sm_put_blocking(np_pio, sm, leds[i].G);

pio_sm_put_blocking(np_pio, sm, leds[i].R);

pio_sm_put_blocking(np_pio, sm, leds[i].B);

}

sleep_us(100);

}



void desenha_coracao(uint8_t r, uint8_t g, uint8_t b) {

npClear();

npSetLED(2, r, g, b);

npSetLED(6, r, g, b);

npSetLED(10, r, g, b);

npSetLED(14, r, g, b);

npSetLED(8, r, g, b);

npSetLED(16, r, g, b);

npSetLED(18, r, g, b);

npSetLED(12, r, g, b);




npWrite();

}



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



// Animações para o coração
void animacao_coracao_1(uint8_t r, uint8_t g, uint8_t b) {
    desenha_coracao(r, g, b);
    sleep_ms(200);
    desenha_coracao(b, r, g);
    sleep_ms(200);
}

void animacao_coracao_2(uint8_t r, uint8_t g, uint8_t b) {
    for (int i = 0; i < 3; i++) {
        desenha_coracao(r, g, b);
        sleep_ms(100);
        desenha_coracao(0, 0, 0);
        sleep_ms(100);
    }
}

void animacao_coracao_3(uint8_t r, uint8_t g, uint8_t b){
    for (int i = 0; i < LED_COUNT; i++){
        npClear();
        npSetLED(i, r, g, b);
        npWrite();
        sleep_ms(50);
    }
}

void animacao_coracao_4(uint8_t r, uint8_t g, uint8_t b){
    for (int i = LED_COUNT -1; i >= 0; i--){
        npClear();
        npSetLED(i, r, g, b);
        npWrite();
        sleep_ms(50);
    }
}

void animacao_coracao_5(uint8_t r, uint8_t g, uint8_t b){
    for (int i = 0; i < LED_COUNT; i++){
        npSetLED(i, r, g, b);
    }
    npWrite();
    sleep_ms(500);
    npClear();
    npWrite();
    sleep_ms(500);
}

// Animações para a seta
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

void clearLEDs() {

npClear();

npWrite();

}

int main() {
    stdio_init_all();
    setup_keypad();
    npInit(LED_PIN);
    npClear();

    char current_key = '\0'; // Variável para armazenar a tecla atual

    while (true) {
        char key = read_keypad();

        if (key != '\0' && key != current_key) { // Verifica se uma nova tecla foi pressionada
            current_key = key; // Atualiza a tecla atual
        }

        if (current_key == '1') {
            animacao_coracao_1(255, 0, 0);  //animação 1 em loop
            animacao_coracao_2(255, 0, 0);
            animacao_coracao_3(255, 0, 0);
            animacao_coracao_4(255, 0, 0);
            animacao_coracao_5(255, 0, 0);
        } else if (current_key == '2') {
            animacao_seta_1(255, 255, 0);  //animação 1 em loop
            animacao_seta_2(255, 255, 0);
            animacao_seta_3(255, 255, 0);
            animacao_seta_4(255, 255, 0);
            animacao_seta_5(255, 255, 0);
        } else if (current_key == '3') {
            animacao_ondas(0, 0, 255);
        } else if (current_key == 'A') {
            clearLEDs();
        } else if (current_key == 'B') {
            for (int i = 0; i < LED_COUNT; i++) {
                npSetLED(i, 0, 0, 255);
            }
            npWrite();
        } else if (current_key == 'C') {
            for (int i = 0; i < LED_COUNT; i++) {
                npSetLED(i, 255, 0, 0);
            }
            npWrite();
        } else if (current_key == 'D') {
            for (int i = 0; i < LED_COUNT; i++) {
                npSetLED(i, 0, 255, 0);
            }
            npWrite();
        } else if (current_key == '#') {
            for (int i = 0; i < LED_COUNT; i++) {
                npSetLED(i, 255, 255, 255);
            }
            npWrite();
        }
        sleep_ms(50); // Reduz o tempo de espera para melhor responsividade
    }

    return 0;
} 