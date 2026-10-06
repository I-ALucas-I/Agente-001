#ifndef ENEMIE_H
#define ENEMIE_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

typedef struct {

    int x;
    int y;
    int largura;
    int altura;
    //float velocidade;
    //float velY;

} Enemie;

void enemieMove(Enemie* e, ALLEGRO_EVENT event);
void enemieDraw(Enemie* e);

#endif
