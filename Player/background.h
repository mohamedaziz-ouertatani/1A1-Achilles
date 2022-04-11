#ifndef backgground_H
#define backgground_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "player.h"
#include "image.h"

	/*BACKGROUND*/
typedef struct{
     SDL_Surface *img;
     SDL_Rect pos;
}background ;

void initBackground(background *b, const char *file);
void displayBackground(background b, SDL_Surface *screen);
void freeBackground(background b);

#endif
