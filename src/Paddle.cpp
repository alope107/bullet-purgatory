#include <bn_math.h>

#include "Paddle.h"

#include "bn_sprite_items_paddle.h"

Paddle::Paddle(bn::fixed radius, bn::fixed angle) :
    _radius(radius),
    _angle(angle),
    _sprite(bn::sprite_items::paddle.create_sprite(_position()))
    {}

bn::fixed_point Paddle::_position() {
    auto [sin, cos] = bn::degrees_sin_and_cos(_angle);
    return bn::fixed_point(cos * _radius, sin * _radius);
}


void Paddle::rotate(bn::fixed angle) {
    // Possible optimization: use 256 circle units instead for east LUT and masking
    _angle += angle;
    while(_angle >= 360) _angle -= 360;
    while(_angle < 0) _angle += 360;

    _sprite.set_position(_position());
    _sprite.set_rotation_angle(360 - _angle);
}

Bullet Paddle::shoot() {
    bn::fixed shootSpeed = 3; // TODO: put elsewhere
    auto [sin, cos] =  bn::degrees_sin_and_cos(_angle);
    return Bullet(_sprite.position(), {-cos * shootSpeed, -sin * shootSpeed});
}