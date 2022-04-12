#ifndef player_H
#define player_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "background.h"
#include "image.h"

typedef struct
{ 
 SDL_Surface *image;
 SDL_Rect pos;
 int dir; //0-Back 1-Front
 double speed,acceleration;
 int speedV; //getting back to ground speed (Gravity)
}Player;

void initPlayer(Player *p, const char *file);
void displayPlayer(Player p,SDL_Surface *screen);
void movePlayer(Player *p,int dt);
void jump(Player* p);
void freePlayer(Player p);
void animePlayer(Player *p);

#endif
