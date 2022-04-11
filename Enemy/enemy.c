#include "enemy.h"

void initEnemy(Enemy *e) {
    e->sprite=IMG_Load("enemie.png");
    e->pos.y=400;
    e->pos.x=600;

    e->direction=0;
    e->pos_sp.x=0;
    e->pos_sp.y=0;
    e->pos_sp.h=100;
    e->pos_sp.w=100;

}


void displayEnemy(Enemy e, SDL_Surface * screen){
    SDL_BlitSurface(e.sprite , &e.pos_sp , screen , &e.pos) ;
}

void animateEnemy( Enemy * e){
    e->pos_sp.x += 100; // += e->pos_sp.w
    if (e->pos_sp.x==400)
    {
        e->pos_sp.x=0;
    }
    e->pos_sp.y = e->direction * 100 ; //   e->pos_sp.y = e->direction * e->pos_sp.h
}

void move( Enemy * e){
    int Xmin =500 , Xmax= 800;
    if (e->direction==0)
    {
        e->pos.x += 10;
    }
    else if (e->direction==1)
    {
        e->pos.x -= 10;
    }



    if (e->pos.x < Xmin)
    {
        e->direction = 0;
    }
    if (e->pos.x > Xmax)
    {
        e->direction = 1;
    }
}



int collision(SDL_Rect E, SDL_Rect p) {
  int collision;
  if (((p.x + p.w) < E.x) || (p.x > (E.x + E.w)) || ((p.y + p.h) < E.y) || (p.y > (E.y + E.h)))
  {
    collision = 0;
  } else {
    collision = 1;
  }
  return collision;
}


