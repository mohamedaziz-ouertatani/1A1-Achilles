#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "player.h"
#include "background.h"
#include "image.h"

//Image functions
	void initImage(image *i, const char *file, int X, int Y)
	{
	i->img=IMG_Load(file);
	 if(i->img==NULL)
	 {
	  return ;
	 }
	 i->pos.x=X;
	 i->pos.y=Y;
	}
	void displayImage(image i, SDL_Surface *screen)
	{
	 SDL_BlitSurface(i.img,NULL,screen,&i.pos);
	}
	void freeImage(image i)
	{
	 SDL_FreeSurface(i.img); 
	}

