#include <SDL.h>
#include <SDL_ttf.h>

typedef struct BLSD_Text {
	SDL_Rect rect;
	SDL_Texture* texture;
} BLSD_Text;

typedef enum BLSD_TextRenderStyle {
	BLSD_TEXT_BLENDED,
	BLSD_TEXT_SOLID
} BLSD_TextRenderStyle;

int BLSD_TextInit(SDL_Renderer* renderer);
BLSD_Text BLSD_TextTexture(
	TTF_Font* font, 
	const char* text, 
	SDL_Color color, 
	BLSD_TextRenderStyle style
);
