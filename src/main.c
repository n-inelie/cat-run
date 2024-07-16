#include "box.h"
#include "land.h"
#include <ncurses.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    srand(time(NULL)); 

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
        l->terrain[tower_pos - 1] = 0;
        l->terrain[tower_pos] = rand() % 8;
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
