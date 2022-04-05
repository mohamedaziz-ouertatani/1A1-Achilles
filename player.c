#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "player.h"
#include "background.h"
#include "image.h"
#include "text.h"
#include "obstacle.h"

//player functions
	void initPlayer(player *p, const char *file, int X, int Y)
	{
	 p->img=IMG_Load(file);
	 if(p->img==NULL)
	 {
	  return ;
	 }
	 p->pos.x=X;
	 p->pos.y=Y;
	}
	void displayPlayer(player p, SDL_Surface * screen)
	{
	 SDL_BlitSurface(p.img,NULL,screen,&p.pos);
	}
	void freePlayer(player p)
	{
	 SDL_FreeSurface(p.img);
	}
		/*player motion*/
	void front(player *p,const char *file)
	{
	 p->img=IMG_Load(file);
	 p->pos.x+=30;
	}
	void back(player *p,const char *file)
	{
	 p->img=IMG_Load(file);
	 p->pos.x-=30	;
	}
	void jump(player *p,int *timeForJump)
	{
	 if(*timeForJump <= 10)
	  p->pos.y-=12;
	 ++(*timeForJump);
	}
	void animePlayer (player* p)
	{
	 //...
	}

