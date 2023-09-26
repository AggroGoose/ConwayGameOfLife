#include <SDL.h>
#include <memory>
#include <ctime>

// SDL Window and Surface for pixel manipulation
SDL_Window* window = NULL;
SDL_Surface* surface = NULL;



// Width and height of cell size in pixels
unsigned int CELL_SIZE = 4;
unsigned  CELLMAP_WIDTH = 100;
unsigned CELLMAP_HEIGHT = 100;

// Screen length and width
unsigned int SCREEN_WIDTH = CELLMAP_WIDTH * CELL_SIZE;
unsigned int SCREEN_HEIGHT = CELLMAP_HEIGHT * CELL_SIZE;