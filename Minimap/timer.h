#ifndef timer_H
#define timer_H
#include <stdio.h>
#include <string.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

typedef struct Time{
	SDL_Surface *msg;
	TTF_Font *font;
  SDL_Rect positiontemps;
	int time;
	char timeString[10];
}Time;

void initializerTime(Time *time);
void displayTime(Time *time, SDL_Surface *screen);

#endif
