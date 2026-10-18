#include "Player.h"
#include"Enemie.h"
#include "Background.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>


void plataformCollision(Player* p, Shot* left_s, int left_quantos, Shot* right_s, int right_quantos, Platform* pl) {

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

	int larguraTela = 1080;
	int alturaTela = 720;

	//Colisão bordas da tela

	if (playerE < larguraTela && playerD > 0 && playerB > 0 && playerC < alturaTela) {
		if (playerE <= 0 - p->velocidade) {
			p->x = 0;
			p->keyboard.a_pressed = false;
		}
	}

	if (playerD > 0 && playerE < larguraTela && playerB > 0 && playerC < alturaTela) {
		if (playerD >= larguraTela + p->velocidade) {
			p->x = larguraTela - p->largura;
			p->keyboard.d_pressed = false;
		}
	}

	if (pl->solid == 0) {

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

		if (playerD > plataformaEsquerda && playerE < plataformaDireita && playerBAntes <= plataformaTopo && playerB >= plataformaTopo){
			p->y = plataformaTopo - (p->altura * 2);
			p->velY = 0;
			p->standing = true;
		}

		if (playerD > plataformaEsquerda && playerE < plataformaDireita && playerCAntes >= plataformaBaixo && playerC <= plataformaBaixo){
			p->y = plataformaBaixo;
			p->velY = 0;
		}
	
		for (int i = 0; i < left_quantos; i++) {
			int leftShotE = 0;
			int leftShotD = 0;
			int leftShotC = 0;
			int leftShotB = 0;


			if (left_s[i].leftActive == true && left_s[i].leftUsed == false) {
				leftShotE = left_s[i].leftShotX - 4.5;
				leftShotD = left_s[i].leftShotX + 4.5;
				leftShotC = left_s[i].leftShotY - 4.5;
				leftShotB = left_s[i].leftShotY + 4.5;
			};

			
			if (leftShotE < plataformaDireita && leftShotD > plataformaEsquerda && leftShotB > plataformaTopo && leftShotC < plataformaBaixo) {
				left_s[i].leftUsed = true;
			}
		}

		for (int i = 0; i < right_quantos; i++) {
			int rightShotE = 0;
			int rightShotD = 0;
			int rightShotC = 0;
			int rightShotB = 0;


			if (right_s[i].rightActive == true && right_s[i].rightUsed == false) {
				rightShotE = right_s[i].rightShotX - 4.5;
				rightShotD = right_s[i].rightShotX + 4.5;
				rightShotC = right_s[i].rightShotY - 4.5;
				rightShotB = right_s[i].rightShotY + 4.5;
			};


			if (rightShotE < plataformaDireita && rightShotD > plataformaEsquerda && rightShotB > plataformaTopo && rightShotC < plataformaBaixo) {
				right_s[i].rightUsed = true;
			}
		}
	}
};

