#include <bn_math.h>

#include "Emitter.h"
#include "Manager.h"

Emitter::Emitter(Manager& manager, bn::fixed shotProb) :
    _manager(manager),
    _shotProb(shotProb)
{};

void Emitter::update() {
    if(_manager.rng().get_fixed(1) < _shotProb) {
        // TODO: Put constants elsewhere
        bn::fixed MAX_TARGET_SPEED = .5; 
        int HALF_SPAWN_SQUARE = 20;

        
        bn::fixed speed = _manager.rng().get_fixed(MAX_TARGET_SPEED);
        int angle = _manager.rng().get_int(360);
                           
        auto [sin, cos] = bn::degrees_sin_and_cos(angle);

        bn::fixed_point velocity =  {cos * speed, sin * speed};
        bn::fixed_point position = {_manager.rng().get_int(-HALF_SPAWN_SQUARE, HALF_SPAWN_SQUARE),
                                    _manager.rng().get_int(-HALF_SPAWN_SQUARE, HALF_SPAWN_SQUARE)
                                   };

        _manager.createTarget(
            position,
            velocity
        );
    }
}