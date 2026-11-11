#include <stdio.h>
#include "Menu.h"
#include "Starting.h"
#include "Player.h"
#include "stages.h"

void menuControl(Game* jogo, Mouse* m) {

    Screen menu = MENU_INICIAL;

    bool executando = true;

    while (executando) {

        al_clear_to_color(al_map_rgb(255, 255, 255));
        al_wait_for_event(jogo->eventQueue, &jogo->event);

        if (jogo->event.type == ALLEGRO_EVENT_MOUSE_AXES) {
            m->mouseX = jogo->event.mouse.x;
            m->mouseY = jogo->event.mouse.y;
        }

        if (menu == MENU_INICIAL) {
         
            if (jogo->event.type == ALLEGRO_EVENT_DISPLAY_CLOSE || (jogo->event.type == ALLEGRO_EVENT_KEY_DOWN && jogo->event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)) {
                executando = false;
            }

            al_draw_bitmap_region(jogo->bitmapMenu, 0, 0, 1080, 720, 0, 0, 0);

            if (m->mouseX >= 140 && m->mouseX <= 140 + 71 && m->mouseY >= 383 && m->mouseY <= 383 + 12 && (jogo->event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && jogo->event.mouse.button == ALLEGRO_MOUSE_BUTTON_LEFT)) menu = MENU_FASES;
            if (m->mouseX >= 140 && m->mouseX <= 140 + 71 && m->mouseY >= 398 && m->mouseY <= 398 + 12 && (jogo->event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && jogo->event.mouse.button == ALLEGRO_MOUSE_BUTTON_LEFT)) menu = MENU_CONFIG;
            if (m->mouseX >= 140 && m->mouseX <= 140 + 71 && m->mouseY >= 413 && m->mouseY <= 413 + 12 && (jogo->event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && jogo->event.mouse.button == ALLEGRO_MOUSE_BUTTON_LEFT)) menu = MENU_CONTROLS;
        }

        if (menu == MENU_FASES) {

            if (jogo->event.type == ALLEGRO_EVENT_KEY_DOWN && jogo->event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                menu = MENU_INICIAL;
            }

            al_draw_bitmap_region(jogo->bitmapMenu, 0, 0, 1080, 720, 0, 0, 0);
            al_draw_bitmap_region(jogo->bitmapMenu, 1080, 0, 330, 194, 140 + 71, 201, 0);

            if (m->mouseX >= 279 && m->mouseX <= 279 + 43 && m->mouseY >= 239 && m->mouseY <= 239 + 25 && (jogo->event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && jogo->event.mouse.button == ALLEGRO_MOUSE_BUTTON_LEFT)) stage(jogo, m, 1);
            if (m->mouseX >= 329 && m->mouseX <= 329 + 43 && m->mouseY >= 239 && m->mouseY <= 239 + 25 && (jogo->event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && jogo->event.mouse.button == ALLEGRO_MOUSE_BUTTON_LEFT)) menu = MENU_CONFIG;
            if (m->mouseX >= 379 && m->mouseX <= 379 + 43 && m->mouseY >= 239 && m->mouseY <= 239 + 25 && (jogo->event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && jogo->event.mouse.button == ALLEGRO_MOUSE_BUTTON_LEFT)) menu = MENU_CONFIG;
            if (m->mouseX >= 429 && m->mouseX <= 429 + 43 && m->mouseY >= 239 && m->mouseY <= 239 + 25 && (jogo->event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && jogo->event.mouse.button == ALLEGRO_MOUSE_BUTTON_LEFT)) menu = MENU_CONFIG;
            if (m->mouseX >= 479 && m->mouseX <= 479 + 43 && m->mouseY >= 239 && m->mouseY <= 239 + 25 && (jogo->event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && jogo->event.mouse.button == ALLEGRO_MOUSE_BUTTON_LEFT)) menu = MENU_CONFIG;

        }

        if (menu == MENU_CONFIG) {
        
            if (jogo->event.type == ALLEGRO_EVENT_KEY_DOWN && jogo->event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                menu = MENU_INICIAL;
            }

            al_draw_bitmap_region(jogo->bitmapMenu, 0, 0, 1080, 720, 0, 0, 0);
            al_draw_bitmap_region(jogo->bitmapMenu, 1080, 195, 153, 194, 140 + 71, 216, 0);
        }

        if (menu == MENU_CONTROLS) {

            if (jogo->event.type == ALLEGRO_EVENT_KEY_DOWN && jogo->event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                menu = MENU_INICIAL;
            }

            al_draw_bitmap_region(jogo->bitmapMenu, 0, 0, 1080, 720, 0, 0, 0);
            al_draw_bitmap_region(jogo->bitmapMenu, 1080, 195, 153, 194, 140 + 71, 231, 0);
        }

        al_draw_bitmap_region(jogo->bitmapMenu, 1235, 197, 9, 12, m->mouseX, m->mouseY, 0);
        
        al_flip_display();
        
    }
}