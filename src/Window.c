#include "Window.h"

SDL_HitTestResult windowHitTest(SDL_Window *win, const SDL_Point *area, void *data)
{
    return SDL_HITTEST_DRAGGABLE;
}

uint8_t initWindow(Window *window)
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);

    window->windowSDL = SDL_CreateWindow("GreenBruh",
                                         SDL_WINDOWPOS_CENTERED,
                                         SDL_WINDOWPOS_CENTERED,
                                         600,
                                         300,
                                         SDL_WINDOW_HIDDEN);
    if (window->windowSDL == NULL)
    {
        fprintf(stderr, "Error initializing SDL window: %s\n", SDL_GetError());
        return false;
    }
    window->rendererSDL = SDL_CreateRenderer(window->windowSDL, -1, SDL_RENDERER_ACCELERATED);
    if (window->rendererSDL == NULL)
    {
        fprintf(stderr, "Error initializing SDL renderer: %s\n", SDL_GetError());
        return false;
    }

    SDL_SetWindowOpacity(window->windowSDL, 0.5f);
    SDL_SetWindowBordered(window->windowSDL, false);
    SDL_SetWindowHitTest(window->windowSDL, windowHitTest, NULL);
    SDL_ShowWindow(window->windowSDL);

    return true;
}

void destroyWindow(Window *window)
{
    SDL_DestroyRenderer(window->rendererSDL);
    window->rendererSDL = NULL;
    SDL_DestroyWindow(window->windowSDL);
    window->windowSDL = NULL;
}