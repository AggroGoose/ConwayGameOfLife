void CellMap::SetCell(unsigned int x, unsigned int y) {
    unsigned char* cell_ptr = cells + (y * w + x);
    int xleft, xright, yabove, ybelow;

    *(cell_ptr) |= 0x01; // Set the first bit as 1, 'on'

    if (x == 0)
        xleft = w - 1;
    else
        xleft = -1;
    if (x == (w - 1))
        xright = -(w - 1);
    else
        xright = 1;
    if (y == 0)
        yabove = length - w;
    else
        yabove = -w;
    if (y == (h - 1))
        ybelow = -(length - w);
    else
        ybelow = w;

    *(cell_ptr + yabove + xleft) += 0x02;
    *(cell_ptr + yabove) += 0x02;
    *(cell_ptr + yabove + xright) += 0x02;
    *(cell_ptr + xleft) += 0x02;
    *(cell_ptr + xright) += 0x02;
    *(cell_ptr + ybelow + xleft) += 0x02;
    *(cell_ptr + ybelow) += 0x02;
    *(cell_ptr + ybelow + xright) += 0x02;
}