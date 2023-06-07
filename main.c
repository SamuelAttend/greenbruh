#include <stdio.h>
#include <stdbool.h>
#include "SDL2/SDL.h"
#include "Window.h"

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "Error initializing SDL: %d\n", SDL_GetError());
        return 1;
    }

    Window window;
    initWindow(&window);

    bool quit = false;
    while (!quit)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        }
    }

    destroyWindow(&window);
    SDL_Quit();

    return 0;
}