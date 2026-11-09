//#include <stdio.h>
//#include "stages.h"
//
//void menu(Jogo* jogo) {
//
//    Tela telaAtual = MENU_INICIAL;
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
//            executando = false;
//        }
//
//        if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
//
//            if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
//
//                if (telaAtual == MENU_INICIAL) {
//                    executando = false;
//                }
//                else {
//                    telaAtual = MENU_INICIAL;
//                }
//            }
//
//            if (telaAtual == MENU_INICIAL) {
//
//                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER) {
//                    telaAtual = MENU_FASES;
//                }
//
//                if (evento.keyboard.keycode == ALLEGRO_KEY_C) {
//                    telaAtual = MENU_CONFIG;
//                }
//            }
//
//            else if (telaAtual == MENU_FASES) {
//
//                if (evento.keyboard.keycode == ALLEGRO_KEY_1) {
//
//                    ResultadoFase resultado =
//                        stage(jogo, 2, 1);
//
//                    if (resultado == FASE_CONCLUIDA) {
//                        telaAtual = MENU_VITORIA;
//                    }
//                    else if (resultado == FASE_PERDIDA) {
//                        telaAtual = MENU_DERROTA;
//                    }
//                    else {
//                        telaAtual = MENU_INICIAL;
//                    }
//                }
//            }
//
//            else if (telaAtual == MENU_VITORIA ||
//                telaAtual == MENU_DERROTA) {
//
//                if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER) {
//                    telaAtual = MENU_FASES;
//                }
//            }
//        }
//
//        if (evento.type == ALLEGRO_EVENT_TIMER) {
//
//            al_clear_to_color(al_map_rgb(20, 20, 30));
//
//            switch (telaAtual) {
//
//            case MENU_INICIAL:
//
//                al_draw_text(
//                    jogo->font,
//                    al_map_rgb(255, 255, 255),
//                    jogo->larguraTela / 2,
//                    jogo->alturaTela / 3,
//                    ALLEGRO_ALIGN_CENTER,
//                    "AGENTE 001"
//                );
//
//                al_draw_text(
//                    jogo->font,
//                    al_map_rgb(255, 255, 255),
//                    jogo->larguraTela / 2,
//                    jogo->alturaTela / 2,
//                    ALLEGRO_ALIGN_CENTER,
//                    "ENTER - JOGAR"
//                );
//
//                al_draw_text(
//                    jogo->font,
//                    al_map_rgb(255, 255, 255),
//                    jogo->larguraTela / 2,
//                    jogo->alturaTela / 2 + 40,
//                    ALLEGRO_ALIGN_CENTER,
//                    "C - CONFIGURACOES"
//                );
//
//                break;
//
//            case MENU_FASES:
//
//                al_draw_text(
//                    jogo->font,
//                    al_map_rgb(255, 255, 255),
//                    jogo->larguraTela / 2,
//                    jogo->alturaTela / 2,
//                    ALLEGRO_ALIGN_CENTER,
//                    "1 - FASE 2, SUBFASE 1"
//                );
//
//                break;
//
//            case MENU_CONFIG:
//                al_draw_text(
//                    jogo->font,
//                    al_map_rgb(255, 255, 255),
//                    jogo->larguraTela / 2,
//                    jogo->alturaTela / 2,
//                    ALLEGRO_ALIGN_CENTER,
//                    "CONFIGURACOES"
//                );
//                break;
//
//            case MENU_VITORIA:
//                al_draw_text(
//                    jogo->font,
//                    al_map_rgb(0, 255, 0),
//                    jogo->larguraTela / 2,
//                    jogo->alturaTela / 2,
//                    ALLEGRO_ALIGN_CENTER,
//                    "FASE CONCLUIDA!"
//                );
//                break;
//
//            case MENU_DERROTA:
//                al_draw_text(
//                    jogo->font,
//                    al_map_rgb(255, 0, 0),
//                    jogo->larguraTela / 2,
//                    jogo->alturaTela / 2,
//                    ALLEGRO_ALIGN_CENTER,
//                    "VOCE PERDEU!"
//                );
//                break;
//
//            default:
//                break;
//            }
//
//            al_flip_display();
//        }
//    }
//}