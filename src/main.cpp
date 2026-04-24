#include <bn_core.h>

#include "Manager.h"

int main() {
    bn::core::init();
    Manager manager(70, 5, .005);

    while (true) {
        manager.update();
        bn::core::update();
    }
}