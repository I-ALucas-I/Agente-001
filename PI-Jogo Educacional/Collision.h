#ifndef COLLISION_H
#define COLLISION_H

#include "Player.h"
#include "Background.h"

void plataformCollision(Player *p, Shot* left_s, int left_quantos, Shot* right_s, int right_quantos, Platform *pl);
void enemieCollision(Player p[], int quantosPlayers, Shot* left_s, int left_quantos, Shot* right_s, int right_quantos, int* pa, Enemie* e, int* mudar);
void enemieShotCollision(Shot* s[], int quantos, Enemie* e, int* mudar);




#endif