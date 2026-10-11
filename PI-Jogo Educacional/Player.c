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

void gun(Mouse* m, Shot* left_s, int left_quantos, Shot* right_s, int right_quantos, Player* p, ALLEGRO_EVENT event) {

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
            
            for (int i = 0; i < left_quantos; i++) {
             
                if (left_s[i].leftActive == false) {

                    left_s[i].leftShotX = m->gunX;
                    left_s[i].leftShotY = m->gunY;

                    float leftShotAngle = atan2(m->mouseY - left_s[i].leftShotY, m->mouseX - left_s[i].leftShotX);

                    left_s[i].leftShotSpdX = cos(leftShotAngle) * 25;
                    left_s[i].leftShotSpdY = sin(leftShotAngle) * 25;

                    left_s[i].leftActive = true;

                    break;
                }
            }
        }
        if (event.mouse.button == ALLEGRO_MOUSE_BUTTON_RIGHT && m->mouse.b_right == true) {
            m->mouse.b_right = false;

            for (int i = 0; i < right_quantos; i++) {

                if (right_s[i].rightActive == false) {

                    right_s[i].rightShotX = m->gunX;
                    right_s[i].rightShotY = m->gunY;

                    float rightShotAngle = atan2(m->mouseY - right_s[i].rightShotY, m->mouseX - right_s[i].rightShotX);

                    right_s[i].rightShotSpdX = cos(rightShotAngle) * 25;
                    right_s[i].rightShotSpdY = sin(rightShotAngle) * 25;

                    right_s[i].rightActive = true;

                    break;
                }
            }
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

void shot(Shot* left_s, int left_quantos, Shot* right_s, int right_quantos, ALLEGRO_EVENT event) {
    
    for (int i = 0; i < left_quantos; i++) {
        if(left_s[i].leftActive == true && left_s[i].leftUsed == false){
            if (event.type == ALLEGRO_EVENT_TIMER) {
                left_s[i].leftShotX += left_s[i].leftShotSpdX;
                left_s[i].leftShotY += left_s[i].leftShotSpdY;

            }
        }
    }

    for (int i = 0; i < right_quantos; i++) {
        if (right_s[i].rightActive == true && right_s[i].rightUsed == false) {
            if (event.type == ALLEGRO_EVENT_TIMER) {
                right_s[i].rightShotX += right_s[i].rightShotSpdX;
                right_s[i].rightShotY += right_s[i].rightShotSpdY;

            }
        }
    }
};

void gunDraw(Mouse* m, Shot* left_s, int left_quantos, Shot* right_s, int right_quantos, Player* p) {

    al_draw_filled_rectangle(p->x + (p->largura / 3), p->y + ((p->altura / 3) * 2), p->x + ((p->largura/3) * 2), p->y + ((p->altura/3) * 3), al_map_rgb(0, 0, 255));

    al_draw_filled_circle(m->mouseX, m->mouseY, 7.5, al_map_rgb(0, 200, 0));

    al_draw_filled_circle(m->gunX, m->gunY, 6.5, al_map_rgb(0, 0, 255));

    for (int i = 0; i < left_quantos; i++) {
        if (left_s[i].leftActive == true && left_s[i].leftUsed == false) {
            al_draw_filled_circle(left_s[i].leftShotX, left_s[i].leftShotY, 6.5, al_map_rgb(0, 0, 255));
        }
    }

    for (int i = 0; i < right_quantos; i++) {
        if (right_s[i].rightActive == true && right_s[i].rightUsed == false) {
            al_draw_filled_circle(right_s[i].rightShotX, right_s[i].rightShotY, 6.5, al_map_rgb(255, 0, 0));
        }
    }
};
