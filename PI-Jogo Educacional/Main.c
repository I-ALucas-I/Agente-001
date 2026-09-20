#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/keyboard.h>
#include <allegro5/mouse.h>
#include "Player.h"
#include "Background.h"

int main() {

    //Iniciando bibliotecas do allegro

    al_init();
    al_install_keyboard();
    al_init_primitives_addon();
    al_install_mouse();

    //Criando janela do jogo

    al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);

    ALLEGRO_DISPLAY* window;
    
    int larguraTela = 1080;
    int alturaTela = 720;
    
    window = al_create_display(larguraTela, alturaTela);

    //Ponteiros para chamar váriaveis nas functions

    int* lT = &larguraTela;
    int* aT = &alturaTela;

    //Nome da janela

    al_set_window_title(window, "Agente 001");

    //Criando fila de eventos

    ALLEGRO_EVENT_QUEUE* eventQueue;
    eventQueue = al_create_event_queue();

    //al_set_new_display_refresh_rate(30);

    //Verifica se a janela e a fila de eventos foi criada, se passar começa o código principal

    if (window == NULL || eventQueue == NULL) {
        return -1;
    }
    else {

        //Assoiciando fila de eventos a tipos de evento

        al_register_event_source(eventQueue, al_get_display_event_source(window));
        al_register_event_source(eventQueue, al_get_keyboard_event_source());
        al_register_event_source(eventQueue, al_get_mouse_event_source());

        //Liga o looping do jogo

        bool windowOn = true;

        //Cor do fundo

        ALLEGRO_COLOR fundo;
        fundo = al_map_rgb(0, 0, 0);

        //
        // Player, inimigos e "blocos" serão posicionados pela grid
        // 
        //--------------------------------------------------//
        //                                                  //
        //          Grid 15x10: 30 -> x e 20 -> y           //
        //                                                  //
        //          /--------------------------             //
        //          | 1-1 | 2-1 |                           //
        //          |-----|-----|                           //
        //          | 1-2 | 2-2 |                           //
        //          |-----|-----|                           //
        //                                                  //
        //--------------------------------------------------//

        //Iniciando váriavel do jogador

        Player jogador;
        //                          coordenada na grid
        // 
        //                                   |
        //                                   V
        //
        jogador.x = ((larguraTela/90) * 3) * 1 - ((larguraTela / 90) * 3);
        jogador.y = ((alturaTela / 60) * 3) * 16 - ((alturaTela / 60) * 3);
        jogador.velocidade = 10;
        jogador.standing = true;
        jogador.keyboard.a_pressed = 0;
        jogador.keyboard.d_pressed = 0;
        jogador.keyboard.w_pressed = 0;

        //Ponteiro para chamar jogador nas functions

        Player* p = &jogador;

        int mouseX, mouseY;

        //looping de jogo principal

        while (windowOn == true) {
        
            //Completando jogador

            jogador.x2 = jogador.x + (larguraTela / 90) * 3;
            jogador.y2 = jogador.y + (alturaTela / 60) * 3 *2;

            //Limpando janela para cor do fundo

            al_clear_to_color(fundo);
            
            //Criando evento

            ALLEGRO_EVENT event;
            
            //Fazendo fila de eventos

            al_wait_for_event(eventQueue, &event);
            
            //Chamando funtion de background/ grid
            
            background(lT, aT);

            //Criando variavel de plataforma e ponteiro para usar em functions

            Platform plataforma1;
            Platform* plataforma1P = &plataforma1;

            plataforma1P->x = 0;
            plataforma1P->standable = 0;

            //Criando cenário com plataformas

            platform(lT, aT, 1, 18, 30, 3, plataforma1P);

            plataforma1P->x = 1;
            plataforma1P->standable = 1;

            //platform(lT, aT, 1, 1, 30, 17, plataforma1P);

            plataforma1P->x = 2;
            plataforma1P->standable = 0;

            platform(lT, aT, 11, 16, 5, 1, plataforma1P);

            //Chamando function playerMove

            playerMove(p, event);

            mouseX = event.mouse.x;
            mouseY = event.mouse.y;

            //Para fechar janela do allegro com ESC ou no 'X' da janela

            if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE || (event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)) {
                windowOn = 0;
            }

            //Trocando tela para fazer animação

            al_flip_display();
        }

        //Destruindo criações do allegro

        al_destroy_display(window);
        al_destroy_event_queue(eventQueue);
        
        return 0;
    }
}