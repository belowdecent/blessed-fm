#include "SDL_render.h"
#include <stddef.h>

// Create a hash table of char[255] to SDL_Texture*
// Text is either created if the table entry is missing or got from the hash map
