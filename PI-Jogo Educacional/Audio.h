#ifndef AUDIO_H
#define AUDIO_H

#include <allegro5/allegro_audio.h>

extern ALLEGRO_SAMPLE* somPulo;
extern ALLEGRO_SAMPLE* somPuloCaida;
extern ALLEGRO_SAMPLE* somArma;

void carregarAudio();
void liberarAudio();

#endif