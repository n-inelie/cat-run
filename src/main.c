#include "box.h"
#include "land.h"
#include <ncurses.h>
#include <string.h>

int main(void) {
    initscr();
    raw();
    noecho();

    clear();

    Box space = {ORIGIN, COLS, LINES};
    drawBox(space);

    Land *l = LandCreate(space.width / 3);

    uint8_t tower_pos = 5;
    while (1) {
        clear();
        drawBox(space);
        memset(l->terrain, 0, l->size);
        l->terrain[tower_pos] = 3;
        drawLand(*l, space, 5);

        refresh();

        int ch = getch();
        switch (ch) {
        case 'q':
            endwin();
            return 0;
            break;
        default:
            ++tower_pos;
            break;
        }
    }

    endwin();
    return 0;
}
