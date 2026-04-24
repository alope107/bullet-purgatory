#include "Manager.h"

#include "bn_sprite_items_bullet.h"
#include "bn_sprite_items_target.h"

Manager::Manager(bn::fixed paddleRadius, bn::fixed paddleSpeed, bn::fixed emitterShotProb) :
    _rng(bn::random()),
    _paddle(*this, paddleRadius, paddleSpeed),
    _emitter(*this, emitterShotProb)
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

    // TODO: Get entropy from user input to give to RNG
}

bool Manager::createBullet(bn::fixed_point position, bn::fixed_point velocity) {
    if(_bullets.full()) return false;
    _bullets.emplace_back(position, velocity, bn::sprite_items::bullet);
    return true;
}

bool Manager::createTarget(bn::fixed_point position, bn::fixed_point velocity) {
    if(_targets.full()) return false;
    _targets.emplace_back(position, velocity, bn::sprite_items::target);
    return true;
}