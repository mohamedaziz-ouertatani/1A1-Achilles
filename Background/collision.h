#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

SDL_Color GetPixel(SDL_Surface *pSurface , int x,int y);
int collision_parfaite_right(SDL_Surface *mask , SDL_Rect posjoueur );
int collision_parfaite_left(SDL_Surface *mask , SDL_Rect posjoueur );
int collision_parfaite_up(SDL_Surface *mask , SDL_Rect posjoueur );
int collision_parfaite_down(SDL_Surface *mask , SDL_Rect posjoueur );


#endif

