#include "player.h"

void drawPlayer(Box space, Player plyr) {
    Box b = {PointNew(space.p.y + space.height - plyr.y - plyr.size,
                      space.p.x + 16),
             plyr.size, plyr.size - 1};
    drawBox(b);
}

