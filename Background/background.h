#ifndef bg_H_INCLUDED
#define bg_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct
{
SDL_Surface * im_player;
SDL_Rect pos_p; 
}player;

typedef struct
{

    SDL_Surface *image;
    SDL_Rect positionbackground;
    SDL_Rect positionback_share;

    SDL_Rect camera1;
    SDL_Rect camera2;
    SDL_Surface *sprite;
    SDL_Rect pos;
    int direction;
    SDL_Rect pos_sp;

} background;


typedef struct
{

    int left, right,up,down,d,q,z,s;

} mouvement;


void initBack(background *b);
void displayBack(SDL_Surface *screen, background *b);
void displayBack_share(SDL_Surface *screen,background *b);
void scrolling_right(background *b, float velocity, SDL_Surface *screen, mouvement M);
void scrolling_right_share(background *b, float velocity, SDL_Surface *screen, mouvement M);
void scrolling_left(background *b, float velocity, SDL_Surface *screen, mouvement M);
void scrolling_left_share(background *b, float velocity, SDL_Surface *screen, mouvement M);
void scrolling_up(background *b, float velocity, SDL_Surface *screen, mouvement M);
void scrolling_up_share(background *b, float velocity, SDL_Surface *screen, mouvement M);
void scrolling_down(background *b, float velocity, SDL_Surface *screen, mouvement M);
void scrolling_down_share(background *b, float velocity, SDL_Surface *screen, mouvement M);
void init_Mouvement(mouvement *M);
void init_player(player *p);
void display_player(player *p,SDL_Surface *screen);
void animateBackground(background *b);

#endif
