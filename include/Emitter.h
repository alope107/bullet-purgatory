#pragma once

#include <bn_random.h>

class Manager;

class Emitter {
public:
    Emitter(Manager& manager);
    void update();
private:
    Manager& _manager;
};