#include "enigma.h"

void initimages(image b[],image g[],image r[],image repp[])

{

repp[0].img=IMG_Load("win.jpg");
repp[1].img=IMG_Load("fail.jpg");

repp[0].pos.x=0;
repp[0].pos.y=0;
repp[1].pos.x=0;
repp[1].pos.y=0;
   


    b[0].img=IMG_Load("b.png");
    b[1].img=IMG_Load("b1.png");

    b[0].pos.x=100;
    b[0].pos.y=180;
    b[1].pos.x=100;
    b[1].pos.y=180;


    g[0].img=IMG_Load("g.png");
    g[1].img=IMG_Load("g1.png");
    g[0].pos.x=200;
    g[0].pos.y=280;
    g[1].pos.x=200;
    g[1].pos.y=280;

    r[0].img=IMG_Load("r.png");
    r[1].img=IMG_Load("r1.png");

    r[0].pos.x=300;
    r[0].pos.y=380;

    r[1].pos.x=300;
    r[1].pos.y=380;
}

void initenigma(enigma *e, char *filename)

{

    int MAX = 3, MIN=1;
    srand(time(0));
    e->choice_question=(rand() % (MAX - MIN + 1)) +MIN;

    SDL_Color black= {0,0,0};
    TTF_Font *police;

    police = TTF_OpenFont("Authentica.ttf", 30);

    FILE *f;
    int nb=0;
    f=fopen(filename, "r");
    if(f!=NULL)
    {
        while((fscanf(f,"%s %s %s %s  %d\n",e->question,e->rep1,e->rep2,e->rep3,&(e->rp))!=EOF)&&(nb!=e->choice_question))
        {
            nb++;
        }
    }
    fclose(f);


    e->questions= TTF_RenderText_Solid (police,e->question,black);

    e->reps[1]= TTF_RenderText_Blended (police,e->rep1,black);
    e->reps[2]= TTF_RenderText_Blended (police,e->rep2,black);
    e->reps[3]= TTF_RenderText_Blended (police,e->rep3,black);
    e->resolu=e->rp;

    e->posRep[1].x=200;
    e->posRep[1].y=200;
    e->posRep[2].x=300;
    e->posRep[2].y=300;
    e->posRep[3].x=400;
    e->posRep[3].y=400;


    e->posQuestion.x=50;
    e->posQuestion.y=50;


}


void displayenigma(enigma *e, SDL_Surface *screen)

{

    SDL_BlitSurface(e->questions,NULL,screen,&(e->posQuestion));
    SDL_BlitSurface(e->reps[1],NULL,screen,&(e->posRep[1]));
    SDL_BlitSurface(e->reps[2],NULL,screen,&(e->posRep[2]));
    SDL_BlitSurface(e->reps[3],NULL,screen,&(e->posRep[3]));

}

void displayimages(image a, SDL_Surface *screen)

{
    SDL_BlitSurface(a.img,NULL,screen,&a.pos);
}

void animate (enigma *e)
{
    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Surface *screen;
    SDL_Surface *back=NULL;
    SDL_Rect pos;



    int done=1,done1=1,pink=0,green=0,blue=0;


    SDL_Event event;
    int rep;
    screen=SDL_SetVideoMode(1000,500,32,SDL_HWSURFACE  );
    if(!screen)
    {
        printf("Unable de set 600x300 video: %s\n", SDL_GetError());
    }
    back= IMG_Load("background.png");
    pos.x=0;
    pos.y=0;

    SDL_BlitSurface(back,NULL,screen,&pos);





    image b[2],r[2],g[2],repp[2];
    initimages(b,g,r,repp);
    initenigma(e,"enigma.txt");
    while(done1)
    {
    while(done)
    {


        displayimages(b[blue], screen);
        displayimages(g[green], screen);
        displayimages(r[pink], screen);
        displayenigma(e,screen);
        SDL_Flip(screen);

        SDL_PollEvent(&event);


        switch(event.type)
        {
        case SDL_QUIT:
        {
            done=0;
        }
        break;




        case SDL_KEYDOWN:
        {
            if(event.key.keysym.sym == SDLK_ESCAPE)
            {
                done = 0;
            }
            blue=0;
            green=0;
            pink=0;
            switch(event.key.keysym.sym)
            {
            case SDLK_a:
                rep=1;
                blue=1;

                break;
            
            case SDLK_b:
                green=1;

                rep=2;
                break;
            case SDLK_c:
                pink=1;
                rep=3;
                break;
                 case SDLK_SPACE:
                        done=0;
                break;
            }

            break;
        }
        case SDL_MOUSEMOTION:
           
blue=0;
green=0;
pink=0;

            if (event.motion.x>100 && event.motion.y>180 && event.motion.x<400 && event.motion.y<280 )
            {
                            rep=1;
                blue=1;
            }
            if (event.motion.x>200 && event.motion.y>280 && event.motion.x<500 && event.motion.y<380 )
            {
                            rep=2;
                green=1;
            }
            if (event.motion.x>300 && event.motion.y>380 && event.motion.x<600 && event.motion.y<480 )
            {                rep=3;
                pink=1;
            }
            if (event.motion.x>100 && event.motion.y>180 && event.motion.x<400 && event.motion.y<280 )
            {
                blue=1;
            }
             case SDL_MOUSEBUTTONDOWN:
            if (event.button.button==SDL_BUTTON_LEFT)
            {
                if ((blue==1)||(green==1)||(pink==1))
               
done=0;
                }
           
        }


    }

            SDL_PollEvent(&event);
    if(event.key.keysym.sym == SDLK_ESCAPE)
            {
                done1= 0;
            }
if(rep==e->rp){
        displayimages(repp[0], screen);
      }
else {
        displayimages(repp[1], screen);
}
                   SDL_Flip(screen);
}}
