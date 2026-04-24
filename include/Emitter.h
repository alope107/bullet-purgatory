#pragma once

#include <bn_random.h>

class Manager;

class Emitter {
public:
    Emitter(Manager& manager, bn::fixed shotProb);
    void update();
private:
    Manager& _manager;
    bn::fixed _shotProb;
};