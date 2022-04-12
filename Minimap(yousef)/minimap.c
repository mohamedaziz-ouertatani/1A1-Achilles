#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include "minimap.h"
#include "player.h"
#include <time.h>
#include <SDL/SDL_ttf.h>

void init_minimap(minimap* mp){

  mp->mini_map =IMG_Load("minimap.png");
 mp->pos_minimap.x = 640;
 mp->pos_minimap.y = 50;


 mp->mini_hero = IMG_Load("mini_perso.png");
 mp->pos_minihero.x = 640;
 mp->pos_minihero.y = 130;

}

void blit_minimap(minimap mp,SDL_Surface *screen)
{

 SDL_BlitSurface(mp.mini_map,NULL,screen,&mp.pos_minimap);
 SDL_BlitSurface(mp.mini_hero,NULL,screen,&mp.pos_minihero);
}

void MAJMinimap(SDL_Rect pos_person, minimap *mp,SDL_Rect camera,int resize,int way){
    SDL_Rect tmp,tmp1;
    tmp1.x = ((pos_person).x*resize)/100;
    tmp1.y= ((pos_person).y*resize)/100;
    if((way==0)&&(mp->pos_minihero.y<=450)){

        mp->pos_minihero.x = 640 + tmp1.x;
}
      else{

          mp->pos_minihero.x = 640 + tmp1.x;

    }
}
void free_minimap(minimap mp)
{
SDL_FreeSurface(mp.mini_map);
SDL_FreeSurface(mp.mini_hero);
}
