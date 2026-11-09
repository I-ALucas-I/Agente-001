#include <stdio.h>
#include "Audio.h"

ALLEGRO_SAMPLE* somPulo = NULL;
ALLEGRO_SAMPLE* somPuloCaida = NULL;
ALLEGRO_SAMPLE* somArma = NULL;

void carregarAudio() {

    somPulo = al_load_sample("pulo.wav");
    somPuloCaida = al_load_sample("pulo_caida.wav");
    somArma = al_load_sample("arma.wav");

    if (!somPulo || !somPuloCaida || !somArma) {
        printf("Erro ao carregar algum audio\n");
    }
}

void liberarAudio() {

    al_destroy_sample(somPulo);
    al_destroy_sample(somPuloCaida);
    al_destroy_sample(somArma);
}