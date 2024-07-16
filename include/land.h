#ifndef LAND_H
#define LAND_H

#include <stdint.h>
#include "box.h"

typedef struct {
    uint8_t size;
    uint8_t *terrain;
} Land;

Land *LandCreate(uint8_t size);
void LandDestroy(Land *l);

void drawLand(Land l, Box b, uint8_t base_height);

#endif
