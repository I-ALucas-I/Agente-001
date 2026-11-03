#ifndef STAGE_H
#define STAGE_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

typedef enum {

	MENU_INICIAL,
	MENU_CONFIG,
	MENU_FASES,
	MENU_PRÓXIMA_FASE,
	MENU_PAUSE,
	MENU_CODE

}tela;

void menu(tela tela);
void stage(int fase, int subfase);

#endif

