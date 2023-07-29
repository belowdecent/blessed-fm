#include "SDL_error.h"
#include "SDL_events.h"
#include "SDL_log.h"
#include "SDL_render.h"
#include "SDL_surface.h"
#include "SDL_video.h"
#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>

static inline int init_error(const char* message_fmt) {
	SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, message_fmt, SDL_GetError());
	return 1;
} 

static int initialize(
	SDL_Window** win,
	SDL_Renderer** renderer
) {
	if (SDL_Init(SDL_INIT_VIDEO)) 
		return init_error("Couldn't initialize SDL: %s");

	if (TTF_Init()) {
		return init_error("Couldn't initialize SDL_ttf: %s");
	}

	*win = SDL_CreateWindow(
		"Blessed FM", 
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
		640, 480,
		SDL_WINDOW_RESIZABLE
	);

	if (*win == NULL)
		return init_error("Couldn't create window: %s");

	*renderer = SDL_CreateRenderer(*win, -1, SDL_RENDERER_PRESENTVSYNC);

	if (*renderer == NULL) {
		return init_error("Couldn't create renderer: %s");
	}

	return 0;
}

int main(void) {
	SDL_Window* win;
	SDL_Renderer* renderer;

	if (initialize(&win, &renderer)) {
		SDL_Quit();
		return 3;
	}

	SDL_Color text_color = {
		.r = 15, 
		.g = 20, 
		.b = 30, 
	};

	char* text = "Либерализм";
	TTF_Font* font = TTF_OpenFont("assets/font.ttf", 36);
	SDL_Surface* text_surface = TTF_RenderUTF8_Blended(font, text, text_color);
	SDL_Rect text_rect = {
		.x = 0, 
		.y = 0, 
		.w = text_surface->w, 
		.h = text_surface->h
	};

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, text_surface);


	SDL_Event e;

	while (1) {
		SDL_PollEvent(&e);
		if (e.type == SDL_QUIT) {
			break;
		}

		SDL_SetRenderDrawColor(renderer, 0xFF, 0x15, 0xDD, 0xFF);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, &text_rect);
		SDL_RenderPresent(renderer);
	}
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	TTF_Quit();
	SDL_Quit();

	return 0;
}
