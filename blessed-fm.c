#include "SDL_error.h"
#include "SDL_events.h"
#include "SDL_log.h"
#include "SDL_render.h"
#include "SDL_video.h"
#include <stdio.h>
#include <SDL.h>

static inline int init_error(char* message_fmt) {
	SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, message_fmt, SDL_GetError());
	return 1;
} 

static int initialize(
	SDL_Window** win,
	SDL_Renderer** renderer
) {
	if (SDL_Init(SDL_INIT_VIDEO)) 
		return init_error("Couldn't initialize SDL: %s");

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

	if (initialize(&win, &renderer))
		return 3;

	SDL_Event e;

	while (1) {
		SDL_PollEvent(&e);
		if (e.type == SDL_QUIT) {
			break;
		}

		SDL_SetRenderDrawColor(renderer, 0xFF, 0x15, 0xDD, 0xFF);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	SDL_Quit();

	return 0;
}
