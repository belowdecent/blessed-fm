#ifndef __BLSD_RENDER_CORE
#define __BLSD_RENDER_CORE

#include "SDL_render.h"
#include <SDL.h>

typedef struct BLSD_DisplayTreeNode {
	SDL_Texture* texture;
	SDL_Rect rect;

	struct BLSD_DisplayTreeNode* parent;
	struct BLSD_DisplayTreeNode* children;
	int count;
} BLSD_DisplayTreeNode;

typedef struct BLSD_DisplayTree {
	SDL_Renderer* renderer;
	BLSD_DisplayTreeNode root;
} BLSD_DisplayTree;

#endif // !__BLSD_RENDER_CORE
