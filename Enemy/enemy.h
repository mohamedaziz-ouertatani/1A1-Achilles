#ifndef enemy_H_INCLUDED
#define enemy_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct Enemy
        {
        SDL_Surface *sprite;
        SDL_Rect pos;
        int direction;
        SDL_Rect pos_sp;
        }Enemy;

void initEnemy(Enemy*e);    
void displayEnemy(Enemy e, SDL_Surface * screen);
void animateEnemy( Enemy * e);
void move( Enemy * e);
int collision( SDL_Rect E, SDL_Rect p) ;


#endif // DS_H_INCLUDED
	

