#include "Player.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/keyboard.h>
#include <allegro5/mouse.h>



void playerMove(Player *p, ALLEGRO_EVENT event) {
   
    if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
        if (event.keyboard.keycode == ALLEGRO_KEY_W) {
            p->keyboard.w_pressed = true;
        }
        if (event.keyboard.keycode == ALLEGRO_KEY_A) {
            p->keyboard.a_pressed = true;
        }
        if (event.keyboard.keycode == ALLEGRO_KEY_D) {
            p->keyboard.d_pressed = true;
        }
    }

    if (event.type == ALLEGRO_EVENT_KEY_UP) {
        if (event.keyboard.keycode == ALLEGRO_KEY_UP || event.keyboard.keycode == ALLEGRO_KEY_W) {
            p->keyboard.w_pressed = false;
        }
        if (event.keyboard.keycode == ALLEGRO_KEY_LEFT || event.keyboard.keycode == ALLEGRO_KEY_A) {
            p->keyboard.a_pressed = false;
        }
        if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT || event.keyboard.keycode == ALLEGRO_KEY_D) {
            p->keyboard.d_pressed = false;
        }
    }

    if (p->keyboard.w_pressed == 1 && p->standing == true) p->y -= p->velocidade;
    if (p->standing == false) p->y += (p->velocidade * 2);
    if (p->keyboard.d_pressed == 1) p->x += p->velocidade;
    if (p->keyboard.a_pressed == 1) p->x -= p->velocidade;

    al_draw_filled_rectangle(p->x, p->y, p->x2, p->y2, al_map_rgb(255, 0, 0));
}