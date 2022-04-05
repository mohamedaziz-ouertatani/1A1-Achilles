#ifndef player_H
#define player_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "background.h"
#include "image.h"
#include "text.h"
#include "obstacle.h"

	/*PLAYER*/
typedef struct{
     SDL_Surface *img;
     SDL_Rect pos;
     text score;
     image lifes;
}player ;

void initPlayer(player *p,const char *file, int X, int Y);
void displayPlayer(player p, SDL_Surface * screen);
void freePlayer(player p);
void animePlayer (player* p);// in progress...

//movement
void front(player *p,const char *file);
void back(player *p,const char *file);
void jump(player *p,int *timeForJump);

#endif
