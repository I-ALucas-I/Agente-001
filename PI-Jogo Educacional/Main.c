#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/keyboard.h>
#include <allegro5/mouse.h>
#include <allegro5/allegro_image.h>

#include "Player.h"
#include "Enemie.h"
#include "Background.h"
#include "Collision.h"
#include "Audio.h"
#include "Starting.h"
#include "Menu.h"

#include <stdio.h>
#include <direct.h>

int main() {

    //Iniciando bibliotecas do allegro

    al_init();
    al_install_keyboard();
    al_init_primitives_addon();
    al_install_mouse();
    al_init_image_addon();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(8);
    carregarAudio();

    Game jogo;
    Game* ponteiroJogo = &jogo;
    //Criando janela do jogo

    al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE /* | ALLEGRO_MAXIMIZED */ );

    jogo.window;
    
    jogo.width = 1080;
    jogo.height = 720;

    jogo.window = al_create_display(jogo.width, jogo.height);

    //Nome da janela

    al_set_window_title(jogo.window, "Agente 001");

    //Criando fila de eventos

    jogo.eventQueue;
    jogo.eventQueue = al_create_event_queue();

    //Criando timer

    jogo.timer;
    jogo.timer = al_create_timer(1.0 / 30.0);

    jogo.bitmapMenu = al_load_bitmap("agente_001_menu.png");
    jogo.bitmapBackground = al_load_bitmap("agente_001_background.png");
    jogo.bitmapBlocos = al_load_bitmap("agente_001_blocos.png");
    jogo.bitmapInimigos = al_load_bitmap("agente_001_inimigos.png");
    jogo.bitmapPlayer = al_load_bitmap("agente_001_player.png");
    jogo.bitmapArmaAgente = al_create_sub_bitmap(jogo.bitmapPlayer, 187, 0, 26, 8);
    jogo.bitmapArmaRobo = al_create_sub_bitmap(jogo.bitmapPlayer, 187, 73, 26, 8);

    //Verifica se a janela, a fila de eventos e o timer foi criada, se passar começa o código principal

    if (jogo.window == NULL) {
        return -31;
    }
    else if (jogo.eventQueue == NULL) return -2;
    else if (jogo.timer == NULL) return -3;
    else if (jogo.bitmapMenu == NULL) - 4;
    else if (jogo.bitmapBlocos == NULL) - 5;
    else if (jogo.bitmapInimigos == NULL) - 6;
    else if (jogo.bitmapPlayer == NULL) - 7;
    else if (jogo.bitmapArmaAgente == NULL) - 8;
    else if (jogo.bitmapArmaRobo == NULL) - 9;
    else {

        //Assoiciando fila de eventos a tipos de evento

        al_register_event_source(jogo.eventQueue, al_get_display_event_source(jogo.window));
        al_register_event_source(jogo.eventQueue, al_get_timer_event_source(jogo.timer));
        al_register_event_source(jogo.eventQueue, al_get_keyboard_event_source());
        al_register_event_source(jogo.eventQueue, al_get_mouse_event_source());

        Mouse mouse;
        
        mouse.mouseX = jogo.width / 2;
        mouse.mouseY = jogo.height / 2;
        mouse.mouse.b_left = false;
        mouse.mouse.b_right = false;
        
        //Ponteiro para chamar mouse nas functions
        
        Mouse* m = &mouse;

        //Põe o mouse no meio da tela
            
        al_set_mouse_xy(jogo.window, mouse.mouseX, mouse.mouseY);
        al_hide_mouse_cursor(jogo.window);

        //ligando timer

        al_start_timer(jogo.timer);

        menuControl(ponteiroJogo, m);

        //bool windowOn = true;

        ////looping de jogo principal

        //while (windowOn == true) {

        //    //Limpando janela para cor do fundo

        //    al_clear_to_color(al_map_rgb(255, 255, 255));
        //    
        //    //Fazendo fila de eventos

        //    al_wait_for_event(jogo.eventQueue, &jogo.event);

        //    //Chamando funtion de background/grid
        //    
        //    background(lT, aT);
        //    
        //    //Criando váriaveis para controle do sistema de vida

        //    int playerAnterior = playerAtual;

        //    playerSystem(jogador, quantosPlayers, pa, event);

        //    Player* p = &jogador[playerAtual];

        //    //Chamando function playerMove, gun e shots

        //    playerMove(p, event);
        //    gun(m, left_s, leftShotQuantos, right_s, rightShotQuantos, p, event);
        //    shot(left_s, leftShotQuantos, right_s, rightShotQuantos, event);

        //    enemieMove(e, event);

        //    //Atualizando colisão quando o timer atualiza

        //    if (event.type == ALLEGRO_EVENT_TIMER) {

        //        p->standing = false;

        //        plataformCollision(p, left_s, leftShotQuantos, right_s, rightShotQuantos, plataformaP);
        //       // plataformCollision(p, left_s, leftShotQuantos, right_s, rightShotQuantos, plataforma1P);
        //        plataformCollision(p, left_s, leftShotQuantos, right_s, rightShotQuantos, plataforma2P);
        //        plataformCollision(p, left_s, leftShotQuantos, right_s, rightShotQuantos, plataforma3P);
        //        plataformCollision(p, left_s, leftShotQuantos, right_s, rightShotQuantos, plataforma4P);
        //        plataformCollision(p, left_s, leftShotQuantos, right_s, rightShotQuantos, nascimentoP);
        //        enemieCollision(jogador, quantosPlayers, left_s, leftShotQuantos, right_s, rightShotQuantos, pa, e);
        //        enemiePlatformCollision(nascimentoP, e);
        //        enemiePlatformCollision(plataformaP, e);
        //        enemiePlatformCollision(plataforma2P, e);
        //        enemiePlatformCollision(plataforma3P, e);
        //    }

        //    //Criando robôs do player na plataforma de nascimento

        //    if (playerAnterior != playerAtual) {

        //        p = &jogador[playerAtual];

        //        if (playerAtual != quantosPlayers - 1) {

        //            p->x = nascimento.x + nascimento.largura / 2 - p->largura / 2;

        //            p->y = nascimento.y - p->altura * 2;
        //        }
        //        
        //    }

        //    //Desenhando plataformas

        //    platformDraw(plataformaP, 30, 3);
        //    //platformDraw(plataforma1P, 0, 0);
        //    platformDraw(plataforma2P, 5, 4);
        //    platformDraw(plataforma4P, 5, 8);
        //    platformDraw(plataforma3P, 5, 7);
        //    platformDraw(nascimentoP, 0, 0);
        //    
        //    //Chamando function playerDraw, gunDraw e enemieDraw

        //    playerDraw(jogador, quantosPlayers);
        //    gunDraw(m, left_s, leftShotQuantos, right_s, rightShotQuantos, p);
        //    enemieDraw(e);

        //    //Comando temporário para resetar tiros

        //    if (event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode == ALLEGRO_KEY_R) {

        //        for (int i = 0; i < leftShotQuantos; i++) {

        //            leftShots[i].leftActive = false;
        //            leftShots[i].leftUsed = false;
        //        }

        //        for (int i = 0; i < rightShotQuantos; i++) {

        //            rightShots[i].rightActive = false;
        //            rightShots[i].rightUsed = false;
        //        }
        //    }

        //    //Para fechar janela do allegro com ESC ou no 'X' da janela

        //    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE || (event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)) {
        //        windowOn = 0;
        //    }

        //    //Trocando tela para fazer animação

        //    al_flip_display();
        //}

        //Destruindo criações do allegro

        al_destroy_timer(jogo.timer);
        al_destroy_display(jogo.window);
        al_destroy_event_queue(jogo.eventQueue);
        al_destroy_bitmap(jogo.bitmapBlocos);
        al_destroy_bitmap(jogo.bitmapBackground);
        al_destroy_bitmap(jogo.bitmapInimigos);
        al_destroy_bitmap(jogo.bitmapPlayer);
        al_destroy_bitmap(jogo.bitmapMenu);
        liberarAudio();

        return 0;
    }
}




