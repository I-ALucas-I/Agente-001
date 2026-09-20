/*
movimentação:

//se pressionar uma tecla
if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
    if (event.keyboard.keycode == ALLEGRO_KEY_UP || event.keyboard.keycode == ALLEGRO_KEY_W) {
        keyboard.w_pressed = true;
    }
    if (event.keyboard.keycode == ALLEGRO_KEY_DOWN || event.keyboard.keycode == ALLEGRO_KEY_S) {
        keyboard.s_pressed = true;
    }
    if (event.keyboard.keycode == ALLEGRO_KEY_LEFT || event.keyboard.keycode == ALLEGRO_KEY_A) {
        keyboard.a_pressed = true;
    }
    if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT || event.keyboard.keycode == ALLEGRO_KEY_D) {
        keyboard.d_pressed = true;
    }
    if (event.keyboard.keycode == ALLEGRO_KEY_R) {
        reset(&player, &inimigo, num_tiros);
    }
    if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
        al_rest(1.0);
        saindo = true;
    }
}

//se soltar uma tecla
if (event.type == ALLEGRO_EVENT_KEY_UP) {
    if (event.keyboard.keycode == ALLEGRO_KEY_UP || event.keyboard.keycode == ALLEGRO_KEY_W) {
        keyboard.w_pressed = false;
    }
    if (event.keyboard.keycode == ALLEGRO_KEY_DOWN || event.keyboard.keycode == ALLEGRO_KEY_S) {
        keyboard.s_pressed = false;
    }
    if (event.keyboard.keycode == ALLEGRO_KEY_LEFT || event.keyboard.keycode == ALLEGRO_KEY_A) {
        keyboard.a_pressed = false;
    }
    if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT || event.keyboard.keycode == ALLEGRO_KEY_D) {
        keyboard.d_pressed = false;
    }


    lista de eventos:

    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();

    //caso falhe um evento, ele fecha a tela
    if (!event_queue) {
        al_destroy_display(display);
        printf("Algum evento falhou");
        return 1;
    }

    //registra os eventos
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());


    bibliotecas:

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/keyboard.h>
#include <allegro5/mouse.h>

pra iniciar elas:

    al_init();
    al_install_keyboard();
    al_install_mouse();
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon(); 
    */