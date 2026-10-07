#include "Player.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/keyboard.h>
#include <allegro5/mouse.h>
#include <math.h>



void playerMove(Player* p, ALLEGRO_EVENT event) {
    if (p->inUse == true) {
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
    }
};

void playerSystem(Player p[], int quantos, int* pa, ALLEGRO_EVENT event) {
    
    if (p[*pa].inUse == true){
        if (event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode == ALLEGRO_KEY_T) {
            p[*pa].inUse = false;

            if (p[*pa].inUse == false && *pa < quantos - 1) {

                (*pa)++;

                p[*pa].active = true;
                p[*pa].inUse = true;
            }
        }
    }

};

void playerDraw(Player p[], int quantos) {

    for (int i = 0; i < quantos; i++) {

        if (p[i].active == true) {

            if (i < quantos - 1) {
                al_draw_filled_rectangle(p[i].x, p[i].y, p[i].x + p[i].largura, p[i].y + p[i].altura * 2, al_map_rgb(255, 100, 0));
            }
            else {
                al_draw_filled_rectangle(p[i].x, p[i].y, p[i].x + p[i].largura, p[i].y + p[i].altura * 2, al_map_rgb(255, 0, 0));
            }
        }
    }
};

void gun(Mouse* m, Shot s[], int quantos, Player* p, ALLEGRO_EVENT event) {

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
            
            for (int i = 0; i < quantos; i++) {
             
                if (s[i].active == false) {
                    s[i].shotX = m->gunX;
                    s[i].shotY = m->gunY;

                    float shotAngle = atan2(m->mouseY - s[i].shotY, m->mouseX - s[i].shotX);

                    s[i].shotSpdX = cos(shotAngle) * 25;
                    s[i].shotSpdY = sin(shotAngle) * 25;

                    s[i].active = true;

                    break;
                }
            }
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

void shot(Shot s[], int quantos, ALLEGRO_EVENT event) {
    
    for (int i = 0; i < quantos; i++) {
        if(s[i].active == true && s[i].used == false){
            if (event.type == ALLEGRO_EVENT_TIMER) {
                s[i].shotX += s[i].shotSpdX;
                s[i].shotY += s[i].shotSpdY;

            }
        }
    }
};

void gunDraw(Mouse* m, Shot s[], int quantos, Player* p) {

    al_draw_filled_rectangle(p->x + (p->largura / 3), p->y + ((p->altura / 3) * 2), p->x + ((p->largura/3) * 2), p->y + ((p->altura/3) * 3), al_map_rgb(0, 0, 255));

    al_draw_filled_circle(m->mouseX, m->mouseY, 7.5, al_map_rgb(0, 200, 0));

    al_draw_filled_circle(m->gunX, m->gunY, 6.5, al_map_rgb(0, 0, 255));

    for (int i = 0; i < quantos; i++) {
        if (s[i].active == true && s[i].used == false) {
            al_draw_filled_circle(s[i].shotX, s[i].shotY, 6.5, al_map_rgb(0, 0, 255));
        }
    }
};
