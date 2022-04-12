#ifndef player_H
#define player_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "background.h"

//#include "text.h"
//#include "obstacle.h"

	/*PLAYER*/
typedef struct{
     SDL_Surface *img;
     SDL_Rect pos;
     //text score;
     //image lifes;
}player ;

void initPlayer(player *p);
void displayPlayer(player p, SDL_Surface * screen);
void freePlayer(player p);
void animePlayer (player* p);// in progress...

//movement
void front(player *p);
void back(player *p);
void jump(player *p,int *timeForJump);

#endif
