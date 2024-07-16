#ifndef PLAYER_H
#define PLAYER_H

#include "box.h"
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    uint32_t score;
    uint32_t jump_count;
    uint32_t super_jump_count;
    uint32_t rockets_launched;
    uint8_t size;
    uint8_t y;
} Player;

void drawPlayer(Box, Player);

#endif
