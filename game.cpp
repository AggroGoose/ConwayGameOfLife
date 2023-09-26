#include "screen.h"

const int GAME_WIDTH = 640;
const int GAME_HEIGHT = 480;

bool isAlive(std::array<std::array<int, GAME_HEIGHT>, GAME_WIDTH>& game, const int x, const int y) {
	int alive = 0;
	//Test Left Side if not at x = 0
	if (x > 0 && game[x - 1][y] == 1) alive += 1;
	//Test Right Side if not at x == GAME_WIDTH
	if (x < GAME_WIDTH && game[x + 1][y] == 1) alive += 1;
	//Test Top Side if not at y = 0
	if (y > 0 && game[x][y - 1] == 1) alive += 1;
	//Test Bottom Side if not at y == GAME_HEIGHT
	if (y < GAME_HEIGHT && game[x][y + 1] == 1) alive += 1;

	//Testing diagonals
	//Testing Top Left
	if (x > 0 && y > 0 && game[x - 1][y - 1] == 1) alive += 1;
	//Testing Top Right
	if (x < GAME_WIDTH && y > 0 && game[x + 1][y - 1] == 1) alive += 1;
	//Testing Bottom Left
	if (x > 0 && y < GAME_HEIGHT && game[x - 1][y + 1] == 1) alive += 1;
	//Testing Bottom Right
	if (x < GAME_WIDTH && y < GAME_HEIGHT && game[x + 1][y + 1] == 1) alive += 1;

	// live and fewer than 2 die
	if (game[x][y] == 1 && alive < 2) return false;
	//alive and 2 or 3 then live
	if (game[x][y] == 1 && (alive == 2 || alive == 3)) return true;
	//If dead but 3 alive, come to life
	if (game[x][y] == 0 && alive == 3) return true;
	return false;
}

int main() {
	G screen;
	std::array<std::array<int, GAME_HEIGHT>, GAME_WIDTH> display {};
	std::array<std::array<int, GAME_HEIGHT>, GAME_WIDTH> swap {};

	//Create random points
	//
	for (auto& row : display)
		std::generate(row.begin(), row.end(), []() { return rand() % 10 == 0 ? 1 : 0; });

	while (true) {
		// Check for alive points
		//
		for (int i = 0; i < GAME_WIDTH; ++i) {
			for (int k = 0; k < GAME_HEIGHT; ++k) {
				swap[i][k] = isAlive(display, i, k) ? 1 : 0;
			}
		}

		//Draw
		//
		for (int i = 0; i < GAME_WIDTH; ++i) {
			for (int k = 0; k < GAME_HEIGHT; ++k) {
				if (swap[i][k]) {
					screen.drawpixel(i, k);
				}
			}
		}

		//Swap buffers
		//
		std::copy(swap.begin(), swap.end(), display.begin());

		// Display to screen
		//
		screen.update();
		SDL_Delay(20);
		screen.input();
		screen.clearpixels();
	}

}