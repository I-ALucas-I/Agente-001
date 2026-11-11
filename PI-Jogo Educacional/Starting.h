#ifndef STARTING_H
#define STARTING_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

typedef struct {

	int width;
	int height;

	ALLEGRO_DISPLAY* window;
	ALLEGRO_EVENT_QUEUE* eventQueue;
	ALLEGRO_EVENT event;
	ALLEGRO_TIMER* timer;

	ALLEGRO_BITMAP* bitmapMenu;
	ALLEGRO_BITMAP* bitmapBackground;
	ALLEGRO_BITMAP* bitmapBlocos;
	ALLEGRO_BITMAP* bitmapInimigos;
	ALLEGRO_BITMAP* bitmapPlayer;
	ALLEGRO_BITMAP* bitmapArmaAgente;
	ALLEGRO_BITMAP* bitmapArmaRobo;

} Game;

#endif

