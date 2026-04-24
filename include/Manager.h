#pragma once

#include <bn_fixed_point.h>
#include <bn_random.h>
#include <bn_list.h>

#include "Emitter.h"
#include "Ship.h"
#include "Projectile.h"

static constexpr int MAX_BULLETS = 50;
static constexpr int MAX_TARGETS = 50;

class Manager {
public:
    Manager(bn::fixed shipRadius, bn::fixed shipSpeed, bn::fixed emitterShotProb);

    bn::random& rng();
    void update();

    bool createBullet(bn::fixed_point position, bn::fixed_point velocity);
    bool createTarget(bn::fixed_point position, bn::fixed_point velocity);
    
private:
    bn::random _rng;
    Ship _ship;
    Emitter _emitter;
    bn::list<Projectile, MAX_BULLETS> _bullets;
    bn::list<Projectile, MAX_TARGETS> _targets;
};