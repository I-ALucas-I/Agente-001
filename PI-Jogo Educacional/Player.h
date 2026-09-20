#ifndef PLAYER_H
#define PLAYER_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

typedef struct {

	bool a_pressed;
	bool d_pressed;
	bool w_pressed;

}KeyboardPressed;

typedef struct {
    int x, x2;
    int y, y2;
    int velocidade;
    bool standing;
    KeyboardPressed keyboard;
} Player;

void playerMove(Player *p, ALLEGRO_EVENT event);

#endif