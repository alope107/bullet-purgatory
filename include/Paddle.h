#pragma once

#include <bn_fixed.h>
#include <bn_sprite_ptr.h>

#include "Projectile.h"

class Manager;

class Paddle {
public:
    Paddle(Manager &manager, bn::fixed radius, bn::fixed rotate_speed, bn::fixed angle = 0);
    void update();
    

private:
    Manager &_manager;
    bn::fixed_point _position();
    void _rotate(bn::fixed deg); // positive degrees is CCW, negative CW
    void _shoot();

    bn::fixed _radius;
    bn::fixed _rotate_speed;
    bn::fixed _angle;
    bn::sprite_ptr _sprite;
};