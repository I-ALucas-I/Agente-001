//#include <allegro5/allegro.h>
//#include <allegro5/allegro_font.h>
//#include <allegro5/allegro_primitives.h>
//#include <allegro5/keyboard.h>
//#include <allegro5/mouse.h>
//#include <allegro5/allegro_image.h>
//#include "Player.h"
//#include "Enemie.h"
//#include "Background.h"
//#include "Collision.h"
//
//void menu(int tela) {
//
//};
//
//void stage(int fase, int subfase, ) {
//
//	if (fase == 1) {
//
//		if (subfase == 1) {
//
//		}
//
//		if (subfase == 2) {
//
//		}
//
//		if (subfase == 3) {
//
//		}
//		
//		if (subfase == 4) {
//
//		}
//
//		if (subfase == 5) {
//
//		}
//	}
//
//	if (fase == 2) {
//
//		if (subfase == 1) {
//
//        //
//        // Player, inimigos e "blocos" serão posicionados pela grid
//        // 
//        //--------------------------------------------------//
//        //                                                  //
//        //          Grid 15x10: 30 -> x e 20 -> y           //
//        //                                                  //
//        //          /--------------------------             //
//        //          | 1-1 | 2-1 |                           //
//        //          |-----|-----|                           //
//        //          | 1-2 | 2-2 |                           //
//        //          |-----|-----|                           //
//        //                                                  //
//        //--------------------------------------------------//
//        //
//
//        //Criando plataforma de nascimento dos robôs 1x3 || 1-1 | 1-2 | 1-3 ||
//
//            Platform nascimento;
//            nascimento.tipo = 4;
//            Platform* nascimentoP = &nascimento;
//
//            Platform plataforma;
//            plataforma.tipo = 0;
//            Platform* plataformaP = &plataforma;
//
//            Platform plataforma1;
//            plataforma1.tipo = 1;
//            Platform* plataforma1P = &plataforma1;
//
//            Platform plataforma2;
//            plataforma2.tipo = 0;
//            Platform* plataforma2P = &plataforma2;
//
//            Platform plataforma4;
//            plataforma4.tipo = 0;
//            Platform* plataforma4P = &plataforma4;
//
//            Platform plataforma5;
//            plataforma5.tipo = 0;
//            Platform* plataforma5P = &plataforma5;
//
//            Platform plataforma3;
//            plataforma3.tipo = 0;
//            Platform* plataforma3P = &plataforma3;
//
//            nascimento = platform(lT, aT, 16, 17, 1, 1, nascimentoP, bitmapBlocos);
//
//            plataforma = platform(lT, aT, 1, 18, 30, 3, plataformaP, bitmapBlocos);
//
//            plataforma1 = platform(lT, aT, 1, 1, 30, 17, plataforma1P, bitmapBlocos);
//
//            plataforma2 = platform(lT, aT, 11, 14, 5, 4, plataforma2P, bitmapBlocos);
//
//            plataforma3 = platform(lT, aT, 19, 12, 5, 6, plataforma3P, bitmapBlocos);
//
//            plataforma4 = platform(lT, aT, 21, 10, 5, 8, plataforma4P, bitmapBlocos);
//
//            plataforma5 = platform(lT, aT, 21, 9, 4, 1, plataforma5P, bitmapBlocos);
//
//
//            //Iniciando array do jogador
//
//            Player jogador[3];
//            int quantosPlayers = 3;
//            //                          coordenada na grid
//            // 
//            //                                   |
//            //                                   V
//            //
//            /*jogador.x = ((larguraTela/90) * 3) * 3 - ((larguraTela / 90) * 3);
//            jogador.y = ((alturaTela / 60) * 3) * 16 - ((alturaTela / 60) * 3);
//            jogador.largura = (larguraTela / 90) * 3;
//            jogador.altura = (alturaTela / 60) * 3;
//            jogador.velocidade = 6;
//            jogador.velY = 0;
//            jogador.standing = true;
//            jogador.keyboard.a_pressed = false;
//            jogador.keyboard.d_pressed = false;
//            jogador.keyboard.w_pressed = false;*/
//
//            for (int i = 0; i < quantosPlayers; i++) {
//                jogador[i].x = ((larguraTela / 90) * 3) * 3 - ((larguraTela / 90) * 3);
//                jogador[i].y = ((alturaTela / 60) * 3) * 16 - ((alturaTela / 60) * 3);
//                jogador[i].largura = (larguraTela / 90) * 3;
//                jogador[i].altura = (alturaTela / 60) * 3;
//                jogador[i].velocidade = 6;
//                jogador[i].velY = 0;
//                jogador[i].standing = true;
//                jogador[i].active = false;
//                jogador[i].inUse = false;
//                jogador[i].used = false;
//                jogador[i].keyboard.a_pressed = false;
//                jogador[i].keyboard.d_pressed = false;
//                jogador[i].keyboard.w_pressed = false;
//                jogador[i].player = bitmapPlayer;
//
//                if (i == 0) {
//                    jogador[i].active = true;
//                    jogador[i].inUse = true;
//                    jogador[i].x = nascimento.x + (nascimento.largura / 6 * 2);
//
//                    jogador[i].y = nascimento.y - (jogador[0].altura * 2);
//                }
//                if (i == quantosPlayers - 1) {
//                    jogador[i].active = true;
//                }
//            }
//
//            //Ponteiro para saber corpo ativo do player
//
//            int playerAtual = 0;
//            int* pa = &playerAtual;
//
//            //Iniciando inimigo
//
//            Enemie inimigo;
//            //                          coordenada na grid
//            // 
//            //                                   |
//            //                                   V
//            //
//            inimigo.x = ((larguraTela / 90) * 3) * 7 - ((larguraTela / 90) * 3);
//            inimigo.y = ((alturaTela / 60) * 3) * 17 - ((alturaTela / 60) * 3);
//            inimigo.largura = (larguraTela / 90) * 3;
//            inimigo.altura = (alturaTela / 60) * 3;
//            inimigo.velocidade = 4.5;
//            inimigo.velY = 0;
//            inimigo.mudar = 0;
//            inimigo.inimigo = bitmapInimigos;
//
//
//            //Ponteiro para chamar inimigo nas functions
//
//            Enemie* e = &inimigo;
//
//            //Iniciando váriavel do mouse
//
//            Mouse mouse;
//
//            mouse.mouseX = larguraTela / 2;
//            mouse.mouseY = alturaTela / 2;
//            mouse.mouse.b_left = false;
//            mouse.mouse.b_right = false;
//
//            //Ponteiro para chamar mouse nas functions
//
//            Mouse* m = &mouse;
//
//            //Iniciando array de tiros
//
//            Shot leftShots[5];
//            int leftShotQuantos = 5;
//
//            for (int i = 0; i < leftShotQuantos; i++) {
//
//                leftShots[i].leftActive = false;
//                leftShots[i].leftUsed = false;
//            }
//
//            Shot rightShots[5];
//            int rightShotQuantos = 5;
//
//            for (int i = 0; i < rightShotQuantos; i++) {
//
//                rightShots[i].rightActive = false;
//                rightShots[i].rightUsed = false;
//            }
//
//            //Ponteiro para tiros nas functions
//
//            Shot* left_s = &leftShots[0];
//            Shot* right_s = &rightShots[0];
//
//            //Põe o muse no meio da tela
//
//            al_set_mouse_xy(window, mouse.mouseX, mouse.mouseY);
//		}
//
//		if (subfase == 2) {
//
//		}
//
//		if (subfase == 3) {
//
//		}
//
//		if (subfase == 4) {
//
//		}
//
//		if (subfase == 5) {
//
//		}
//	}
//
//	if (fase == 3) {
//
//		if (subfase == 1) {
//
//		}
//
//		if (subfase == 2) {
//
//		}
//
//		if (subfase == 3) {
//
//		}
//
//		if (subfase == 4) {
//
//		}
//
//		if (subfase == 5) {
//
//		}
//	}
//
//	if (fase == 4) {
//
//		if (subfase == 1) {
//
//		}
//
//		if (subfase == 2) {
//
//		}
//
//		if (subfase == 3) {
//
//		}
//
//		if (subfase == 4) {
//
//		}
//
//		if (subfase == 5) {
//
//		}
//	}
//};
//
