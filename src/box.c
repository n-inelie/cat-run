#include "box.h"
#include <assert.h>
#include <ncurses.h>
#include <stdarg.h>
#include <stdint.h>

void drawBox(Box b) {
    mvhline(b.p.y, b.p.x + 1, ACS_HLINE, b.width - 2);
    mvhline(b.p.y + b.height - 1, b.p.x + 1, ACS_HLINE, b.width - 2);
    mvvline(b.p.y + 1, b.p.x, ACS_VLINE, b.height - 2);
    mvvline(b.p.y + 1, b.p.x + b.width - 1, ACS_VLINE, b.height - 2);

    mvaddch(b.p.y, b.p.x, ACS_ULCORNER);
    mvaddch(b.p.y, b.p.x + b.width - 1, ACS_URCORNER);
    mvaddch(b.p.y + b.height - 1, b.p.x, ACS_LLCORNER);
    mvaddch(b.p.y + b.height - 1, b.p.x + b.width - 1, ACS_LRCORNER);
}

void boxInsertText(Box b, uint8_t line_nr, char *str, ...) {
    assert(line_nr < b.height - 1);

    va_list args;
    va_start(args, str);
    mvprintw(b.p.y + line_nr, b.p.x + 1, str, args);

    va_end(args);
}

void boxSetCenter(Box outer, Box *inner) {
    inner->p.x = outer.p.x + (outer.width - inner->width) / 2;
    inner->p.y = outer.p.y + (outer.height - inner->height) / 2;
}
