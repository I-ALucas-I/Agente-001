#include "Enemie.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>


void enemieMove(Enemie* e, ALLEGRO_EVENT event) {

};

void enemieDraw(Enemie* e) {

	al_draw_filled_rectangle(e->x, e->y, e->x + e->largura, e->y + e->altura, al_map_rgb(100, 0, 200));

};
