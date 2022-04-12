#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "player.h"
struct minimap
{
SDL_Surface* mini_map;
SDL_Rect pos_minimap;
SDL_Surface* mini_hero;
SDL_Rect pos_minihero;
};
typedef struct minimap minimap;

void init_minimap(minimap* mp);
void blit_minimap(minimap mp,SDL_Surface *screen);
void MAJMinimap(SDL_Rect pos_person,minimap *mp,SDL_Rect camera, int resize,int way);
/*void inittime(time *t);
void updatetime(time *t);
void displaytime(time *t,char time[],SDL_Surface* screen);*/
void free_minimap(minimap mp);

#endif
