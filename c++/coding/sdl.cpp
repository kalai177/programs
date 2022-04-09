#include<SDL2/SDL.h>
int main()
{
    if(SDL_Init(SDL_INIT_VIDEO)==-1){
        printf("could not initialize SDL: %s.\n",SDL_GetError());
    }
    SDL_Quit();
    return 0;
}