//#include <stdlib.h>
//#include <allegro5/allegro.h>
//#include <allegro5/allegro_font.h>
//#include <allegro5/allegro_primitives.h>
//#include <allegro5/allegro_image.h>
//
//#include "Game.h"
//#include "stages.h"
//#include "Audio.h"
//
//int main() {
//
//    al_init();
//    al_install_keyboard();
//    al_install_mouse();
//
//    al_init_primitives_addon();
//    al_init_image_addon();
//    al_init_font_addon();
//
//    Jogo jogo = { 0 };
//
//    jogo.larguraTela = 1080;
//    jogo.alturaTela = 720;
//
//    al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);
//
//    jogo.window = al_create_display(
//        jogo.larguraTela,
//        jogo.alturaTela
//    );
//
//    jogo.eventQueue = al_create_event_queue();
//    jogo.timer = al_create_timer(1.0 / 30.0);
//
//    jogo.font = al_create_builtin_font();
//
//    jogo.bitmapMenu = al_load_bitmap("agente_001_menu.png");
//    jogo.bitmapBlocos = al_load_bitmap("agente_001_blocos.png");
//    jogo.bitmapInimigos = al_load_bitmap("agente_001_inimigos.png");
//    jogo.bitmapPlayer = al_load_bitmap("agente_001_player.png");
//
//    if (!jogo.window || !jogo.eventQueue || !jogo.timer ||
//        !jogo.font || !jogo.bitmapBlocos ||
//        !jogo.bitmapInimigos || !jogo.bitmapPlayer) {
//
//        return -1;
//    }
//
//    jogo.bitmapArmaAgente =
//        al_create_sub_bitmap(jogo.bitmapPlayer, 187, 0, 26, 8);
//
//    jogo.bitmapArmaRobo =
//        al_create_sub_bitmap(jogo.bitmapPlayer, 187, 73, 26, 8);
//
//    al_register_event_source(
//        jogo.eventQueue,
//        al_get_display_event_source(jogo.window)
//    );
//
//    al_register_event_source(
//        jogo.eventQueue,
//        al_get_timer_event_source(jogo.timer)
//    );
//
//    al_register_event_source(
//        jogo.eventQueue,
//        al_get_keyboard_event_source()
//    );
//
//    al_register_event_source(
//        jogo.eventQueue,
//        al_get_mouse_event_source()
//    );
//
//    al_set_window_title(jogo.window, "Agente 001");
//
//    al_start_timer(jogo.timer);
//
//    carregarAudio();
//
//    // Inicia o controlador do jogo
//    menu(&jogo);
//
//    // Liberação dos recursos
//    liberarAudio();
//
//    al_destroy_bitmap(jogo.bitmapArmaAgente);
//    al_destroy_bitmap(jogo.bitmapArmaRobo);
//
//    al_destroy_bitmap(jogo.bitmapMenu);
//    al_destroy_bitmap(jogo.bitmapBlocos);
//    al_destroy_bitmap(jogo.bitmapInimigos);
//    al_destroy_bitmap(jogo.bitmapPlayer);
//
//    al_destroy_font(jogo.font);
//
//    al_destroy_timer(jogo.timer);
//    al_destroy_event_queue(jogo.eventQueue);
//    al_destroy_display(jogo.window);
//
//    return 0;
//}
