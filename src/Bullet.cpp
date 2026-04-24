#include "Bullet.h"
#include "location.h"

#include "bn_sprite_items_bullet.h"


Bullet::Bullet(bn::fixed_point position, bn::fixed_point velocity) :
    _velocity(velocity),
    _sprite(bn::sprite_items::bullet.create_sprite(position))
    {}

bool Bullet::update() {
    _sprite.set_position(_sprite.position() + _velocity);
    return !outOfBounds(_sprite.position()); // mark bullet for removal if it goes offscreen
}