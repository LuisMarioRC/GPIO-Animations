#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"

// Definições dos pinos do teclado matricial
#define LINE1 14
#define LINE2 15
#define LINE3 16
#define LINE4 17
#define COL1 18
#define COL2 19
#define COL3 20
#define COL4 21

// Definição do pino do buzzer
#define BUZZER_PIN 22

// Mapeamento do teclado matricial
const char key_map[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

// Leitura da tecla pressionada no teclado matricial
char read_keypad() {
    for (int row = 0; row < 4; row++) {
        gpio_put(LINE1, row == 0);
        gpio_put(LINE2, row == 1);
        gpio_put(LINE3, row == 2);
        gpio_put(LINE4, row == 3);

        for (int col = 0; col < 4; col++) {
            if (gpio_get(COL1 + col)) {
                return key_map[row][col];
            }
        }
    }
    return '\0'; // Nenhuma tecla pressionada
}

// controle de animações
void control_devices(char key) {
    switch (key) {
        case 'A':
            // Colocar a animação
        default:
            break;
    }
}

int main()
{
    stdio_init_all();

    while (true) {
        char key = read_keypad(); // Lê a tecla pressionada
        printf("Tecla pressionada: %c\n", key); 
        control_devices(key); // Controla a animação do teclado
        sleep_ms(100); // Delay para evitar múltiplas leituras
    }
}
