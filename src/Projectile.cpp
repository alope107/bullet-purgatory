#include "Projectile.h"
#include "location.h"

#include "bn_sprite_items_bullet.h"

Projectile::Projectile(bn::fixed_point position,
                       bn::fixed_point velocity, 
                       bn::sprite_item sprite_item) 
                        : _velocity(velocity),
                         _sprite(sprite_item.create_sprite(position)){}

bool Projectile::update() {
    _sprite.set_position(_sprite.position() + _velocity);
    return !outOfBounds(_sprite.position()); // mark projectile for removal if it goes offscreen
}