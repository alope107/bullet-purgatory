#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>
#include <bn_list.h>

#include "Projectile.h"
#include "Paddle.h"

#include "bn_sprite_items_paddle.h"
#include "bn_sprite_items_bullet.h"
#include "bn_sprite_items_target.h"

static constexpr int MAX_BULLETS = 30;

int main()
{
    bn::core::init();

    Paddle paddle(70);

    bn::fixed rotate_speed = 3;

    bn::list<Projectile, MAX_BULLETS> bullets = {};

    Projectile target = Projectile({0, 0}, {0, 0}, bn::sprite_items::target);

    while (true)
    {
        if (bn::keypad::left_held())
        {
            paddle.rotate(rotate_speed);
        }
        if (bn::keypad::right_held())
        {
            paddle.rotate(-rotate_speed);
        }
        if (bn::keypad::a_pressed())
        {
            if (!bullets.full())
            {
                bullets.push_back(paddle.shoot());
            }
        }
        for (auto it = bullets.begin(); it != bullets.end();)
        {
            if (!it->update())
            {
                it = bullets.erase(it);
            }
            else
            {
                it++;
            }
        }
        bn::core::update();
    }
}