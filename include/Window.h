#pragma once
#include "SDL2/SDL.h"
#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    SDL_Window *windowSDL;
    SDL_Renderer *rendererSDL;
} Window;

uint8_t initWindow(Window *window);
void destroyWindow(Window *window);