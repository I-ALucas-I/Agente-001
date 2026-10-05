#ifndef BACKGROUND_H
#define BACKGROUND_H

void background(int *larguraTela, int *alturaTela);

typedef struct {
	int x;
	int y;
	int largura;
	int altura;
	int tipo;
	int solid;
}Platform;

Platform platform(int* larguraTela, int* alturaTela, int gridY, int gridX, int quantosX, int quantosY, Platform* pl);
void platformDraw(Platform* pl);
#endif
