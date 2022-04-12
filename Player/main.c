#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "player.h"
#include "background.h"
#include "image.h"

int main(int argc, char** argv)
{
 //Initializing SDL
 if(SDL_Init(SDL_INIT_VIDEO)!=0)
 {
  printf("Error: %s \n", SDL_GetError());
 }

 //Variables
 SDL_Surface *screen;
 SDL_Event event;
 background backG;
 Player p1;
 int right1=0,left1=0,up1=0,dir1=2;
 Uint32 dt;
 Uint32 t_prev;
 
 //create window
 screen=SDL_SetVideoMode( 1000,700,32, SDL_HWSURFACE | SDL_DOUBLEBUF );
 if(!screen)
 {
  printf("Unable create window: %s\n",SDL_GetError());
  return 1;
 }
 
 //initializing variables
 initBackground(&backG, "Sources/sunrise.jpg");
 initPlayer(&p1,"Sources/characterFront.png");

 while(1)
{
t_prev=SDL_GetTicks();
while(SDL_PollEvent(&event))
{
  if(event.type==SDL_KEYDOWN)
    if(event.key.keysym.sym==SDLK_ESCAPE)
       return 0;
      
  switch(event.type)
   {
     case SDL_QUIT:
       return 0;
       break;

     case SDL_KEYDOWN:
         switch(event.key.keysym.sym)
             {
                case SDLK_RIGHT:
                   right1=1;
                   break;
                case SDLK_LEFT:
                   left1=1;
                   break;
                case SDLK_UP:
                   up1=1;
                   break;
              }
              break;
     case SDL_KEYUP:
         switch(event.key.keysym.sym)
             {
                case SDLK_RIGHT:
                   right1=0;
                   dir1=1;
                   p1.speed=0;
                   break;
                case SDLK_LEFT:
                   left1=0;
                   dir1=0;
                   p1.speed=0;
                   break;
                case SDLK_UP:
                   up1=0;
                   break;
              }
              break;
    }
}
/*UPDATE*/
if (right1==1)
{
  p1.speed=10;
  p1.acceleration+=0.5;
  p1.dir=1;
}
if (left1==1)
{
  p1.speed=10;
  p1.acceleration+=0.5;
  p1.dir=0;
}
if (up1==1)
{
 jump(&p1);
}

movePlayer(&p1,dt);

animePlayer(&p1);

p1.acceleration-=0.3;

if(p1.acceleration<0) // min_acceleration for the player is 0
  p1.acceleration=0;
  
if(p1.acceleration>4) // max_acceleration for the player is 4
  p1.acceleration=4;

SDL_Delay(1);

dt=SDL_GetTicks()-t_prev; //dt=t2-t1

if ((p1.speed==0)&&(p1.acceleration==0)) //not moving 
   p1.dir=dir1;//MEMORIZATION OF THE DIRECTION OF THE PLAYER 1

p1.pos.y+=p1.speedV; 
p1.speedV+=10;
if (p1.pos.y>=430)
{
   p1.speedV=0; //THE PLAYER GO BACK DOWN ALONE
   p1.pos.y=430;
}

/*DISPLAY*/
 displayBackground( backG, screen);
 displayPlayer(p1,screen);

SDL_Flip(screen);
SDL_Delay(50);
}
 
 freeBackground(backG);
 freePlayer(p1);
  
 SDL_Quit();
}
