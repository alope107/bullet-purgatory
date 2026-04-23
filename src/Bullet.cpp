#include "Bullet.h"

#include "bn_sprite_items_bullet.h"

Bullet::Bullet(bn::fixed_point position, bn::fixed_point velocity) :
    _velocity(velocity),
    _sprite(bn::sprite_items::bullet.create_sprite(position))
    {}

void Bullet::update() {
    _sprite.set_position(_sprite.position() + _velocity);
}