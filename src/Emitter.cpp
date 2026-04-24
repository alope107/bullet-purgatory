#include <bn_math.h>

#include "Emitter.h"
#include "Manager.h"

Emitter::Emitter(Manager& manager, bn::fixed shotProb) :
    _manager(manager),
    _shotProb(shotProb)
{};

void Emitter::update() {
    if(_manager.rng().get_fixed(1) < _shotProb) {
        bn::fixed MAX_TARGET_SPEED = 2; // TODO: Put elsewhere
        
        bn::fixed speed = _manager.rng().get_fixed(MAX_TARGET_SPEED);
        int angle = _manager.rng().get_int(360);
        
        auto [sin, cos] = bn::degrees_sin_and_cos(angle);
        _manager.createTarget(
            {0, 0},
            {cos * speed, sin * speed}
        );
    }
}