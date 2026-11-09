//#include <allegro5/allegro.h>
//#include <allegro5/allegro_font.h>
//#include <allegro5/allegro_primitives.h>
//#include <allegro5/keyboard.h>
//#include <allegro5/mouse.h>
//#include <allegro5/allegro_image.h>
//#include "Player.h"
//#include "Enemie.h"
//#include "Background.h"
//#include "Collision.h"
//#include "stages.h"
//
//void menu(Tela tela) {
//    switch (tela) {
//    
//    case MENU_INICIAL:
//        break;
//    case MENU_FASES:
//        break;
//    case MENU_CONFIG:
//        break;
//    case MENU_VITORIA:
//        break;
//    case MENU_CODE:
//        break;
//    case MENU_PAUSE:
//        break;
//    case MENU_DERROTA:
//        break;
//    }
//
//};
//
//void stage(int fase, int subfase) {
//
//	if (fase == 1) {
//
//		if (subfase == 1) {
//
//		}
//
//		if (subfase == 2) {
//
//		}
//
//		if (subfase == 3) {
//
//		}
//		
//		if (subfase == 4) {
//
//		}
//
//		if (subfase == 5) {
//
//		}
//	}
//
//	if (fase == 2) {
//
//		if (subfase == 1) {
//
//        
////         Player, inimigos e "blocos" serão posicionados pela grid
////         
////        --------------------------------------------------
////                                                          
////                  Grid 15x10: 30 -> x e 20 -> y           
////                                                          
////                  /--------------------------             
////                  | 1-1 | 2-1 |                           
////                  |-----|-----|                           
////                  | 1-2 | 2-2 |                           
////                  |-----|-----|                           
////                                                         
////      --------------------------------------------------
//        
//
////          Criando plataforma de nascimento dos robôs 1x3 || 1-1 | 1-2 | 1-3 ||
//
//            Platform nascimento;
//            nascimento.tipo = 4;
//            Platform* nascimentoP = &nascimento;
//
//            Platform plataforma;
//            plataforma.tipo = 0;
//            Platform* plataformaP = &plataforma;
//
//            Platform plataforma1;
//            plataforma1.tipo = 1;
//            Platform* plataforma1P = &plataforma1;
//
//            Platform plataforma2;
//            plataforma2.tipo = 0;
//            Platform* plataforma2P = &plataforma2;
//
//            Platform plataforma4;
//            plataforma4.tipo = 0;
//            Platform* plataforma4P = &plataforma4;
//
//            Platform plataforma5;
//            plataforma5.tipo = 0;
//            Platform* plataforma5P = &plataforma5;
//
//            Platform plataforma3;
//            plataforma3.tipo = 0;
//            Platform* plataforma3P = &plataforma3;
//
//            nascimento = platform(lT, aT, 16, 17, 1, 1, nascimentoP, bitmapBlocos);
//
//            plataforma = platform(lT, aT, 1, 18, 30, 3, plataformaP, bitmapBlocos);
//
//            plataforma1 = platform(lT, aT, 1, 1, 30, 17, plataforma1P, bitmapBlocos);
//
//            plataforma2 = platform(lT, aT, 11, 14, 5, 4, plataforma2P, bitmapBlocos);
//
//            plataforma3 = platform(lT, aT, 19, 12, 5, 6, plataforma3P, bitmapBlocos);
//
//            plataforma4 = platform(lT, aT, 21, 10, 5, 8, plataforma4P, bitmapBlocos);
//
//            plataforma5 = platform(lT, aT, 21, 9, 4, 1, plataforma5P, bitmapBlocos);
//
//
////          Iniciando array do jogador
//
//            Player jogador[3];
//            int quantosPlayers = 3;
//
//
//            for (int i = 0; i < quantosPlayers; i++) {
////                                               coordenada na grid
////                                                        |
////                                                        V
//                jogador[i].x = ((larguraTela / 90) * 3) * 3 - ((larguraTela / 90) * 3);
//                jogador[i].y = ((alturaTela / 60) * 3) * 16 - ((alturaTela / 60) * 3);
//                jogador[i].largura = (larguraTela / 90) * 3;
//                jogador[i].altura = (alturaTela / 60) * 3;
//                jogador[i].velocidade = 6;
//                jogador[i].velY = 0;
//                jogador[i].standing = true;
//                jogador[i].active = false;
//                jogador[i].inUse = false;
//                jogador[i].used = false;
//                jogador[i].keyboard.a_pressed = false;
//                jogador[i].keyboard.d_pressed = false;
//                jogador[i].keyboard.w_pressed = false;
//                jogador[i].player = bitmapPlayer;
//
//                if (i == 0) {
//                    jogador[i].active = true;
//                    jogador[i].inUse = true;
//                    jogador[i].x = nascimento.x + (nascimento.largura / 6 * 2);
//
//                    jogador[i].y = nascimento.y - (jogador[0].altura * 2);
//                }
//                if (i == quantosPlayers - 1) {
//                    jogador[i].active = true;
//                }
//            }
//
////          Ponteiro para saber corpo ativo do player
//
//            int playerAtual = 0;
//            int* pa = &playerAtual;
//
////          Iniciando inimigo
//
//            Enemie inimigo;
////                                       coordenada na grid             
////                                                 |
////                                                 V
//            inimigo.x = ((larguraTela / 90) * 3) * 7 - ((larguraTela / 90) * 3);
//            inimigo.y = ((alturaTela / 60) * 3) * 17 - ((alturaTela / 60) * 3);
//            inimigo.largura = (larguraTela / 90) * 3;
//            inimigo.altura = (alturaTela / 60) * 3;
//            inimigo.velocidade = 4.5;
//            inimigo.velY = 0;
//            inimigo.mudar = 0;
//            inimigo.inimigo = bitmapInimigos;
//
//
////          Ponteiro para chamar inimigo nas functions
//
//            Enemie* e = &inimigo;
//
////          Iniciando váriavel do mouse
//
//            Mouse mouse;
//
//            mouse.mouseX = larguraTela / 2;
//            mouse.mouseY = alturaTela / 2;
//            mouse.mouse.b_left = false;
//            mouse.mouse.b_right = false;
//
////          Ponteiro para chamar mouse nas functions
//
//            Mouse* m = &mouse;
//
////          Iniciando array de tiros
//
//            Shot leftShots[5];
//            int leftShotQuantos = 5;
//
//            for (int i = 0; i < leftShotQuantos; i++) {
//
//                leftShots[i].leftActive = false;
//                leftShots[i].leftUsed = false;
//            }
//
//            Shot rightShots[5];
//            int rightShotQuantos = 5;
//
//            for (int i = 0; i < rightShotQuantos; i++) {
//
//                rightShots[i].rightActive = false;
//                rightShots[i].rightUsed = false;
//            }
//
////          Ponteiro para tiros nas functions
//
//            Shot* left_s = &leftShots[0];
//            Shot* right_s = &rightShots[0];
//
////          Põe o muse no meio da tela
//
//            al_set_mouse_xy(window, mouse.mouseX, mouse.mouseY);
//            al_hide_mouse_cursor(window);
//		}
//
//		if (subfase == 2) {
//
//		}
//
//		if (subfase == 3) {
//
//		}
//
//		if (subfase == 4) {
//
//		}
//
//		if (subfase == 5) {
//
//		}
//	}
//
//	if (fase == 3) {
//
//		if (subfase == 1) {
//
//		}
//
//		if (subfase == 2) {
//
//		}
//
//		if (subfase == 3) {
//
//		}
//
//		if (subfase == 4) {
//
//		}
//
//		if (subfase == 5) {
//
//		}
//	}
//
//	if (fase == 4) {
//
//		if (subfase == 1) {
//
//		}
//
//		if (subfase == 2) {
//
//		}
//
//		if (subfase == 3) {
//
//		}
//
//		if (subfase == 4) {
//
//		}
//
//		if (subfase == 5) {
//
//		}
//	}
//};
//

