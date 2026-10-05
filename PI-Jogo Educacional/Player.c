#include "Player.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/keyboard.h>
#include <allegro5/mouse.h>
#include <math.h>



void playerMove(Player* p, ALLEGRO_EVENT event) {

    if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
        if (event.keyboard.keycode == ALLEGRO_KEY_W && p->standing == true) {
            p->keyboard.w_pressed = true;
            p->velY = -16;
            p->standing = false;
        }
        if (event.keyboard.keycode == ALLEGRO_KEY_A && p->keyboard.a_pressed == false) {
            p->keyboard.a_pressed = true;
        }
        if (event.keyboard.keycode == ALLEGRO_KEY_D && p->keyboard.d_pressed == false) {
            p->keyboard.d_pressed = true;
        }
    }

    if (event.type == ALLEGRO_EVENT_KEY_UP) {
        if (event.keyboard.keycode == ALLEGRO_KEY_W) {
            p->keyboard.w_pressed = false;

            if (p->velY < 0) {
                p->velY *= 0.5;
            }
        }
        if (event.keyboard.keycode == ALLEGRO_KEY_A) {
            p->keyboard.a_pressed = false;
        }
        if (event.keyboard.keycode == ALLEGRO_KEY_D) {
            p->keyboard.d_pressed = false;
        }
    }

    if (event.type == ALLEGRO_EVENT_TIMER) {
        if (p->keyboard.d_pressed == true) p->x += p->velocidade;
        if (p->keyboard.a_pressed == true) p->x -= p->velocidade;

        p->velY += 1;

        p->y += p->velY;
    }
};

void playerDraw(Player* p) {

    al_draw_filled_rectangle(p->x, p->y, p->x + p->largura, p->y + p->altura * 2, al_map_rgb(255, 0, 0));

};

void gun(Mouse* m, Shot *s[], int quantos, Player* p, ALLEGRO_EVENT event) {

    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
        if (event.mouse.button == ALLEGRO_MOUSE_BUTTON_LEFT && m->mouse.b_left == false) {
            m->mouse.b_left = true;
        }
        if (event.mouse.button == ALLEGRO_MOUSE_BUTTON_RIGHT && m->mouse.b_right == false) {
            m->mouse.b_right = true;
        }
    }

    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
        if (event.mouse.button == ALLEGRO_MOUSE_BUTTON_LEFT && m->mouse.b_left == true) {
            m->mouse.b_left = false;
            s[quantos]->shotX = m->gunX;
            s[quantos]->shotY = m->gunY;

            float shotAngle = atan2(m->mouseY - s[quantos]->shotY, m->mouseX - s[quantos]->shotX);

            s[quantos]->shotSpdX = cos(shotAngle) * 25;
            s[quantos]->shotSpdY = sin(shotAngle) * 25;
        }
        if (event.mouse.button == ALLEGRO_MOUSE_BUTTON_RIGHT && m->mouse.b_right == true) {
            m->mouse.b_right = false;
        }
    }
        
    if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
        m->mouseX = event.mouse.x;
        m->mouseY = event.mouse.y;
    }

    float angle = atan2(m->mouseY - (p->y + ((p->altura / 3) * 2.5)), m->mouseX - (p->x + (p->largura / 3) * 1.5));
    
    m->gunX = (p->x + (p->largura / 3) * 1.5) + cos(angle) * 30;
    m->gunY = (p->y + (p->altura / 3) * 2.5) + sin(angle) * 30;

    
};

void shot(Shot *s[], int quantos, ALLEGRO_EVENT event) {

    if (event.type == ALLEGRO_EVENT_TIMER) {
        s[quantos]->shotX += s[quantos]->shotSpdX;
        s[quantos]->shotY += s[quantos]->shotSpdY;
        
    }
};

void gunDraw(Mouse* m, Shot *s[], int quantos, Player* p) {

    al_draw_filled_rectangle(p->x + (p->largura / 3), p->y + ((p->altura / 3) * 2), p->x + ((p->largura/3) * 2), p->y + ((p->altura/3) * 3), al_map_rgb(0, 0, 255));

    al_draw_filled_circle(m->mouseX, m->mouseY, 7.5, al_map_rgb(0, 200, 0));

    al_draw_filled_circle(m->gunX, m->gunY, 7.5, al_map_rgb(0, 0, 255));

    al_draw_filled_circle(s[quantos]->shotX, s[quantos]->shotY, 7.5, al_map_rgb(0, 0, 255));
};