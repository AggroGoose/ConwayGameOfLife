void DrawCell(unsigned int x, unsigned int y, unsigned int colour) {
    Uint8* pixel_ptr = (Uint8*)surface->pixels + (y * CELL_SIZE * SCREEN_WIDTH + x * CELL_SIZE) * 4;

    for (unsigned int i = 0; i < CELL_SIZE; i++) {
        for (unsigned int j = 0; j < CELL_SIZE; j++) {
            *(pixel_ptr + j * 4) = colour;
            *(pixel_ptr + j * 4 + 1) = colour;
            *(pixel_ptr + j * 4 + 2) = colour;
        }

        pixel_ptr += SCREEN_WIDTH * 4;
    }
}