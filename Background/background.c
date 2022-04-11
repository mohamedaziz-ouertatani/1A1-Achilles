#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "background.h"
void init_player(player *p)

{
    p->pos_p.x=10;
    p->pos_p.y=140;
    p->im_player=IMG_Load("d1.png");
}
void display_player(player *p,SDL_Surface *screen)
{
    SDL_BlitSurface(p->im_player,NULL,screen,&p->pos_p);

}
void initBack(background *b)
{

    b->image = IMG_Load("bg.jpg"); /// change background image 

//// initialisation position background1
    b->positionbackground.x = 0;
    b->positionbackground.y = -10;
    b->positionbackground.w = 0;
    b->positionbackground.h = 0;


//// initialisation position camera 1
    b->camera1.x = 0;
    b->camera1.y = 0;
    b->camera1.w = 600;
    b->camera1.h = 500;


//// initialisation position background 2
    b->positionback_share.x = 600;
    b->positionback_share.y = -10;
    b->positionback_share.h = 0;
    b->positionback_share.w = 0;


//// initialisation position camera 2
    b->camera2.x = 0;
    b->camera2.y = 0;
    b->camera2.w = 600;
    b->camera2.h = 1000;


}



void displayBack(SDL_Surface *screen,background *b)
{

    SDL_BlitSurface(b->image, &b->camera1, screen, &b->positionbackground); /// blite de 1ere background

}


/*********************************************************************************/


void displayBack_share(SDL_Surface *screen,background *b)
{


    SDL_BlitSurface(b->image, &b->camera2, screen, &b->positionback_share);/// blite de 2eme background avec partage

}


/*********************************************************************************/


void scrolling_right(background *b, float velocity, SDL_Surface *screen, mouvement M)
{
    if (M.right == 1 )
    {
        if (b->camera1.x < 5000 - 530)
        {
            b->camera1.x += velocity;
        }
    }

}


/*********************************************************************************/


void scrolling_right_share(background *b, float velocity, SDL_Surface *screen, mouvement M)
{
    if (M.d == 1)
    {
        if (b->camera2.x < 5000 - 530)
        {
            b->camera2.x += velocity;
        }
    }
}


/*********************************************************************************/


void scrolling_left(background *b, float velocity, SDL_Surface *screen, mouvement M)
{

    if (M.left == 1)
    {
        if (b->camera1.x > 0)
        {
            b->camera1.x -= velocity;
        }
    }

}


/*********************************************************************************/


void scrolling_left_share(background *b, float velocity, SDL_Surface *screen, mouvement M)
{

    if (M.q == 1)
    {
        if (b->camera2.x > 0)
        {
            b->camera2.x -= velocity;
        }
    }

}


/*********************************************************************************/


void scrolling_up(background *b, float velocity, SDL_Surface *screen, mouvement M)
{

    if (M.up == 1)
    {
        if (b->camera1.y > 0)
        {
            b->camera1.y -= velocity;
        }
    }

}


/*********************************************************************************/


void scrolling_up_share(background *b, float velocity, SDL_Surface *screen, mouvement M)
{

    if (M.z == 1)
    {
        if (b->camera2.y > 0)
        {
            b->camera2.y -= velocity;
        }
    }

}


/*********************************************************************************/


void scrolling_down(background *b, float velocity, SDL_Surface *screen, mouvement M)
{
    if (M.down == 1 )
    {
        if (b->camera1.y < 600 - 528)
        {
            b->camera1.y += velocity;
        }
    }

}


/*********************************************************************************/


void scrolling_down_share(background *b, float velocity, SDL_Surface *screen, mouvement M)
{
    if (M.s == 1 )
    {
        if (b->camera2.y < 600 - 528)
        {
            b->camera2.y += velocity;
        }
    }

}


/*********************************************************************************/


///// initialisation des deplacement
void init_Mouvement(mouvement *M)
{
    M->left = 0;
    M->right = 0;

    M->q = 0;
    M->d = 0;

}




void animateBackground(background * b){
    b->pos_sp.x += 100; // += b->pos_sp.w
    if (b->pos_sp.x==400)
    {
        b->pos_sp.x=0;
    }
    b->pos_sp.y = b->direction * 100 ; //   b->pos_sp.y = b->direction * b->pos_sp.h
}




/*void animateBackground(background *b)
{   
    if(b->frame==3)
        b->frame=0;
    else b->frame++;
}*/
