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

int platform(int* larguraTela, int* alturaTela, int gridX, int gridY,int quantosX,int quantosY, Platform* pl) {
	int xInicial = *larguraTela / 90;
	int yInicial = *alturaTela / 60;
	
	//al_draw_filled_circle((xInicial * 3) * gridX - (xInicial * 3), (yInicial * 3) * gridY - (yInicial * 3), 10, al_map_rgb(255, 0, 0));
	//al_draw_filled_circle((xInicial * 3) * gridX, (yInicial * 3) * gridY,10, al_map_rgb(255, 255, 0));
	for (int i = 0; i < quantosY; i++) {
		for (int j = 0; j < quantosX; j++) {
			if (pl->x == 0) {
				al_draw_filled_rectangle((xInicial * 3) * (gridX + j) - (xInicial * 3), (yInicial * 3) * (gridY + i) - (yInicial * 3), (xInicial * 3) * (gridX + j), (yInicial * 3) * (gridY + i), al_map_rgb(255, 255, 255));
				pl->standable = 0;
			}
			if (pl->x == 1) {
				al_draw_filled_rectangle((xInicial * 3) * (gridX + j) - (xInicial * 3), (yInicial * 3) * (gridY + i) - (yInicial * 3), (xInicial * 3) * (gridX + j), (yInicial * 3) * (gridY + i), al_map_rgb(0, 255, 255));
				pl->standable = 1;
			}
			if (pl->x == 2) {
				al_draw_filled_rectangle((xInicial * 3) * (gridX + j) - (xInicial * 3), (yInicial * 3) * (gridY + i) - (yInicial * 3), (xInicial * 3) * (gridX + j), (yInicial * 3) * (gridY + i), al_map_rgb(255, 0, 255));
				pl->standable = 0;
			}
		}
	}

	return yInicial;
};
