#pragma once

#include <bn_fixed.h>
#include <bn_sprite_ptr.h>

class Paddle {
    public:
        Paddle(bn::fixed radius, bn::fixed angle=0);
        void rotate(bn::fixed deg); // positive degrees is CCW, negative CW
    private:
        bn::fixed_point _position();
        
        bn::fixed _radius;
        bn::fixed _angle;
        bn::sprite_ptr _sprite;

};