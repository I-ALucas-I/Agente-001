#ifndef BACKGROUND_H
#define BACKGROUND_H

void background(int *larguraTela, int *alturaTela);

typedef struct {
	int x; 
	int standable;
}Platform;

int platform(int* larguraTela, int* alturaTela, int gridY, int gridX, int quantosX, int quantosY, Platform* pl);

#endif
