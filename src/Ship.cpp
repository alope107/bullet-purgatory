#include <bn_math.h>
#include <bn_keypad.h>

#include "Ship.h"
#include "Manager.h"

#include "bn_sprite_items_ship.h"
#include "bn_sprite_items_bullet.h"

Ship::Ship(Manager& manager, bn::fixed radius, bn::fixed rotateSpeed, bn::fixed angle) : 
    _manager(manager),
    _radius(radius),
    _rotateSpeed(rotateSpeed),
    _angle(angle),
    _sprite(bn::sprite_items::ship.create_sprite(_position())) {
    _sprite.set_z_order(-1);
}

void Ship::update() {
    if (bn::keypad::left_held()) {
        _rotate(_rotateSpeed);
    }
    if (bn::keypad::right_held()) {
        _rotate(-_rotateSpeed);
    }
    if (bn::keypad::a_pressed()) {
        _shoot();
    }
}

bn::fixed_point Ship::_position() {
    auto [sin, cos] = bn::degrees_sin_and_cos(_angle);
    return bn::fixed_point(cos * _radius, sin * _radius);
}

void Ship::_rotate(bn::fixed angle) {
    // Possible optimization: use 256 circle units instead for east LUT and masking
    _angle += angle;
    while (_angle >= 360)
        _angle -= 360;
    while (_angle < 0)
        _angle += 360;

    _sprite.set_position(_position());
    _sprite.set_rotation_angle(360 - _angle);
}

void Ship::_shoot() {
    bn::fixed shootSpeed = 4; // TODO: put elsewhere
    auto [sin, cos] = bn::degrees_sin_and_cos(_angle);
    _manager.createBullet(_sprite.position(), {-cos * shootSpeed, -sin * shootSpeed});
}