#include "Window.h"

uint8_t initWindow(Window *window)
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);

    window->windowSDL = SDL_CreateWindow("GreenBruh",
                                         SDL_WINDOWPOS_CENTERED,
                                         SDL_WINDOWPOS_CENTERED,
                                         600,
                                         300,
                                         SDL_WINDOW_SHOWN);
    if (window->windowSDL == NULL)
    {
        fprintf(stderr, "Error initializing SDL window: %d\n", SDL_GetError());
    }
    window->rendererSDL = SDL_CreateRenderer(window->windowSDL, -1, SDL_RENDERER_ACCELERATED);
    if (window->rendererSDL == NULL)
    {
        fprintf(stderr, "Error initializing SDL renderer: %d\n", SDL_GetError());
    }

    SDL_SetWindowOpacity(window->windowSDL, 0.5f);
}

void destroyWindow(Window *window)
{
    SDL_DestroyRenderer(window->rendererSDL);
    window->rendererSDL = NULL;
    SDL_DestroyWindow(window->windowSDL);
    window->windowSDL = NULL;
}