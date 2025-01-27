#include "globals.h"
#include <unistd.h>
#include <stdlib.h>  // Para utilizar a função rand()

void animacao_v() {
       // Definindo as cores que serão alternadas (vermelho, verde e azul)
    uint8_t cores[3][3] = {
        {255, 0, 0},   // Vermelho
        {0, 255, 0},   // Verde
        {0, 0, 255}    // Azul
    };

    // Matriz de LEDs com valores iniciais fornecidos
    uint32_t tabuleiro[5][5] = {
        {0xff0000ff, 0x00000000, 0xff0000ff, 0x00000000, 0xff0000ff},
        {0x00000000, 0x00000000, 0x00000000, 0xff0000ff, 0x00000000},
        {0xff0000ff, 0xff0000ff, 0xff0000ff, 0xff0000ff, 0xff0000ff},
        {0x00000000, 0x00000000, 0xff0000ff, 0x00000000, 0x00000000},
        {0xff0000ff, 0x00000000, 0xff0000ff, 0x00000000, 0xff0000ff}
    };

    // Função para obter a cor em formato RGB de um valor hexadecimal
    void getRGB(uint32_t cor, uint8_t *r, uint8_t *g, uint8_t *b) {
        *r = (cor >> 16) & 0xFF;
        *g = (cor >> 8) & 0xFF;
        *b = cor & 0xFF;
    }

    // Animação: Expande a partir do centro
    for (int expandir = 0; expandir < 3; expandir++) {
        npClear();

        // Atualiza os LEDs com a expansão e alternância de cores
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                // Verifica a distância do centro
                int dist = abs(i - 2) + abs(j - 2);
                if (dist <= expandir) {
                    // Alterna entre as cores verde, vermelho e azul
                    uint8_t r_atual = cores[expandir % 3][0];
                    uint8_t g_atual = cores[expandir % 3][1];
                    uint8_t b_atual = cores[expandir % 3][2];
                    
                    // Define a cor para o LED correspondente
                    npSetLED(i * 5 + j, r_atual, g_atual, b_atual);
                }
            }
        }

        npWrite();
        sleep_ms(300);  // Tempo de pausa entre as atualizações do tabuleiro
    }

    // Pisca todos os LEDs acesos
    for (int blink = 0; blink < 4; blink++) {
        npClear();
        
        // Acende todos os LEDs com a última cor alternada
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                uint8_t r_atual = cores[2][0];
                uint8_t g_atual = cores[2][1];
                uint8_t b_atual = cores[2][2];
                npSetLED(i * 5 + j, r_atual, g_atual, b_atual);
            }
        }

        npWrite();
        sleep_ms(300);  // Tempo de piscar
        npClear();
        npWrite();
        sleep_ms(300);  // Tempo de apagamento
    }

}
