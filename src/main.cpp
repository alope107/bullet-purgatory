#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>
#include <bn_list.h>

#include "Manager.h"

#include "bn_sprite_items_paddle.h"
#include "bn_sprite_items_bullet.h"
#include "bn_sprite_items_target.h"

int main() {
    bn::core::init();
    Manager manager(60, 3);

    while (true) {
        manager.update();
        bn::core::update();
    }
}