void enemieCollision(Player p[], int quantosPlayers, Shot* left_s, int left_quantos, Shot* right_s, int right_quantos, int* pa, Enemie* e) {

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

			if (e->mudar == 0) {
				if (i == quantosPlayers - 1) {
					if (playerD > enemieEsquerda && playerE < enemieDireita && playerB > enemieTopo && playerC < enemieBaixo) {

						//Falsa morte para poc

						p[i].x = ((larguraTela / 90) * 3) * 3 - ((larguraTela / 90) * 3);
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

				if (playerD > enemieEsquerda && playerE < enemieDireita && playerBAntes <= enemieTopo && playerB >= enemieTopo) {
					p[i].y = enemieTopo - (p[i].altura * 2);
					p[i].velY = 0;
					p[i].standing = true;
				}
				if (playerD > enemieEsquerda && playerE < enemieDireita && playerCAntes >= enemieBaixo && playerC <= enemieBaixo) {
					p[i].y = enemieBaixo;
					p[i].velY = 0;
				}

			}
		}
	}

	for (int i = 0; i < left_quantos; i++) {
		int leftShotE = 0;
		int leftShotD = 0;
		int leftShotC = 0;
		int leftShotB = 0;


		if (left_s[i].leftActive == true && left_s[i].leftUsed == false) {
			leftShotE = left_s[i].leftShotX - 4.5;
			leftShotD = left_s[i].leftShotX + 4.5;
			leftShotC = left_s[i].leftShotY - 4.5;
			leftShotB = left_s[i].leftShotY + 4.5;
		};

		if (e->mudar == 0) {
			if (leftShotE < enemieDireita && leftShotD > enemieEsquerda && leftShotB > enemieTopo && leftShotC < enemieBaixo) {

				left_s[i].leftUsed = true;
				e->mudar++;
			}
		}
		else {
			if (leftShotE < enemieDireita && leftShotD > enemieEsquerda && leftShotB > enemieTopo && leftShotC < enemieBaixo) {

				e->x = ((larguraTela / 90) * 3) * 7 - ((larguraTela / 90) * 3);
				e->y = ((alturaTela / 60) * 3) * 17 - ((alturaTela / 60) * 3);

				left_s[i].leftUsed = true;
			}
		}
	}

	for (int i = 0; i < right_quantos; i++) {
		int rightShotE = 0;
		int rightShotD = 0;
		int rightShotC = 0;
		int rightShotB = 0;


		if (right_s[i].rightActive == true && right_s[i].rightUsed == false) {
			rightShotE = right_s[i].rightShotX - 4.5;
			rightShotD = right_s[i].rightShotX + 4.5;
			rightShotC = right_s[i].rightShotY - 4.5;
			rightShotB = right_s[i].rightShotY + 4.5;
		};

		
		if (rightShotE < enemieDireita && rightShotD > enemieEsquerda && rightShotB > enemieTopo && rightShotC < enemieBaixo) {

			right_s[i].rightUsed = true;
		}
		
		
	}
};

void enemiePlatformCollision(Platform* pl, Enemie* e) {

	int enemieEsquerda = e->x;
	int enemieDireita = e->x + e->largura;
	int enemieTopo = e->y;
	int enemieBaixo = e->y + e->altura;

	int enemieEsquerdaAntes = enemieEsquerda - e->velocidade;
	int enemieDireitaAntes = enemieDireita - e->velocidade;
	int enemieBaixoAntes = enemieBaixo - e->velY;
	int enemieTopoAntes = enemieTopo - e->velY;

	int plataformaEsquerda = pl->x;
	int plataformaDireita = pl->x + pl->largura;
	int plataformaTopo = pl->y;
	int plataformaBaixo = pl->y + pl->altura;

	int larguraTela = 1080;
	int alturaTela = 720;

	if (enemieEsquerda < larguraTela && enemieDireita > 0 && enemieBaixo > 0 && enemieTopo < alturaTela) {
		if (enemieEsquerda <= 0 - e->velocidade) {
			e->x = 0;
			e->velocidade *= -1;
		}
	}

	if (enemieDireita > 0 && enemieEsquerda < larguraTela && enemieBaixo > 0 && enemieTopo < alturaTela) {
		if (enemieDireita >= larguraTela - e->velocidade) {
			e->x = larguraTela - e->largura;
			e->velocidade *= -1;
		}
	}

	if (pl->solid == 0) {

		if (e->velocidade > 0 && enemieDireita >= plataformaEsquerda && enemieDireitaAntes <= plataformaEsquerda && enemieBaixo > plataformaTopo && enemieTopo < plataformaBaixo) {
			e->x = plataformaEsquerda - e->largura;
			e->velocidade *= -1;
		}

		if (e->velocidade < 0 && enemieEsquerda <= plataformaDireita && enemieEsquerdaAntes >= plataformaDireita && enemieBaixo > plataformaTopo && enemieTopo < plataformaBaixo) {
			e->x = plataformaDireita;
			e->velocidade *= -1;
		}

		if (enemieDireita > plataformaEsquerda && enemieEsquerda < plataformaDireita && enemieBaixoAntes <= plataformaTopo && enemieBaixo >= plataformaTopo) {
			e->y = plataformaTopo - e->altura;
			e->velY = 0;
		}

		if (enemieDireita > plataformaEsquerda && enemieEsquerda < plataformaDireita && enemieTopoAntes >= plataformaBaixo && enemieTopo <= plataformaBaixo) {
			e->y = plataformaBaixo;
			e->velY = 0;
		}
	}
};
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