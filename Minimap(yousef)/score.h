#ifndef Score_H
#define Score_H
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
typedef struct{
  SDL_Rect pos;
  TTF_Font *font;
  SDL_Surface *surfaceS;
  SDL_Color Scolor;
}Score;

void initScore(Score *S);
void freeScore(Score S);
void displayScore(Score S,SDL_Surface *screen,int x);
void bestscore(char filename[],int *score,char playername[]);
#endif
