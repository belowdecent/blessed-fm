#include "core.h"
#include "SDL_render.h"
#include "SDL_surface.h"
#include "SDL_ttf.h"

static SDL_Renderer* text_renderer;

int BLSD_TextInit(SDL_Renderer* renderer) {
	text_renderer = renderer;
	return 0;
}

BLSD_Text BLSD_TextTexture(
	TTF_Font* font, 
	const char* text, 
	SDL_Color color, 
	BLSD_TextRenderStyle style
) {
	SDL_Surface* tmp = TTF_RenderUTF8_Blended(font, text, color);
	BLSD_Text text_obj = {
		.rect = {
			.w = tmp->w, 
			.h = tmp->h
		},
		.texture = SDL_CreateTextureFromSurface(text_renderer, tmp)
	};

	SDL_FreeSurface(tmp);
	return text_obj;
}
