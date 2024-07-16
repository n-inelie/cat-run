#include "land.h"
#include <ncurses.h>
#include <stdlib.h>

Land *LandCreate(uint8_t size) {
    Land *l = malloc(sizeof(*l));
    l->size = size;
    l->terrain = calloc(size, sizeof(uint8_t));
    return l;
}

void LandDestroy(Land *l) {
    free(l->terrain);
    free(l);
}

void drawLand(Land l, Box b, uint8_t base_height) {
    uint8_t zero_level = b.p.y + b.height - (base_height + 2);
    for (uint8_t i = 0; i < b.width - 1; i += 3) {
        uint8_t prev_level = l.terrain[i / 3 - 1];
        uint8_t current_level = l.terrain[i / 3];
        mvaddch(zero_level - current_level, b.p.x + i + 1, ACS_HLINE);
        mvaddch(zero_level - current_level, b.p.x + i + 2, ACS_HLINE);

        if (prev_level > current_level) {
            mvaddch(zero_level - current_level, b.p.x + i, ACS_LLCORNER);
            mvvline(zero_level - prev_level + 1, b.p.x + i, ACS_VLINE,
                    prev_level - current_level - 1);
            mvaddch(zero_level - prev_level, b.p.x + i, ACS_URCORNER);
        } else if (prev_level < current_level) {
            mvaddch(zero_level - current_level, b.p.x + i, ACS_ULCORNER);
            mvvline(zero_level - current_level + 1, b.p.x + i, ACS_VLINE,
                    current_level - prev_level - 1);
            mvaddch(zero_level - prev_level, b.p.x + i, ACS_LRCORNER);
        } else {
            mvaddch(zero_level - current_level, b.p.x + i, ACS_HLINE);
        }
    }
    mvaddch(zero_level, b.p.x, ACS_VLINE);
    mvaddch(zero_level, b.p.x + b.width - 1, ACS_VLINE);
}
