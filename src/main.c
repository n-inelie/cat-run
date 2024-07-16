#include "box.h"
#include "land.h"
#include "player.h"
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define BASE_LEVEL 5

int main(void) {
    srand(time(NULL));

    initscr();
    raw();
    noecho();

    clear();

    Box space = {ORIGIN, COLS, LINES};
    drawBox(space);

    Land *l = LandCreate(space.width / 3);

    Player plyr;
    plyr.y = BASE_LEVEL;
    plyr.size = 3;
    bool plyr_jump = false;
    bool plyr_fallback = false;

    nodelay(stdscr, TRUE);
    int rand_bet_0_10 = rand() % 10;
    while (1) {
        clear();
        drawBox(space);

        rand_bet_0_10 = rand() % 10;
        if (rand_bet_0_10 > 8) {
            genTower(l, 3);
        } else {
            genTower(l, 0);
        }
        drawLand(*l, space, BASE_LEVEL);

        if (plyr_jump) {
            if (plyr.y < BASE_LEVEL + plyr.size * 3) {
                plyr.y += 2;
            } else {
                plyr_jump = false;
                plyr_fallback = true;
            }
        }
        if(plyr_fallback) {
            if (plyr.y > BASE_LEVEL) {
                plyr.y -= 2;
            } else {
                plyr_fallback = false;
            }
        }

        drawPlayer(space, plyr);
        move(0, 0);
        refresh();

        usleep(50000);
        int ch = getch();
        if (ch == ERR) {
            continue;
        } else {
            switch (ch) {
            case 'q':
                LandDestroy(l);
                endwin();
                return 0;
                break;
            case ' ':
                if (!plyr_jump && !plyr_fallback) {
                    plyr.jump_count++;
                    plyr_jump = true;
                }
                break;
            default:
                break;
            }
        }
    }

    endwin();
    return 0;
}
