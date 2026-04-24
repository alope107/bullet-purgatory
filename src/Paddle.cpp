#include <bn_math.h>
#include <bn_keypad.h>

#include "Paddle.h"
#include "Manager.h"

#include "bn_sprite_items_paddle.h"
#include "bn_sprite_items_bullet.h"

Paddle::Paddle(Manager& manager, bn::fixed radius, bn::fixed rotate_speed, bn::fixed angle) : 
    _manager(manager),
    _radius(radius),
    _rotate_speed(rotate_speed),
    _angle(angle),
    _sprite(bn::sprite_items::paddle.create_sprite(_position())) {
    _sprite.set_z_order(-1);
}

void Paddle::update() {
    if (bn::keypad::left_held()) {
        _rotate(_rotate_speed);
    }
    if (bn::keypad::right_held()) {
        _rotate(-_rotate_speed);
    }
    if (bn::keypad::a_pressed()) {
        _shoot();
    }
}

bn::fixed_point Paddle::_position() {
    auto [sin, cos] = bn::degrees_sin_and_cos(_angle);
    return bn::fixed_point(cos * _radius, sin * _radius);
}

void Paddle::_rotate(bn::fixed angle) {
    // Possible optimization: use 256 circle units instead for east LUT and masking
    _angle += angle;
    while (_angle >= 360)
        _angle -= 360;
    while (_angle < 0)
        _angle += 360;

    _sprite.set_position(_position());
    _sprite.set_rotation_angle(360 - _angle);
}

void Paddle::_shoot() {
    bn::fixed shootSpeed = 4; // TODO: put elsewhere
    auto [sin, cos] = bn::degrees_sin_and_cos(_angle);
    _manager.createBullet(_sprite.position(), {-cos * shootSpeed, -sin * shootSpeed});
}