//#include <stdlib.h>
//#include "stages.h"
//#include "Player.h"
//#include "Enemie.h"
//#include "Background.h"
//#include "Collision.h"
//
//static ResultadoFase executarSubfase21(Jogo* jogo) {
//
//    int* lT = &jogo->larguraTela;
//    int* aT = &jogo->alturaTela;
//
//    // -------------------------------
//    // CONFIGURAÇÃO DAS PLATAFORMAS
//    // -------------------------------
//
//    Platform nascimento = { 0 };
//    nascimento.tipo = 4;
//
//    Platform plataforma = { 0 };
//    plataforma.tipo = 0;
//
//    Platform plataforma1 = { 0 };
//    plataforma1.tipo = 1;
//
//    Platform plataforma2 = { 0 };
//    plataforma2.tipo = 0;
//
//    Platform plataforma3 = { 0 };
//    plataforma3.tipo = 0;
//
//    Platform plataforma4 = { 0 };
//    plataforma4.tipo = 0;
//
//    Platform plataforma5 = { 0 };
//    plataforma5.tipo = 0;
//
//    nascimento = platform(lT, aT, 16, 17, 1, 1,
//        &nascimento, jogo->bitmapBlocos);
//
//    plataforma = platform(lT, aT, 1, 18, 30, 3,
//        &plataforma, jogo->bitmapBlocos);
//
//    plataforma1 = platform(lT, aT, 1, 1, 30, 17,
//        &plataforma1, jogo->bitmapBlocos);
//
//    plataforma2 = platform(lT, aT, 11, 14, 5, 4,
//        &plataforma2, jogo->bitmapBlocos);
//
//    plataforma3 = platform(lT, aT, 19, 12, 5, 6,
//        &plataforma3, jogo->bitmapBlocos);
//
//    plataforma4 = platform(lT, aT, 21, 10, 5, 8,
//        &plataforma4, jogo->bitmapBlocos);
//
//    plataforma5 = platform(lT, aT, 21, 9, 4, 1,
//        &plataforma5, jogo->bitmapBlocos);
//
//
//    // -------------------------------
//    // CONFIGURAÇÃO DOS JOGADORES
//    // -------------------------------
//
//    Player jogador[3] = { 0 };
//    int quantosPlayers = 3;
//
//    for (int i = 0; i < quantosPlayers; i++) {
//
//        jogador[i].x = 0;
//        jogador[i].y = 0;
//
//        jogador[i].largura = (*lT / 90) * 3;
//        jogador[i].altura = (*aT / 60) * 3;
//
//        jogador[i].velocidade = 6;
//        jogador[i].velY = 0;
//
//        jogador[i].standing = true;
//
//        jogador[i].active = false;
//        jogador[i].inUse = false;
//        jogador[i].used = false;
//
//        jogador[i].keyboard.a_pressed = false;
//        jogador[i].keyboard.d_pressed = false;
//        jogador[i].keyboard.w_pressed = false;
//
//        jogador[i].player = jogo->bitmapPlayer;
//
//        if (i == 0) {
//            jogador[i].active = true;
//            jogador[i].inUse = true;
//
//            jogador[i].x = nascimento.x + nascimento.largura / 3;
//            jogador[i].y = nascimento.y - jogador[i].altura * 2;
//        }
//
//        if (i == quantosPlayers - 1) {
//            jogador[i].active = true;
//        }
//    }
//
//    int playerAtual = 0;
//    int* pa = &playerAtual;
//
//
//    // -------------------------------
//    // CONFIGURAÇÃO DO INIMIGO
//    // -------------------------------
//
//    Enemie inimigo = { 0 };
//
//    inimigo.x = ((*lT / 90) * 3) * 7 - ((*lT / 90) * 3);
//    inimigo.y = ((*aT / 60) * 3) * 17 - ((*aT / 60) * 3);
//
//    inimigo.largura = (*lT / 90) * 3;
//    inimigo.altura = (*aT / 60) * 3;
//
//    inimigo.velocidade = 4.5;
//    inimigo.velY = 0;
//    inimigo.mudar = 0;
//
//    inimigo.inimigo = jogo->bitmapInimigos;
//
//    Enemie* e = &inimigo;
//
//
//    // -------------------------------
//    // CONFIGURAÇÃO DO MOUSE
//    // -------------------------------
//
//    Mouse mouse = { 0 };
//
//    mouse.mouseX = *lT / 2;
//    mouse.mouseY = *aT / 2;
//
//    Mouse* m = &mouse;
//
//
//    // -------------------------------
//    // CONFIGURAÇÃO DOS TIROS
//    // -------------------------------
//
//    Shot leftShots[5] = { 0 };
//    Shot rightShots[5] = { 0 };
//
//    int leftShotQuantos = 5;
//    int rightShotQuantos = 5;
//
//    Shot* left_s = leftShots;
//    Shot* right_s = rightShots;
//
//    al_set_mouse_xy(jogo->window, mouse.mouseX, mouse.mouseY);
//    al_hide_mouse_cursor(jogo->window);
//
//
//    // -------------------------------
//    // LOOP DA SUBFASE
//    // -------------------------------
//
//    bool executando = true;
//
//    while (executando) {
//
//        ALLEGRO_EVENT evento;
//
//        al_wait_for_event(jogo->eventQueue, &evento);
//
//        if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
//            return FASE_ABANDONADA;
//        }
//
//        if (evento.type == ALLEGRO_EVENT_KEY_DOWN &&
//            evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
//
//            return FASE_PAUSADA;
//        }
//
//        if (evento.type == ALLEGRO_EVENT_TIMER) {
//
//            Player* p = &jogador[playerAtual];
//
//            p->standing = false;
//
//            // Aqui entram as atualizações:
//            // playerMove, playerSystem, gun, shot e enemieMove.
//            //
//            // Aqui também entram as colisões que você já
//            // utiliza no seu main.c.
//
//            al_clear_to_color(al_map_rgb(0, 255, 255));
//
//            background(lT, aT);
//
//            // Desenho das plataformas
//            platformDraw(&plataforma, 30, 3);
//            platformDraw(&plataforma1, 30, 17);
//            platformDraw(&plataforma2, 5, 4);
//            platformDraw(&plataforma3, 5, 6);
//            platformDraw(&plataforma4, 5, 8);
//            platformDraw(&plataforma5, 4, 1);
//            platformDraw(&nascimento, 0, 0);
//
//            // Desenho dos personagens
//            playerDraw(jogador, quantosPlayers);
//            enemieDraw(e);
//
//            al_flip_display();
//        }
//    }
//
//    return FASE_CONCLUIDA;
//}
//
//
//ResultadoFase stage(Jogo* jogo, int fase, int subfase) {
//
//    if (fase == 2 && subfase == 1) {
//        return executarSubfase21(jogo);
//    }
//
//    // Subfase ainda não implementada
//    return FASE_ABANDONADA;
//}
