#include "Player.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/keyboard.h>
#include <allegro5/mouse.h>
#include <math.h>
#include "Audio.h"

void playerMove(Player* p, ALLEGRO_EVENT event) {
    if (p->inUse == true) {

        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (event.keyboard.keycode == ALLEGRO_KEY_W && p->standing == true) {
                p->keyboard.w_pressed = true;
                p->velY = -16;
                p->standing = false;
                
                al_play_sample(somPulo, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
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

        if (event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode == ALLEGRO_KEY_T && *pa != quantos - 1) {
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

            if (p[i].inUse == false) {

                p[i].largura = 36;

                if (i < quantos - 1) {
                    al_draw_bitmap_region(p[i].player, 0, 73, 36, 72, p[i].x, p[i].y, 0);
                }
                else {
                    al_draw_bitmap_region(p[i].player, 0, 0, 36, 72, p[i].x, p[i].y, 0);
                }

            }
            else {
                p[i].largura = 30;

                if (p[i].standing == true) {
                 
                    if (p[i].keyboard.d_pressed == true && p[i].keyboard.a_pressed == false) p[i].quadro++;

                    if (p[i].keyboard.a_pressed == true && p[i].keyboard.d_pressed == false) p[i].quadro++;
                }
                if (p[i].quadro == 5) {

                    p[i].anima++;
                    p[i].quadro = 0;
                }

                if (p[i].anima > 5 || p[i].keyboard.d_pressed == false && p[i].keyboard.a_pressed == false) p[i].anima = 1;
                if (i < quantos - 1) {
                    if (p[i].olhar == 1)al_draw_bitmap_region(p[i].player, 7 + p[i].anima * 30, 73, 30, 72, p[i].x, p[i].y, 0);
                    else al_draw_bitmap_region(p[i].player, 7 + p[i].anima * 30, 73, 30, 72, p[i].x, p[i].y, ALLEGRO_FLIP_HORIZONTAL);
                }
                else {
                    if (p[i].olhar == 1)al_draw_bitmap_region(p[i].player, 7 + p[i].anima * 30, 0, 30, 72, p[i].x, p[i].y, 0);
                    else al_draw_bitmap_region(p[i].player, 7 + p[i].anima * 30, 0, 30, 72, p[i].x, p[i].y, ALLEGRO_FLIP_HORIZONTAL);
                }
            }

        }
    }
};

void gun(Mouse* m, Shot* left_s, int left_quantos, Shot* right_s, int right_quantos, Player* p, ALLEGRO_EVENT event) {

    if (event.type == ALLEGRO_EVENT_TIMER) {

        if (m->mouseX >= p->x + (p->largura / 2)) p->olhar = 1;
        else p->olhar = 0;
    }

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

                    left_s[i].leftShotX = m->gunX + cos(m->angle) * 25;
                    left_s[i].leftShotY = m->gunY + sin(m->angle) * 25;

                    float leftShotAngle = atan2(m->mouseY - left_s[i].leftShotY, m->mouseX - left_s[i].leftShotX);

                    left_s[i].leftShotSpdX = cos(leftShotAngle) * 25;
                    left_s[i].leftShotSpdY = sin(leftShotAngle) * 25;

                    left_s[i].leftActive = true;
                    al_play_sample(somArma, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);

                    break;
                }
            }
        }
        if (event.mouse.button == ALLEGRO_MOUSE_BUTTON_RIGHT && m->mouse.b_right == true) {
            m->mouse.b_right = false;

            for (int i = 0; i < right_quantos; i++) {

                if (right_s[i].rightActive == false) {

                    right_s[i].rightShotX = m->gunX + cos(m->angle) * 25;
                    right_s[i].rightShotY = m->gunY + sin(m->angle) * 25;

                    float rightShotAngle = atan2(m->mouseY - right_s[i].rightShotY, m->mouseX - right_s[i].rightShotX);

                    right_s[i].rightShotSpdX = cos(rightShotAngle) * 25;
                    right_s[i].rightShotSpdY = sin(rightShotAngle) * 25;

                    right_s[i].rightActive = true;
                    al_play_sample(somArma, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);

                    break;
                }
            }
        }
    }

    if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
        m->mouseX = event.mouse.x;
        m->mouseY = event.mouse.y;
    }

    m->angle = atan2(m->mouseY - (p->y + p->altura - 2), m->mouseX - (p->x + (p->largura / 3) * 1.5));

    if(p->olhar == 1) m->gunX = (p->x + (p->largura / 3) * 1);
    else m->gunX = (p->x + (p->largura / 3) * 2);
    m->gunY = p->y + p->altura - 2;

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

    al_draw_rotated_bitmap(p->gun, 4, 5, m->gunX, m->gunY , m->angle, 0);

    al_draw_bitmap_region(p->player, 16, 146, 15, 15, m->mouseX - 8, m->mouseY - 8, 0);

    for (int i = 0; i < left_quantos; i++) {
        if (left_s[i].leftActive == true && left_s[i].leftUsed == false) {
            al_draw_bitmap_region(p->player, 0, 162, 15, 15, left_s[i].leftShotX - 8, left_s[i].leftShotY - 8, 0);
        }
    }

    for (int i = 0; i < right_quantos; i++) {
        if (right_s[i].rightActive == true && right_s[i].rightUsed == false) {
            al_draw_bitmap_region(p->player, 0, 146, 15, 15, right_s[i].rightShotX - 8, right_s[i].rightShotY - 8, 0);
        }
    }
};
