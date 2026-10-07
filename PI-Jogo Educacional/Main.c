#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/keyboard.h>
#include <allegro5/mouse.h>
#include "Player.h"
#include "Enemie.h"
#include "Background.h"
#include "Collision.h"

int main() {

    //Iniciando bibliotecas do allegro

    al_init();
    al_install_keyboard();
    al_init_primitives_addon();
    al_install_mouse();

    //Criando janela do jogo

    al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE /* | ALLEGRO_MAXIMIZED */ );

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

    ALLEGRO_TIMER* timer;
    timer = al_create_timer(1.0 / 30.0);

    //Verifica se a janela e a fila de eventos foi criada, se passar começa o código principal

    if (window == NULL || eventQueue == NULL || timer == NULL) {
        return -1;
    }
    else {

        //Assoiciando fila de eventos a tipos de evento

        al_register_event_source(eventQueue, al_get_display_event_source(window));
        al_register_event_source(eventQueue, al_get_timer_event_source(timer));
        al_register_event_source(eventQueue, al_get_keyboard_event_source());
        al_register_event_source(eventQueue, al_get_mouse_event_source());

        al_start_timer(timer);

        //Liga o looping do jogo

        bool windowOn = true;

        //Cor do fundo

        ALLEGRO_COLOR fundo;
        fundo = al_map_rgb(0, 0, 0);

        //Criando evento

        ALLEGRO_EVENT event;

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

        Platform nascimento;
        nascimento.tipo = 4;
        Platform* nascimentoP = &nascimento;

        nascimento = platform(lT, aT, 16, 17, 1, 1, nascimentoP);

        //Iniciando váriavel do jogador

        Player jogador[3];
        int quantosPlayers = 3;
        //                          coordenada na grid
        // 
        //                                   |
        //                                   V
        //
        /*jogador.x = ((larguraTela/90) * 3) * 3 - ((larguraTela / 90) * 3);
        jogador.y = ((alturaTela / 60) * 3) * 16 - ((alturaTela / 60) * 3);
        jogador.largura = (larguraTela / 90) * 3;
        jogador.altura = (alturaTela / 60) * 3;
        jogador.velocidade = 6;
        jogador.velY = 0;
        jogador.standing = true;
        jogador.keyboard.a_pressed = false;
        jogador.keyboard.d_pressed = false;
        jogador.keyboard.w_pressed = false;*/

        for (int i = 0; i < quantosPlayers; i++) {
            jogador[i].x = ((larguraTela / 90) * 3) * 3 - ((larguraTela / 90) * 3);
            jogador[i].y = ((alturaTela / 60) * 3) * 16 - ((alturaTela / 60) * 3);
            jogador[i].largura = (larguraTela / 90) * 3;
            jogador[i].altura = (alturaTela / 60) * 3;
            jogador[i].velocidade = 6;
            jogador[i].velY = 0;
            jogador[i].standing = true;
            jogador[i].active = false;
            jogador[i].inUse = false;
            jogador[i].used = false;
            jogador[i].keyboard.a_pressed = false;
            jogador[i].keyboard.d_pressed = false;
            jogador[i].keyboard.w_pressed = false;

            if (i == 0) {
                jogador[i].active = true;
                jogador[i].inUse = true;
                jogador[0].x = nascimento.x + (nascimento.largura / 6 * 2);

                jogador[0].y = nascimento.y - jogador[0].altura * 2;
            }
            if (i == quantosPlayers - 1) {
                jogador[i].active = true;
            }
        }

        //Ponteiro para chamar jogador nas functions

        int playerAtual = 0;
        int* pa = &playerAtual;

      

        Enemie inimigo;
        //                          coordenada na grid
        // 
        //                                   |
        //                                   V
        //
        inimigo.x = ((larguraTela / 90) * 3) * 7 - ((larguraTela / 90) * 3);
        inimigo.y = ((alturaTela / 60) * 3) * 17 - ((alturaTela / 60) * 3);
        inimigo.largura = (larguraTela / 90) * 3;
        inimigo.altura = (alturaTela / 60) * 3;
        

        //Ponteiro para chamar jogador nas functions

        Enemie* e = &inimigo;

        int mudar = 0;
        int* mu = &mudar;
        //Iniciando váriavel do mouse

        Mouse mouse;

        mouse.mouseX = larguraTela / 2;
        mouse.mouseY = alturaTela / 2;
        mouse.mouse.b_left = false;
        mouse.mouse.b_right = false;

        //Ponteiro para chamar mouse nas functions

        Mouse* m = &mouse;

        Shot shots[5];
        int quantos = 5;

        for (int i = 0; i < quantos; i++) {

            shots[i].active = false;
            shots[i].used = false;
        }

        Shot* s = &shots[0];

        al_set_mouse_xy(window, mouse.mouseX, mouse.mouseY);

        //looping de jogo principal

        while (windowOn == true) {

            //Limpando janela para cor do fundo

            al_clear_to_color(fundo);
            
            //Fazendo fila de eventos

            al_wait_for_event(eventQueue, &event);

            //Chamando funtion de background/grid
            
            background(lT, aT);

            //Criando variavel de plataforma e ponteiro para usar em functions

            Platform plataforma;
            plataforma.tipo = 0;
            Platform* plataformaP = &plataforma;

            //Criando cenário com plataformas

            plataforma = platform(lT, aT, 1, 18, 30, 3, plataformaP);

            Platform plataforma1;
            plataforma1.tipo = 1;
            Platform* plataforma1P = &plataforma1;

            plataforma1 = platform(lT, aT, 1, 1, 30, 17, plataforma1P);

            Platform plataforma2;
            plataforma2.tipo = 2;
            Platform* plataforma2P = &plataforma2;

            plataforma2 = platform(lT, aT, 11, 14, 5, 4, plataforma2P);

            Platform plataforma4;
            plataforma4.tipo = 3;
            Platform* plataforma4P = &plataforma4;

            plataforma4 = platform(lT, aT, 21, 10, 5, 8, plataforma4P);

            Platform plataforma5;
            plataforma5.tipo = 3;
            Platform* plataforma5P = &plataforma5;

            plataforma5 = platform(lT, aT, 21, 9, 4, 1, plataforma5P);

            Platform plataforma3;
            plataforma3.tipo = 2;
            Platform* plataforma3P = &plataforma3;

            plataforma3 = platform(lT, aT, 19, 12, 5, 6, plataforma3P);

            

            //Chamando function playerMove e gun

            int playerAnterior = playerAtual;

            playerSystem(jogador, quantosPlayers, pa, event);

            Player* p = &jogador[playerAtual];

            playerMove(p, event);
            gun(m, s, quantos, p, event);
            shot(s, quantos, event);

            //Atualizando colisão quando o timer atualiza

            if (event.type == ALLEGRO_EVENT_TIMER) {

                p->standing = false;

                plataformCollision(p, plataformaP);
                plataformCollision(p, plataforma1P);
                plataformCollision(p, plataforma2P);
                plataformCollision(p, plataforma3P);
                plataformCollision(p, plataforma4P);
                plataformCollision(p, plataforma5P);
                plataformCollision(p, nascimentoP);
                enemieCollision(jogador, 3, s, quantos, pa, e, mu);
                //enemieShotCollision(s, quantos, e, mu);
            }

            if (playerAnterior != playerAtual) {

                p = &jogador[playerAtual];

                if (playerAtual != quantosPlayers - 1) {

                    p->x = nascimento.x
                        + nascimento.largura / 2
                        - p->largura / 2;

                    p->y = nascimento.y
                        - p->altura * 2;
                }
                
            }

            //Desenhando plataformas

            platformDraw(plataformaP);
            platformDraw(plataforma1P);
            platformDraw(plataforma2P);
            platformDraw(plataforma4P);
            platformDraw(plataforma5P);
            platformDraw(plataforma3P);
            platformDraw(nascimentoP);
            
            //Chamando function playerDraw e gunDraw

            playerDraw(jogador, quantosPlayers);
            gunDraw(m, s, quantos, p);
            enemieDraw(e);

            if (event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode == ALLEGRO_KEY_R) {

                for (int i = 0; i < quantos; i++) {

                    shots[i].active = false;
                    shots[i].used = false;
                }
            }

            //Para fechar janela do allegro com ESC ou no 'X' da janela

            if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE || (event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)) {
                windowOn = 0;
            }

            //Trocando tela para fazer animação

            al_flip_display();
        }

        //Destruindo criações do allegro

        al_destroy_timer(timer);
        al_destroy_display(window);
        al_destroy_event_queue(eventQueue);

        return 0;
    }
}
