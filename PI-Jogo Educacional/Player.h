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

    int shotX;
    int shotY;
    float shotSpdX;
    float shotSpdY;
    bool active;
    bool used;

}Shot;

void playerMove(Player* p, ALLEGRO_EVENT event);
void playerSystem(Player p[], int quantos, int* pa, ALLEGRO_EVENT event);
void playerDraw(Player p[], int quantos);
void gun(Mouse* m, Shot* s, int quantos, Player* p, ALLEGRO_EVENT event);
void shot(Shot* s[], int quantos, ALLEGRO_EVENT event);
void gunDraw(Mouse* m, Shot* s[], int quantos, Player* p);
#endif
