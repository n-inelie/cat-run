#ifndef BOX_H
#define BOX_H

#include <stdint.h>

typedef struct {
    uint8_t y;
    uint8_t x;
} Point;

#define PointNew(y, x) (Point){y, x}
#define ORIGIN (Point){0, 0}

typedef struct {
    Point p;
    uint8_t width;
    uint8_t height;
} Box;

void drawBox(Box b);
void boxInsertText(Box b, uint8_t line_nr, char *str, ...);

void boxSetCenter(Box outer, Box *inner);

#endif
