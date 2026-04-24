#pragma once

#include <bn_fixed_point.h>

static constexpr int HALF_SCREEN_WIDTH = 240/2;
static constexpr int HALF_SCREEN_HEIGHT = 160/2;

static inline bool outOfBounds(const bn::fixed_point &position) {
    return position.x() > HALF_SCREEN_WIDTH ||
           position.x() < -HALF_SCREEN_WIDTH ||
           position.y() > HALF_SCREEN_HEIGHT ||
           position.y() < -HALF_SCREEN_HEIGHT;
}