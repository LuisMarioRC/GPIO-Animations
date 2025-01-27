#include "globals.h"
#include <unistd.h>

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
        sleep_ms(200);
    }

    // Alterar para nova cor para descida
    uint8_t new_r = g;  // Nova cor para descida
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
        sleep_ms(200);
    }

    // Animação: Ondas horizontais da esquerda para a direita (cor inicial)
    for (int col = 0; col < 5; col++) {
        npClear();
        for (int row = 0; row < 5; row++) {
            int index = row * 5 + col;
            npSetLED(index, r, g, b);
        }
        npWrite();
        sleep_ms(200);
    }

    // Alterar para nova cor para a onda reversa
    new_r = b;  // Nova cor para reversa
    new_g = r;
    new_b = g;

    // Animação: Ondas horizontais da direita para a esquerda (nova cor)
    for (int col = 4; col >= 0; col--) {
        npClear();
        for (int row = 0; row < 5; row++) {
            int index = row * 5 + col;
            npSetLED(index, new_r, new_g, new_b);
        }
        npWrite();
        sleep_ms(200);
    }

    // Animação: Ondas diagonais (cor inicial)
    for (int frame = 0; frame < 5; frame++) {
        npClear();
        for (int i = 0; i <= frame; i++) {
            int index = i * 5 + i; // Elementos da diagonal principal
            npSetLED(index, r, g, b);
        }
        npWrite();
        sleep_ms(200);
    }

    // Alterar para nova cor para descida diagonal
    new_r = g;
    new_g = b;
    new_b = r;

    for (int frame = 4; frame >= 0; frame--) {
        npClear();
        for (int i = 0; i <= frame; i++) {
            int index = i * 5 + i;
            npSetLED(index, new_r, new_g, new_b);
        }
        npWrite();
        sleep_ms(200);
    }

    // Animação final: Cobrinhas saindo das pontas e formando um X vermelho
    for (int step = 0; step < 5; step++) {
        npClear();
        // Cobra 1 (de cima-esquerda para baixo-direita)
        int index1 = step * 5 + step;
        npSetLED(index1, 255, 0, 0); // Vermelho

        // Cobra 2 (de cima-direita para baixo-esquerda)
        int index2 = step * 5 + (4 - step);
        npSetLED(index2, 255, 0, 0); // Vermelho

        npWrite();
        sleep_ms(400);
    }

    // Mostrar o X completo no final
    npClear();
    for (int i = 0; i < 5; i++) {
        int index1 = i * 5 + i; // Diagonal principal
        int index2 = i * 5 + (4 - i); // Diagonal secundária
        npSetLED(index1, 255, 0, 0); // Vermelho
        npSetLED(index2, 255, 0, 0); // Vermelho
    }
    npWrite();
    sleep_ms(1000);

    // Apaga os LEDs ao final da animação
    npClear();
    npWrite();
}
