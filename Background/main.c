#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "background.h"


int main()
{
    SDL_Surface *screen,*image;
    mouvement M;
    background b;
    int frame;
    player p ;
    int continuer = 1;    
    Mix_Music *music;


///////////////////// music /////////////////////////
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	music = Mix_LoadMUS("music.mp3") ;
	Mix_PlayMusic(music,-1);
//////////////////////////////



    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);//// init SDL 
    SDL_WM_SetIcon(IMG_Load("icon.png"), NULL);/// icon image
    screen = SDL_SetVideoMode(1200, 1000, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);//// window creation 
    SDL_WM_SetCaption("SPACE INVADERS", NULL); /// window name 


    init_Mouvement(&M); // call init and mouvements
    initBack(&b);// call fn back 1 2 
init_player(&p);



                                 //////event//////////////////
    SDL_Event event;
    SDL_EnableKeyRepeat(1, 0);//curseur continue
    while (continuer)

    {
displayBack(screen,&b);
display_player(&p,screen);

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:

                continuer = 0;
                break;

            case SDL_KEYDOWN:

                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    continuer = 0;
                    break;

                case SDLK_RIGHT:
                    M.right = 1;
                    break;

                case SDLK_LEFT:
                    M.left = 1;
                    break;

                case SDLK_d:
                    M.d = 1;
                    break;

                case SDLK_q:
                    M.q = 1;
                    break;

                case SDLK_DOWN:
                    M.down = 1;
                    break;

                case SDLK_UP:
                    M.up = 1;
                    break;

                case SDLK_z:
                    M.z = 1;
                    break;

                case SDLK_s:
                    M.s = 1;
                    break;
                }
                break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {

                case SDLK_RIGHT:
                    M.right = 0;
                    break;

                case SDLK_LEFT:
                    M.left = 0;
                    break;

                case SDLK_d:
                    M.d = 0;
                    break;

                case SDLK_q:
                    M.q = 0;
                    break;

                case SDLK_DOWN:
                    M.down = 0;
                    break;

                case SDLK_UP:
                    M.up = 0;
                    break;

                case SDLK_z:
                    M.z = 0;
                    break;

                case SDLK_s:
                    M.s = 0;
                    break;

                }
                break;
            }
//////////////////////////////////////////////////////////////////




//////////////////////////// call scrolling ////////////////////////// 
                scrolling_right(&b, 4, screen, M);
		scrolling_right_share(&b, 4,screen,M);
                scrolling_left(&b, 4, screen, M);
		scrolling_left_share(&b, 4,screen,M);
		scrolling_up(&b, 4,screen,M);
		scrolling_up_share(&b, 4,screen,M);
		scrolling_down(&b, 4,screen,M);
		scrolling_down_share(&b, 4,screen,M);
////////////////////
                animateBackground(&b);


        }

	displayBack_share(screen,&b);/// call display and screen share
        SDL_Flip(screen);// refresh screen

    }

    SDL_FreeSurface(screen);
    SDL_FreeSurface(image);
    Mix_FreeMusic(music); 
    SDL_Quit();
    return 0;
}
