#include "globals.h"
#include <unistd.h>

void buzzer_tone(uint frequency, uint duration_ms) {
    uint period_us = 1000000 / frequency; // Período em microssegundos
    uint cycles = (duration_ms * 1000) / period_us;

    for (uint i = 0; i < cycles; i++) {
        gpio_put(BUZZER_PIN, 1); // Ativa o buzzer
        sleep_us(period_us / 2); // Metade do período
        gpio_put(BUZZER_PIN, 0); // Desativa o buzzer
        sleep_us(period_us / 2); // Metade do período
    }
}

void animacao_ondas(uint8_t r, uint8_t g, uint8_t b) {
    // Animação: Ondas ascendentes (cor inicial)
    for (int frame = 0; frame < 5; frame++) {
        npClear();
        for (int row = 0; row <= frame; row++) {
            for (int col = 0; col < 5; col++) {
                int index = row * 5 + col;
                npSetLED(index, r, g, b);
            }
        }
        npWrite();
        buzzer_tone(1000, 50); // Buzzer curto para cada frame
        sleep_ms(200);
    }

    // Alterar para nova cor para descida
    uint8_t new_r = g;
    uint8_t new_g = b;
    uint8_t new_b = r;

    // Animação: Ondas descendentes (nova cor)
    for (int frame = 4; frame >= 0; frame--) {
        npClear();
        for (int row = 0; row <= frame; row++) {
            for (int col = 0; col < 5; col++) {
                int index = row * 5 + col;
                npSetLED(index, new_r, new_g, new_b);
            }
        }
        npWrite();
        buzzer_tone(800, 50); // Buzzer com tom diferente para descida
        sleep_ms(200);
    }

    // Animação: Ondas horizontais (esquerda para a direita)
    for (int col = 0; col < 5; col++) {
        npClear();
        for (int row = 0; row < 5; row++) {
            int index = row * 5 + col;
            npSetLED(index, r, g, b);
        }
        npWrite();
        buzzer_tone(1200, 50); // Som de frequência maior para este movimento
        sleep_ms(200);
    }

    // Alterar para nova cor para onda reversa
    new_r = b;
    new_g = r;
    new_b = g;

    // Animação: Ondas horizontais (direita para a esquerda)
    for (int col = 4; col >= 0; col--) {
        npClear();
        for (int row = 0; row < 5; row++) {
            int index = row * 5 + col;
            npSetLED(index, new_r, new_g, new_b);
        }
        npWrite();
        buzzer_tone(1500, 50); // Frequência maior ainda
        sleep_ms(200);
    }

    // Animação final: Cobrinhas e X vermelho
    for (int step = 0; step < 5; step++) {
        npClear();
        int index1 = step * 5 + step;
        int index2 = step * 5 + (4 - step);
        npSetLED(index1, 255, 0, 0);
        npSetLED(index2, 255, 0, 0);

        npWrite();
        buzzer_tone(2000, 50); // Som gradualmente mais agudo
        sleep_ms(200);
    }

    // Mostrar o X completo no final
    npClear();
    for (int i = 0; i < 5; i++) {
        int index1 = i * 5 + i; // Diagonal principal
        int index2 = i * 5 + (4 - i); // Diagonal secundária
        npSetLED(index1, 255, 0, 0);
        npSetLED(index2, 255, 0, 0);
    }
    npWrite();
    buzzer_tone(2500, 1000); // Longa nota para o final
    sleep_ms(1000);

    // Apaga os LEDs ao final da animação
    npClear();
    npWrite();
}
