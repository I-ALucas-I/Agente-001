#include "Player.h"
#include "Background.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>


void collision(Player* p, Platform* pl) {

	if (pl->solid == 0) {

		int playerE = p->x;
		int playerD = p->x + p->largura;
		int playerC = p->y;
		int playerB = p->y + p->altura * 2;
		int playerBAntes = playerB - p->velY;
		int playerCAntes = playerC - p->velY;

		int plataformaEsquerda = pl->x;
		int plataformaDireita = pl->x + pl->largura;
		int plataformaTopo = pl->y;
		int plataformaBaixo = pl->y + pl->altura;

		if (playerE < plataformaDireita && playerD > plataformaEsquerda && playerB > plataformaTopo && playerC < plataformaBaixo){
			if (playerE >= plataformaDireita - p->velocidade) {
				p->x = plataformaDireita;
				p->keyboard.a_pressed = false;
			}
		}

		if (playerD > plataformaEsquerda && playerE < plataformaDireita && playerB > plataformaTopo && playerC < plataformaBaixo){
			if (playerD <= plataformaEsquerda + p->velocidade) {
				p->x = plataformaEsquerda - p->largura;
				p->keyboard.d_pressed = false;
			}
		}

		if (playerD > plataformaEsquerda && playerE < plataformaDireita && p->velY > 0 && playerBAntes <= plataformaTopo && playerB >= plataformaTopo){
			p->y = plataformaTopo - (p->altura * 2);
			p->velY = 0;
			p->standing = true;
		}

		if (playerD > plataformaEsquerda && playerE < plataformaDireita && p->velY < 0 && playerCAntes >= plataformaBaixo && playerC <= plataformaBaixo){
			p->y = plataformaBaixo;
			p->velY = 0;
		}
	}
};
