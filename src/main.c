#include <stdio.h>
#include <stdbool.h>
#include "SDL2/SDL.h"
#include "Window.h"
#include "SDL_ttf.h"

void renderText(
	char *text, int x, int y, SDL_Color color,
	SDL_Renderer *renderer, TTF_Font *font, SDL_Texture **texture, SDL_Rect *rect
) {

    SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
    *texture = SDL_CreateTextureFromSurface(renderer, surface);

    rect->x = x;
    rect->y = y;
    rect->w = surface->w;
    rect->h = surface->h;

    SDL_FreeSurface(surface);
}

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

	TTF_Init();
	TTF_Font* fnt = TTF_OpenFont("couriernew.ttf", 24);
	SDL_Texture* txtTex;
	SDL_Rect txtRect;

	renderText("TEXT\nTEXT", 0, 0, (SDL_Color) {255, 255, 255}, window.rendererSDL, fnt, &txtTex, &txtRect);

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

		SDL_RenderCopy(window.rendererSDL, txtTex, NULL, &txtRect);
		
        SDL_RenderPresent(window.rendererSDL);
    }

	SDL_DestroyTexture(txtTex);
    TTF_Quit();

    destroyWindow(&window);
    SDL_Quit();

    return EXIT_SUCCESS;
}