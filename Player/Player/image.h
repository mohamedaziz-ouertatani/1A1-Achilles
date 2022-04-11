#ifndef image_H
#define image_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "player.h"
#include "background.h"

	/*IMAGE*/
typedef struct{
     SDL_Surface *img;
     SDL_Rect pos;
}image ;

void initImage(image *i, const char *file, int X, int Y);
void displayImage(image i, SDL_Surface *screen);
void freeImage(image i);

#endif
