#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>
#include <bn_vector.h>

#include "Bullet.h"
#include "Paddle.h"

#include "bn_sprite_items_paddle.h"
#include "bn_sprite_items_bullet.h"

static constexpr int MAX_BULLETS = 30;

int main() {
    bn::core::init();

    Paddle paddle(50);

    bn::fixed rotate_speed = 3;


    bn::vector<Bullet, MAX_BULLETS> bullets = {};

    while(true) {
        if(bn::keypad::left_held()) {
            paddle.rotate(rotate_speed);
        }
        if(bn::keypad::right_held()) {
            paddle.rotate(-rotate_speed);
        }
        if(bn::keypad::a_pressed()) {
            if(!bullets.full()) {
                bullets.push_back(paddle.shoot());
            }
        }
        for(Bullet &bullet : bullets) {
            bullet.update();
        }
        bn::core::update();
    }
}