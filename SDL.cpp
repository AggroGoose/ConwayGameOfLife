int main(int argc, char* argv[]) {
    // SDL Boilerplate
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Conway's game of life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    surface = SDL_GetWindowSurface(window);
    // SDL Event Handler
    SDL_Event e;

    // Rendering Loop
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0)
            if (e.type == SDL_QUIT) quit == true;
        SDL_Delay(1000);
        // Update frame buffer
        SDL_UpdateWindowSurface(window);
    }

    // Clean up SDL
    SDL_DestroyWindow(window);
    // Quit
    SDL_Quit();
    return 0;
}