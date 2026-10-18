#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

void background(int *larguraTela, int *alturaTela);

typedef struct {
	int x;
	int y;
	int largura;
	int altura;
	int tipo;
	int solid;
	ALLEGRO_BITMAP* bloco;
}Platform;

Platform platform(int* larguraTela, int* alturaTela, int gridX, int gridY, int quantosX, int quantosY, Platform* pl, ALLEGRO_BITMAP* bitmap);
void platformDraw(Platform* pl, int quantosX, int quantosY);
#endif
