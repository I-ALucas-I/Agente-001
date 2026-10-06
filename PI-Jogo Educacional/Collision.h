#ifndef COLLISION_H
#define COLLISION_H

#include "Player.h"
#include "Background.h"

void plataformCollision(Player *p, Platform *pl);
void enemieCollision(Player* p, Enemie* e);
void enemieShotCollision(Shot* s[], int quantos, Enemie* e, int* mudar);




#endif