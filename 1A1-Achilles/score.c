#include <SDL/SDL.h>
#include "score.h"
#include <SDL/SDL_image.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void initScore(Score *S){
  S->pos.x=1450;
  S->pos.y=50;
  S->Scolor.r=255;
  S->Scolor.g=255;
  S->Scolor.b=255;
  S->font=TTF_OpenFont("Trajan Pro.ttf",70);
}

void freeScore(Score S){
  SDL_FreeSurface(S.surfaceS);
}
void displayScore(Score S,SDL_Surface *screen,int x){
  char ch[10];
  sprintf(ch,"%d",x);
  S.surfaceS = TTF_RenderText_Solid(S.font,ch,S.Scolor);
  SDL_BlitSurface(S.surfaceS,NULL,screen,&S.pos);
}
void bestscore(char filename[],int *score1,char playername[]){
  FILE *f;
  Score s;
  int score,max=0;
  char name[15];

  f=fopen(filename,"a+");
  if(f==NULL){
    printf("error!\n");
  }
  else{
    while(!EOF){
    fscanf(f,"%s %d\n",name,score);
    if(score>max){
      max=score;
      playername=name;

    }
  }
  }
  (*score1)=max;

}
