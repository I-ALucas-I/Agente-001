#ifndef MENU_H
#define MENU_H

#include "Starting.h"
#include "Player.h"

typedef enum {
    MENU_INICIAL,
    MENU_CONFIG,
    MENU_FASES,
    MENU_CONTROLS,
    MENU_VITORIA,
    MENU_PAUSE,
    MENU_CODE,
    MENU_DERROTA
} Screen;

void menuControl(Game* jogo, Mouse* m);

#endif
