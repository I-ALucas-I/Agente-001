#ifndef COLLISION_H
#define COLLISION_H

#include "Player.h"
#include "Background.h"

void plataformCollision(Player *p, Platform *pl);
void enemieCollision(Player p[], int quantosPlayers, Shot s[], int quantos, int* pa, Enemie* e, int* mudar);
void enemieShotCollision(Shot* s[], int quantos, Enemie* e, int* mudar);




#endif