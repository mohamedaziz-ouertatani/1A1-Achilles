#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "player.h"
#include "background.h"
#include "image.h"

void initPlayer(Player *p, const char *file)
{
 p->image=IMG_Load(file);
 if(p->image==NULL)
 {
  return ;
 }
 p->pos.x=450;
 p->pos.y=430;

 p->dir=1; //right 
 
 p->acceleration=0;
 p->speed=0;
 p->speedV=0;
}

void displayPlayer (Player p,SDL_Surface *screen)
{ 
  SDL_BlitSurface (p.image,NULL,screen,&p.pos);
}

void movePlayer (Player *p,int dt)
{ 
 double dx;
 dx=0.5*p->acceleration*dt*dt+p->speed*dt;
 if (p->dir==1)
   {
     p->pos.x+=dx;
    }
else if (p->dir==0)
    {
      p->pos.x-=dx;
     }
}

void jump (Player *p)
{ 
 if (p->pos.y==430)
   {
     p->speedV=-50;
    }
}

	void freePlayer(Player p)
	{
	 SDL_FreeSurface(p.image);
	}
	
void animePlayer(Player *p)
{
 if(p->dir==1)
 {
  p->image=IMG_Load("Sources/characterFront.png");
 }
 else if(p->dir==0)
 {
  p->image=IMG_Load("Sources/characterBack.png");
 }
}
