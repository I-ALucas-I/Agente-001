#include "Background.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

void background(int* larguraTela, int* alturaTela) {

	int y = *alturaTela / 60;
	int yInicial = *alturaTela / 60;
	int x = *larguraTela / 90;
	int xInicial = *larguraTela / 90;

	for (int i = 0; i < 90; i++) {
		al_draw_rectangle(1, 1, *larguraTela, *alturaTela, al_map_rgb(255, 255, 255), 1);
		al_draw_line(0, *alturaTela - y, *larguraTela, *alturaTela - y, al_map_rgb(255, 255, 255), 1);
		al_draw_line(*larguraTela - x, 0, *larguraTela - x, *alturaTela, al_map_rgb(255, 255, 255), 1);
		
		y += yInicial;
		x += xInicial;
	}
};

Platform platform(int* larguraTela, int* alturaTela, int gridX, int gridY,int quantosX,int quantosY, Platform* pl) {
	int xInicial = *larguraTela / 90;
	int yInicial = *alturaTela / 60;
	
	for (int i = 0; i < quantosY; i++) {
		for (int j = 0; j < quantosX; j++) {
			
			if (i == 0 && j == 0) {
				pl->x = (xInicial * 3) * (gridX + j ) - (xInicial * 3);
				pl->y = (yInicial * 3) * (gridY + i ) - (yInicial * 3);
			}

			if (i == quantosY-1 && j == quantosX-1) {
				pl->largura = (xInicial * 3) * (gridX + j) - pl->x;
				pl->altura = (yInicial * 3) * (gridY + i) - pl->y;
			}

			if (pl->tipo == 0) {
				pl->solid = 0;
			}
			if (pl->tipo == 1) {
				pl->solid = 1;
			}
			if (pl->tipo == 2) {
				pl->solid = 0;
			}
			if (pl->tipo == 3) {
				pl->solid = 0;
			}
			if (pl->tipo == 4) {
				pl->solid = 0;

				pl->largura = (xInicial * 3) * (gridX + 2) - pl->x;
				pl->altura = (yInicial * 3) * gridY - pl->y;
			}
		}
	}
	/*al_draw_filled_circle(pl->x, pl->y, 10, al_map_rgb(255, 100, 150));
	al_draw_filled_circle((xInicial * 3) * gridX - (xInicial * 3), (yInicial * 3) * gridY - (yInicial * 3), 10, al_map_rgb(255, 100, 150));
	al_draw_filled_circle((xInicial * 3) * gridX, (yInicial * 3) * gridY, 10, al_map_rgb(255, 255, 0));*/

	return *pl;
};

void platformDraw(Platform* pl) {

	if (pl->tipo == 0) {
		al_draw_filled_rectangle(pl->x, pl->y, pl->x + pl->largura, pl->y + pl->altura, al_map_rgb(0, 255, 0));
		
	}
	if (pl->tipo == 1) {
		al_draw_filled_rectangle(pl->x, pl->y, pl->x + pl->largura, pl->y + pl->altura, al_map_rgb(0, 255, 255));
		
	}
	if (pl->tipo == 2) {
		al_draw_filled_rectangle(pl->x, pl->y, pl->x + pl->largura, pl->y + pl->altura, al_map_rgb(255, 0, 255));
		
	}
	if (pl->tipo == 3) {
		al_draw_filled_rectangle(pl->x, pl->y, pl->x + pl->largura, pl->y + pl->altura, al_map_rgb(0, 0, 255));
		
	}
	if (pl->tipo == 4) {
		al_draw_filled_rectangle(pl->x, pl->y, pl->x + pl->largura, pl->y + pl->altura, al_map_rgb(240, 167, 58));
		
	}
};
