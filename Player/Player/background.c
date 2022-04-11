#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "player.h"
#include "background.h"
#include "image.h"

//Background functions
	void initBackground(background *b, const char *file)
	{
	 b->img=IMG_Load(file);
	 if(b->img==NULL)
	 {
	  return ;
	 }
	 b->pos.x=0;
	 b->pos.y=0;
	}

	void displayBackground(background b, SDL_Surface *screen)
	{
	 SDL_BlitSurface(b.img,NULL,screen,&b.pos);
	}

	void freeBackground(background b)
	{
	 SDL_FreeSurface(b.img);
	}

