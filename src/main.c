#include <stdio.h>
#include <stdbool.h>
#include "SDL2/SDL.h"
#include "Window.h"

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    Window window;
    if (!initWindow(&window))
    {
        SDL_Quit();
        return EXIT_FAILURE;
    }

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

        SDL_SetRenderDrawColor(window.rendererSDL, 173, 216, 230, 255);
        SDL_RenderClear(window.rendererSDL);
        SDL_RenderPresent(window.rendererSDL);
    }

    destroyWindow(&window);
    SDL_Quit();

    return EXIT_SUCCESS;
}