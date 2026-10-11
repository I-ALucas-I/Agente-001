#ifndef PLAYER_H
#define PLAYER_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

typedef struct {

	bool a_pressed;
	bool d_pressed;
	bool w_pressed;

}KeyboardPressed;

typedef struct {
    
    int x;
    int y;
    int largura;
    int altura;
    float velocidade;
    float velY;
    bool standing;
    bool active;
    bool inUse;
    bool used;
    KeyboardPressed keyboard;

} Player;

typedef struct {

    bool b_right;
    bool b_left;

}MousePressed;

typedef struct {

    int mouseX;
    int mouseY;
    int gunX;
    int gunY;
    MousePressed mouse;

}Mouse;

typedef struct {

    int leftShotX;
    int leftShotY;
    float leftShotSpdX;
    float leftShotSpdY;
    bool leftActive;
    bool leftUsed;

    int rightShotX;
    int rightShotY;
    float rightShotSpdX;
    float rightShotSpdY;
    bool rightActive;
    bool rightUsed;

}Shot;

void playerMove(Player* p, ALLEGRO_EVENT event);
void playerSystem(Player p[], int quantos, int* pa, ALLEGRO_EVENT event);
void playerDraw(Player p[], int quantos);
void gun(Mouse* m, Shot* left_s, int left_quantos, Shot* right_s, int right_quantos, Player* p, ALLEGRO_EVENT event);
void shot(Shot* left_s, int left_quantos, Shot* right_s, int right_quantos, ALLEGRO_EVENT event);
void gunDraw(Mouse* m, Shot* left_s, int left_quantos, Shot* right_s, int right_quantos, Player* p);
#endif
