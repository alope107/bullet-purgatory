#pragma once

#include <bn_fixed.h>
#include <bn_sprite_ptr.h>

class Bullet {
    public:
        Bullet(bn::fixed_point position, bn::fixed_point velocity);
        void update();
    private:
        bn::fixed_point _velocity;
        bn::sprite_ptr _sprite;
};