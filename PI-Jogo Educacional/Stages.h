//#ifndef STAGE_H
//#define STAGE_H
//
//#include <allegro5/allegro.h>
//#include <allegro5/allegro_primitives.h>
//#include <allegro5/allegro_image.h>
//
//typedef enum {
//
//	MENU_INICIAL,
//	MENU_CONFIG,
//	MENU_FASES,
//	MENU_VITORIA,
//	MENU_PAUSE,
//	MENU_CODE,
//	MENU_DERROTA
//
//}Tela;
//
//void menu(Tela tela);
//void stage(int fase, int subfase);
//
//#endif
//

#ifndef STAGES_H
#define STAGES_H

#include "Game.h"

typedef enum {
    MENU_INICIAL,
    MENU_CONFIG,
    MENU_FASES,
    MENU_VITORIA,
    MENU_PAUSE,
    MENU_CODE,
    MENU_DERROTA
} Tela;

typedef enum {
    FASE_CONCLUIDA,
    FASE_PERDIDA,
    FASE_PAUSADA,
    FASE_ABANDONADA
} ResultadoFase;

void menu(Jogo* jogo);

ResultadoFase stage(Jogo* jogo, int fase, int subfase);

#endif