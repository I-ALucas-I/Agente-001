#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/keyboard.h>
#include <allegro5/mouse.h>
#include <allegro5/allegro_image.h>
#include "Player.h"
#include "Enemie.h"
#include "Background.h"
#include "Collision.h"

#include <stdio.h>
#include <direct.h>

int main() {

    //Iniciando bibliotecas do allegro

    al_init();
    al_install_keyboard();
    al_init_primitives_addon();
    al_install_mouse();
    al_init_image_addon();

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

    //Criando timer

    ALLEGRO_TIMER* timer;
    timer = al_create_timer(1.0 / 30.0);

    ALLEGRO_BITMAP* bitmap = al_load_bitmap("agente_001_blocos.png");

    char caminho[1024];

    if (_getcwd(caminho, sizeof(caminho)) != NULL) {
        printf("Diretorio atual: %s\n", caminho);
    }

    //Verifica se a janela, a fila de eventos e o timer foi criada, se passar começa o código principal

    if (window == NULL || eventQueue == NULL || timer == NULL || bitmap == NULL) {
        return -1;
    }
    else {

        //Assoiciando fila de eventos a tipos de evento

        al_register_event_source(eventQueue, al_get_display_event_source(window));
        al_register_event_source(eventQueue, al_get_timer_event_source(timer));
        al_register_event_source(eventQueue, al_get_keyboard_event_source());
        al_register_event_source(eventQueue, al_get_mouse_event_source());

        //ligando timer

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
        //

        //Criando plataforma de nascimento dos robôs 1x3 || 1-1 | 1-2 | 1-3 ||

        Platform nascimento;
        nascimento.tipo = 4;
        Platform* nascimentoP = &nascimento;

        Platform plataforma;
        plataforma.tipo = 0;
        Platform* plataformaP = &plataforma;

        Platform plataforma1;
        plataforma1.tipo = 1;
        Platform* plataforma1P = &plataforma1;

        Platform plataforma2;
        plataforma2.tipo = 0;
        Platform* plataforma2P = &plataforma2;

        Platform plataforma4;
        plataforma4.tipo = 0;
        Platform* plataforma4P = &plataforma4;

        Platform plataforma5;
        plataforma5.tipo = 0;
        Platform* plataforma5P = &plataforma5;

        Platform plataforma3;
        plataforma3.tipo = 0;
        Platform* plataforma3P = &plataforma3;

        nascimento = platform(lT, aT, 16, 17, 1, 1, nascimentoP, bitmap);

        plataforma = platform(lT, aT, 1, 18, 30, 3, plataformaP, bitmap);

        plataforma1 = platform(lT, aT, 1, 1, 30, 17, plataforma1P, bitmap);

        plataforma2 = platform(lT, aT, 11, 14, 5, 4, plataforma2P, bitmap);

        plataforma4 = platform(lT, aT, 21, 10, 5, 8, plataforma4P, bitmap);

        plataforma5 = platform(lT, aT, 21, 9, 4, 1, plataforma5P, bitmap);

        plataforma3 = platform(lT, aT, 19, 12, 5, 6, plataforma3P, bitmap);

        //Iniciando array do jogador

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
                jogador[i].x = nascimento.x + (nascimento.largura / 6 * 2);

                jogador[i].y = nascimento.y - (jogador[0].altura * 2);
            }
            if (i == quantosPlayers - 1) {
                jogador[i].active = true;
            }
        }

        //Ponteiro para saber corpo ativo do player

        int playerAtual = 0;
        int* pa = &playerAtual;

        //Iniciando inimigo

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
        

        //Ponteiro para chamar inimigo nas functions

        Enemie* e = &inimigo;

        //Ponteiro para mudanças do tiro para poc

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

        //Iniciando array de tiros

        Shot leftShots[5];
        int leftShotQuantos = 5;

        for (int i = 0; i < leftShotQuantos; i++) {

            leftShots[i].leftActive = false;
            leftShots[i].leftUsed = false;
        }

        Shot rightShots[5];
        int rightShotQuantos = 5;

        for (int i = 0; i < rightShotQuantos; i++) {

            rightShots[i].rightActive = false;
            rightShots[i].rightUsed = false;
        }

        //Ponteiro para tiros nas functions

        Shot* left_s = &leftShots[0];
        Shot* right_s = &rightShots[0];

        //Põe o muse no meio da tela

        al_set_mouse_xy(window, mouse.mouseX, mouse.mouseY);

        //looping de jogo principal

        while (windowOn == true) {

            //Limpando janela para cor do fundo

            al_clear_to_color(fundo);
            
            //Fazendo fila de eventos

            al_wait_for_event(eventQueue, &event);

            //Chamando funtion de background/grid
            
            background(lT, aT);

            //Criando variáveis de plataforma e ponteiro para usar em functions

            /*Platform plataforma;
            plataforma.tipo = 0;
            Platform* plataformaP = &plataforma;

            Platform plataforma1;
            plataforma1.tipo = 1;
            Platform* plataforma1P = &plataforma1;

            Platform plataforma2;
            plataforma2.tipo = 2;
            Platform* plataforma2P = &plataforma2;

            Platform plataforma4;
            plataforma4.tipo = 3;
            Platform* plataforma4P = &plataforma4;

            Platform plataforma5;
            plataforma5.tipo = 3;
            Platform* plataforma5P = &plataforma5;

            Platform plataforma3;
            plataforma3.tipo = 2;
            Platform* plataforma3P = &plataforma3;*/

            //Criando cenário com plataformas

            /*plataforma = platform(lT, aT, 1, 18, 30, 3, plataformaP, bitmap);

            plataforma1 = platform(lT, aT, 1, 1, 30, 17, plataforma1P, bitmap);

            plataforma2 = platform(lT, aT, 11, 14, 5, 4, plataforma2P, bitmap);

            plataforma4 = platform(lT, aT, 21, 10, 5, 8, plataforma4P, bitmap);

            plataforma5 = platform(lT, aT, 21, 9, 4, 1, plataforma5P, bitmap);

            plataforma3 = platform(lT, aT, 19, 12, 5, 6, plataforma3P, bitmap);*/

            //Criando váriaveis para controle do sistema de vida

            int playerAnterior = playerAtual;

            playerSystem(jogador, quantosPlayers, pa, event);

            Player* p = &jogador[playerAtual];

            //Chamando function playerMove, gun e shots

            playerMove(p, event);
            gun(m, left_s, leftShotQuantos, right_s, rightShotQuantos, p, event);
            shot(left_s, leftShotQuantos, right_s, rightShotQuantos, event);

            //Atualizando colisão quando o timer atualiza

            if (event.type == ALLEGRO_EVENT_TIMER) {

                p->standing = false;

                plataformCollision(p, left_s, leftShotQuantos, right_s, rightShotQuantos, plataformaP);
                plataformCollision(p, left_s, leftShotQuantos, right_s, rightShotQuantos, plataforma1P);
                plataformCollision(p, left_s, leftShotQuantos, right_s, rightShotQuantos, plataforma2P);
                plataformCollision(p, left_s, leftShotQuantos, right_s, rightShotQuantos, plataforma3P);
                plataformCollision(p, left_s, leftShotQuantos, right_s, rightShotQuantos, plataforma4P);
                plataformCollision(p, left_s, leftShotQuantos, right_s, rightShotQuantos, plataforma5P);
                plataformCollision(p, left_s, leftShotQuantos, right_s, rightShotQuantos, nascimentoP);
                enemieCollision(jogador, quantosPlayers, left_s, leftShotQuantos, right_s, rightShotQuantos, pa, e, mu);
                //enemieShotCollision(s, quantos, e, mu);
            }

            //Criando robôs do player na plataforma de nascimento

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

            platformDraw(plataformaP, 30, 3);
            platformDraw(plataforma1P, 0, 0);
            platformDraw(plataforma2P, 5, 5);
            platformDraw(plataforma4P, 5, 9);
            platformDraw(plataforma5P, 4, 2);
            platformDraw(plataforma3P, 5, 7);
            platformDraw(nascimentoP, 0, 0);
            
            //Chamando function playerDraw, gunDraw e enemieDraw

            playerDraw(jogador, quantosPlayers);
            gunDraw(m, left_s, leftShotQuantos, right_s, rightShotQuantos, p);
            enemieDraw(e);

            //Comando temporário para resetar tiros

            if (event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode == ALLEGRO_KEY_R) {

                for (int i = 0; i < leftShotQuantos; i++) {

                    leftShots[i].leftActive = false;
                    leftShots[i].leftUsed = false;
                }

                for (int i = 0; i < rightShotQuantos; i++) {

                    rightShots[i].rightActive = false;
                    rightShots[i].rightUsed = false;
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
        al_destroy_bitmap(bitmap);

        return 0;
    }
}
