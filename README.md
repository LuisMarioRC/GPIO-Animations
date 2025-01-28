# CEPEDI

## Grupo 7 Subgrupo 8

# Animações em Matriz de LEDs 5x5 com Teclado Matricial - RP2040

## Tarefa 1 - Geração de Animações em Matriz de LEDs

### Descrição

Este repositório contém o código-fonte de um projeto desenvolvido em Linguagem C, utilizando o Pico SDK, para controlar uma matriz de LEDs 5x5 (WS2812) por meio de um teclado matricial 4x4 conectado a um microcontrolador Raspberry Pi Pico W. A aplicação é simulada no Wokwi e possui funcionalidades como animações de LEDs e controles específicos baseados em teclas.

A solução implementa estratégias para:

1. Geração de diferentes animações na matriz de LEDs.
2. Controle de cores e intensidade dos LEDs.
3. Interação com um teclado matricial 4x4.
4. (Opcional) Emissão de sinal sonoro com um buzzer.
5. (Opcional) Entrada no modo de gravação via software.

## Funcionalidades

1. **Animações na Matriz de LEDs**:
   - Teclas 0 a 9: Geração de até 10 animações diferentes (mínimo de 5 frames cada).
   - Frames e FPS configuráveis pela equipe.

2. **Configurações Específicas**:
   - Tecla A: Desligar todos os LEDs.
   - Tecla B: Ligar todos os LEDs na cor azul (100% de luminosidade).
   - Tecla C: Ligar todos os LEDs na cor vermelha (80% de luminosidade).
   - Tecla D: Ligar todos os LEDs na cor verde (50% de luminosidade).
   - Tecla #: Ligar todos os LEDs na cor branca (20% de luminosidade).

3. **Especificações Opcionais**:
   - Emissão de som por buzzer para uma animação específica.
   - Tecla *: Reinicialização e entrada no modo de gravação.

## Pré-requisitos

1. Ambiente de Desenvolvimento VS Code.
2. Pico SDK instalado.
3. Simulador Wokwi configurado.
4. Compilador de C, como GCC.

## Como Usar

1. Clone o repositório:

    ```bash
    git clone https://github.com/LuisMarioRC/GPIO-Animations.git
    ```

2. Navegue até o diretório do projeto:

    ```bash
    cd GPIO-Animations
    ```

3. Compile o código com o compilador de C:

    ```bash
    gcc neopixel_pio.c -o main
    ```

4. Execute o programa:

    ```bash
    ./main
    ```

## Equipe

A equipe foi formada por membros com as seguintes responsabilidades:

### Líder do Projeto

- <b><a href="https://github.com/LuisMarioRC">Luis Mario</a></b> – Gerenciamento do repositório, revisão de código, integração, documentação e criação de animação.

### Desenvolvedores

- <b><a href="https://github.com/LeonardoGermano">Leonardo</a></b> – Geração de animações e configuração de teclas A, B, C, D e #.
- <b><a href="https://github.com/icarosg">Ícaro Gonçalves</a></b> – Geração de animações.
- <b><a href="https://github.com/vinicius-bash">Vinícius José</a></b> – Geração de animações.

## Vídeo

Acesse o vídeo ensaio da solução no link: [Link do vídeo](o link http aqui!).
