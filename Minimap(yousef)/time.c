#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"timer.h"
#define SCREEN_W 1000
#define SCREEN_H 800

void initializerTime(Time *time)
{
	time->font = TTF_OpenFont("Trajan Pro.ttf",50);
	time->time = 0;
	sprintf(time->timeString,"00:00");
	SDL_Color color = {255,255,255};
	time->msg = TTF_RenderText_Solid(time->font,time->timeString,color);
        time->positiontemps.x=100;
        time->positiontemps.y=50;
}

void displayTime(Time *time, SDL_Surface *screen)
{
	SDL_Color color = {255,255,255};
	time->time++;
	if(time->time % 60 == 0){
		sprintf(time->timeString,"%02d:%02d\n",time->time/60/60,(time->time/60)%60);
		time->msg = TTF_RenderText_Solid(time->font,time->timeString,color);
	}
	SDL_BlitSurface(time->msg,NULL,screen,&(time->positiontemps));
}
