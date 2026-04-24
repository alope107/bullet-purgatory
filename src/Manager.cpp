#include "Manager.h"

#include "bn_sprite_items_bullet.h"
#include "bn_sprite_items_target.h"

Manager::Manager(bn::fixed paddle_radius, bn::fixed paddle_speed) :
    _rng(bn::random()),
    _paddle(*this, paddle_radius, paddle_speed),
    _emitter(*this)
{}

bn::random& Manager::rng() {return _rng;}

void Manager::update() {
    _paddle.update();
    _emitter.update();

    // TODO: refactor duplicated projectile code
    for (auto it = _bullets.begin(); it != _bullets.end();) {
        if (!it->update()) {
            it = _bullets.erase(it);
        }
        else {
            it++;
        }
    }
    for (auto it = _targets.begin(); it != _targets.end();) {
        if (!it->update()) {
            it = _targets.erase(it);
        }
        else {
            it++;
        }
    }
}

bool Manager::createBullet(bn::fixed_point position, bn::fixed_point velocity) {
    if(_bullets.full()) return false;
    _bullets.emplace_back(position, velocity, bn::sprite_items::bullet);
    return true;
}

bool Manager::createTarget(bn::fixed_point position, bn::fixed_point velocity) {
    if(_bullets.full()) return false;
    _bullets.emplace_back(position, velocity, bn::sprite_items::target);
    return true;
}