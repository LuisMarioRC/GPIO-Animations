#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "pico/bootrom.h"


// Biblioteca gerada pelo arquivo .pio durante a compilação.
#include "ws2818b.pio.h"


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


// MACROS
#define LED_COUNT 25
#define LED_PIN 7


// Mapeamento do teclado matricial
const char key_map[4][4] = {
 {'1', '2', '3', 'A'},
 {'4', '5', '6', 'B'},
 {'7', '8', '9', 'C'},
 {'*', '0', '#', 'D'}
};


PIO np_pio;
uint sm;
struct pixel_t {
 uint8_t G, R, B;
};
typedef struct pixel_t npLED_t;
npLED_t leds[LED_COUNT];


// Inicialização do teclado matricial
void init_keypad() {
 // Configurar linhas como saída
 gpio_init(LINE1); gpio_set_dir(LINE1, GPIO_OUT);
 gpio_init(LINE2); gpio_set_dir(LINE2, GPIO_OUT);
 gpio_init(LINE3); gpio_set_dir(LINE3, GPIO_OUT);
 gpio_init(LINE4); gpio_set_dir(LINE4, GPIO_OUT);


 // Configurar colunas como entrada com pull-down
 gpio_init(COL1); gpio_set_dir(COL1, GPIO_IN); gpio_pull_down(COL1);
 gpio_init(COL2); gpio_set_dir(COL2, GPIO_IN); gpio_pull_down(COL2);
 gpio_init(COL3); gpio_set_dir(COL3, GPIO_IN); gpio_pull_down(COL3);
 gpio_init(COL4); gpio_set_dir(COL4, GPIO_IN); gpio_pull_down(COL4);
}


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


// Controle de LEDs
void control_devices(char key) {
 switch (key) {
   case '1':


     break;
   case '2':


     break;
   case '3':


     break;
   case '4':
     for (int frame = 0; frame < 5; frame++) {
       clear_leds();
       for (int i = 0; i < LED_COUNT; i++) {
         int intensity = (i + frame) % 5 == 0 ? 255 : 0;
         set_led(i, intensity, intensity / 2, intensity / 3); // Tons de roxo
       }
       write_leds(); // Atualiza os LEDs
       sleep_ms(250);
     }
     clear_leds();
     write_leds(); // Garante que os LEDs sejam apagados ao final
     break;
   case '5':


     break;
   default:
     break;
 }
}


// Inicialização do buzzer
void init_buzzer() {
 gpio_init(BUZZER_PIN);
 gpio_set_dir(BUZZER_PIN, GPIO_OUT);
 gpio_put(BUZZER_PIN, 0); // Inicialmente desligado
}


void init_leds(void) {
 uint offset = pio_add_program(pio0, &ws2818b_program);
 np_pio = pio0;
 sm = pio_claim_unused_sm(np_pio, true);
 ws2818b_program_init(np_pio, sm, offset, LED_PIN, 800000.f);
 for (int i = 0; i < LED_COUNT; i++) {
   leds[i].R = leds[i].G = leds[i].B = 0;
 }
}


void set_led(int index, uint8_t r, uint8_t g, uint8_t b) {
 if (index < LED_COUNT) {
   leds[index].R = r;
   leds[index].G = g;
   leds[index].B = b;
 }
}


void clear_leds(void) {
 for (int i = 0; i < LED_COUNT; i++) {
   set_led(i, 0, 0, 0);
 }
}


void write_leds(void) {
 for (int i = 0; i < LED_COUNT; i++) {
   pio_sm_put_blocking(np_pio, sm, leds[i].G);
   pio_sm_put_blocking(np_pio, sm, leds[i].R);
   pio_sm_put_blocking(np_pio, sm, leds[i].B);
 }
}


// Função principal
int main() {
 stdio_init_all(); // Inicializa entrada/saída padrão
 init_keypad();    // Inicializa o teclado matricial
 init_buzzer();    // Inicializa o buzzer


 // Inicializa os LEDs
 init_leds();
 clear_leds();
 write_leds();


 char last_key = '\0'; // Armazena a última tecla pressionada


 while (true) {
   char key = read_keypad(); // Lê a tecla pressionada
   printf("Tecla pressionada: %c\n", key);
   control_devices(key); // Controla LEDs
   sleep_ms(100); // Delay para evitar múltiplas leituras
 }


 return 0;
}


