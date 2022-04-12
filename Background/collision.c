#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "collision.h"




SDL_Color GetPixel(SDL_Surface *pSurface ,int x,int y)
{SDL_Color color;
Uint32 col=0;
char *pPosition = (char *) pSurface -> pixels;
pPosition+=(pSurface->pitch *y);
pPosition+=(pSurface ->format->BytesPerPixel *x);
memcpy (&col,pPosition,pSurface ->format ->BytesPerPixel);

SDL_GetRGB(col,pSurface -> format,&color.r ,&color.g ,&color.b);
return (color);
}
int collision_parfaite_right(SDL_Surface *mask , SDL_Rect posjoueur )
{  SDL_Color col,colp;
SDL_Rect pos[8];
int collision = 0;
int i,w,h;
col.r=0;
col.g=0;
col.b=0;
w=100;
h=100;





/*pos[3].x = posjoueur.x + w/2;
pos[3].y = posjoueur.y;*/
/*pos[4].x = posjoueur.x+ w /2;
pos[4].y = posjoueur.y +h;*/
pos[5].x = posjoueur.x +w;
pos[5].y = posjoueur.y;
pos[6].x = posjoueur.x +w;
pos[6].y = posjoueur.y+ h/2;
pos[7].x = posjoueur.x +w;
pos[7].y = posjoueur.y +h;
for (i =5;(i < 8)&&(collision == 0); i++)
{
colp = GetPixel(mask,pos[i].x ,pos[i].y);
if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))
collision = 1;}
return (collision);
}
int collision_parfaite_left(SDL_Surface *mask, SDL_Rect posjoueur)
{
SDL_Color col,colp;
SDL_Rect pos[8];
int collision = 0;
int i,w,h;
col.r=0;
col.g=0;
col.b=0;


w=100;
h=100;


pos[0].x = posjoueur.x;
pos[0].y = posjoueur.y;
pos[1].x = posjoueur.x;
pos[1].y = posjoueur.y + h /2;
pos[2].x = posjoueur.x;
pos[2].y = posjoueur.y + h;
//pos[3].x = posjoueur.x + w/2;
//pos[3].y = posjoueur.y;
//pos[4].x = posjoueur.x+ w /2;
//pos[4].y = posjoueur.y +h;

for (i =0;(i < 3)&&(collision == 0); i++)
{
col = GetPixel(mask,pos[i].x ,pos[i].y);
if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))
collision = 1;}
return (collision);
}


int collision_parfaite_up(SDL_Surface *mask, SDL_Rect posjoueur)
{
SDL_Color col,colp;
SDL_Rect pos[8];
int collision = 0;
int i,w,h;
col.r=0;
col.g=0;
col.b=0;


w=100;
h=100;


/*pos[0].x = posjoueur.x;
pos[0].y = posjoueur.y;
pos[1].x = posjoueur.x;
pos[1].y = posjoueur.y + h /2;
pos[2].x = posjoueur.x;
pos[2].y = posjoueur.y + h;*/
pos[3].x = posjoueur.x + w/2;
pos[3].y = posjoueur.y;
//pos[4].x = posjoueur.x+ w /2;
//pos[4].y = posjoueur.y +h;

for (i =3;(i < 4)&&(collision == 0); i++)
{
col = GetPixel(mask,pos[i].x ,pos[i].y);
if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))
collision = 1;}
return (collision);
}

int collision_parfaite_down(SDL_Surface *mask, SDL_Rect posjoueur)
{
SDL_Color col,colp;
SDL_Rect pos[8];
int collision = 0;
int i,w,h;
col.r=0;
col.g=0;
col.b=0;


w=100;
h=100;


/*pos[0].x = posjoueur.x;
pos[0].y = posjoueur.y;
pos[1].x = posjoueur.x;
pos[1].y = posjoueur.y + h /2;
pos[2].x = posjoueur.x;
pos[2].y = posjoueur.y + h;*/
//pos[3].x = posjoueur.x + w/2;
//pos[3].y = posjoueur.y;
pos[4].x = posjoueur.x+ w /2;
pos[4].y = posjoueur.y +h;

for (i =4;(i < 5)&&(collision == 0); i++)
{
col = GetPixel(mask,pos[i].x ,pos[i].y);
if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))
collision = 1;}
return (collision);
}

