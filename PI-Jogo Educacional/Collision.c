#include "Player.h"
#include"Enemie.h"
#include "Background.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>


void plataformCollision(Player* p, Platform* pl) {

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

void enemieCollision(Player p[], int quantosPlayers, Shot s[], int quantos, int* pa, Enemie* e, int* mudar) {

	int enemieEsquerda = e->x;
	int enemieDireita = e->x + e->largura;
	int enemieTopo = e->y;
	int enemieBaixo = e->y + e->altura;

	int larguraTela = 1080;
	int alturaTela = 720;

	for (int i = 0; i < quantosPlayers; i++) {
		if (p[i].active) {
			int playerE = p[i].x;
			int playerD = p[i].x + p[i].largura;
			int playerC = p[i].y;
			int playerB = p[i].y + p[i].altura * 2;

			int playerBAntes = playerB - p[i].velY;
			int playerCAntes = playerC - p[i].velY;

			if (*mudar == 0) {
				if (i == quantosPlayers - 1) {
					if (playerD > enemieEsquerda && playerE < enemieDireita && playerB > enemieTopo && playerC < enemieBaixo) {

						p[i].x = ((larguraTela / 90) * 3) * 3 - ((larguraTela / 90) * 3);;
						p[i].y = ((alturaTela / 60) * 3) * 16 - ((alturaTela / 60) * 3);

					}
				}
				else {
					if (playerD > enemieEsquerda && playerE < enemieDireita && playerB > enemieTopo && playerC < enemieBaixo) {
						p[i].used = true;
						p[i].inUse = false;
						p[i].active = false;

						(*pa)++;

						p[*pa].active = true;
						p[*pa].inUse = true;
					}
				}
			}
			else {

				if (playerE < enemieDireita && playerD > enemieEsquerda && playerB > enemieTopo && playerC < enemieBaixo) {
					if (playerE >= enemieDireita - p[i].velocidade) {
						p[i].x = enemieDireita;
						p[i].keyboard.a_pressed = false;
					}
				}

				if (playerD > enemieEsquerda && playerE < enemieDireita && playerB > enemieTopo && playerC < enemieBaixo) {
					if (playerD <= enemieEsquerda + p[i].velocidade) {
						p[i].x = enemieEsquerda - p[i].largura;
						p[i].keyboard.d_pressed = false;
					}
				}

				if (playerD > enemieEsquerda && playerE < enemieDireita && p[i].velY > 0 && playerBAntes <= enemieTopo && playerB >= enemieTopo) {
					p[i].y = enemieTopo - (p[i].altura * 2);
					p[i].velY = 0;
					p[i].standing = true;
				}
				if (playerD > enemieEsquerda && playerE < enemieDireita && p[i].velY < 0 && playerCAntes >= enemieBaixo && playerC <= enemieBaixo) {
					p[i].y = enemieBaixo;
					p[i].velY = 0;
				}

			}
		}
	}

	for (int i = 0; i < quantos; i++) {
		int shotE = 0;
		int shotD = 0;
		int shotC = 0;
		int shotB = 0;


		if (s[i].active == true && s[i].used == false) {
			shotE = s[i].shotX - 6.5;
			shotD = s[i].shotX + 6.5;
			shotC = s[i].shotY - 6.5;
			shotB = s[i].shotY + 6.5;
		};

		if (*mudar == 0) {
			if (shotE < enemieDireita && shotD > enemieEsquerda && shotB > enemieTopo && shotC < enemieBaixo) {

				e->x = ((larguraTela / 90) * 3) * 7 - ((larguraTela / 90) * 3);;
				e->y = ((alturaTela / 60) * 3) * 17 - ((alturaTela / 60) * 3);

				s[i].used = true;
				(*mudar)++;
			}
		}
	}
}
//void enemieShotCollision(Shot s[], int quantos, Enemie* e, int* mudar) {
//	
//	for (int i = 0; i < quantos; i++) {
//		int shotE = 0;
//		int shotD = 0;
//		int shotC = 0;
//		int shotB = 0;
//
//
//		if (s[i].active == true && s[i].used == false) {
//			shotE = s[i].shotX - 6.5;
//			shotD = s[i].shotX + 6.5;
//			shotC = s[i].shotY - 6.5;
//			shotB = s[i].shotY + 6.5;
//
//
//
//			int enemieEsquerda = e->x;
//			int enemieDireita = e->x + e->largura;
//			int enemieTopo = e->y;
//			int enemieBaixo = e->y + e->altura;
//
//			int larguraTela = 1080;
//			int alturaTela = 720;
//
//			if (*mudar == 0) {
//				if (shotE < enemieDireita && shotD > enemieEsquerda && shotB > enemieTopo && shotC < enemieBaixo) {
//
//					e->x = ((larguraTela / 90) * 3) * 7 - ((larguraTela / 90) * 3);;
//					e->y = ((alturaTela / 60) * 3) * *mudar - ((alturaTela / 60) * 3);
//
//					s[i].used = true;
//					(*mudar)++;
//				}
//			}
//			else {
//
//			}
//		}
//	}
//};