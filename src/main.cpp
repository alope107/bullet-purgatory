#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>

#include "Paddle.h"

#include "bn_sprite_items_paddle.h"

int main() {
    bn::core::init();

    Paddle paddle(50);

    bn::fixed rotate_speed = 3;

    bn::backdrop::set_color(bn::color(31, 0, 0));

    while(true) {
        if(bn::keypad::left_held()) {
            paddle.rotate(rotate_speed);
        }
        if(bn::keypad::right_held()) {
            paddle.rotate(-rotate_speed);
        }
        bn::core::update();
    }
}