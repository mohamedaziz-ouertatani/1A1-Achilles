#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
typedef struct
{
  char question[100];
           char rep1[50];
           char rep2[50];
           char rep3[50];
           
           
           SDL_Surface *questions;
           SDL_Surface *reps[5];
          int choice_question;
           SDL_Rect posQuestion;
           SDL_Rect posRep[5];
           SDL_Rect pos,pos1;
           
  int resolu;
           int rp;
 
}enigma;

typedef struct
{
SDL_Rect pos;
SDL_Surface *img;
}image;

void initImages(image b[],image g[],image r[],image repp[]);
void diplayimages(image a, SDL_Surface *screen);
void InitEnigma(enigma *e,char *filename);
void displayEnigme(enigma *e,SDL_Surface *screen);
//int resolution_enigma(enigme e, SDL_Event event);
void animate (enigma *e);

#endif
