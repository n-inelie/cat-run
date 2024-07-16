#include "box.h"
#include "land.h"
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
    srand(time(NULL));

    initscr();
    raw();
    noecho();

    clear();

    Box space = {ORIGIN, COLS, LINES};
    drawBox(space);

    Land *l = LandCreate(space.width / 3);

    while (1) {
        clear();
        drawBox(space);
        genTower(l, rand() % 8);
        drawLand(*l, space, 5);

        refresh();

        int ch = getch();
        switch (ch) {
        case 'q':
            LandDestroy(l);
            endwin();
            return 0;
            break;
        default:
            break;
        }
    }

    endwin();
    return 0;
}
