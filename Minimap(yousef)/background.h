#ifndef Background_H
#define Background_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
/*struct Background{
  SDL_Surface *back;
  SDL_Rect pos1;
  SDL_Rect pos2;
};
typedef struct Background Background;*/
typedef struct{
 SDL_Surface *back;
  SDL_Rect pos1;
  SDL_Rect pos2;
}Background;

void initback(Background *b);
void displayback(Background b,SDL_Surface *screen);
void free_background(Background b);

#endif
