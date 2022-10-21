#include <bn_core.h>
#include <bn_math.h>
#include <bn_keypad.h>
#include <bn_display.h>
#include <bn_sprite_actions.h>
#include <bn_sprite_builder.h>
#include <bn_sprite_animate_actions.h>

#include "ship.h"

using namespace ittyruga;

ship::ship() {
}

void ship::update(bool visible) {
    this->sprite.set_visible(visible);

    if (this->polarity == 2)
        this->sprite.set_tiles(bn::sprite_items::ship.tiles_item().create_tiles(4));
    else
        this->sprite.set_tiles(bn::sprite_items::ship.tiles_item().create_tiles(0));

    // swap polarity
    if (bn::keypad::pressed(bn::keypad::key_type::A)) {
        if (this->polarity == 1)
            this->polarity = 2;
        else
            this->polarity = 1;
    }

    // movement
    if (bn::keypad::held(bn::keypad::key_type::UP)) {
        this->position.set_y(this->position.y() - 2);
        bn::sprite_position_manager::set(this->position, this->sprite);
    }

    if (bn::keypad::held(bn::keypad::key_type::DOWN)) {
        this->position.set_y(this->position.y() + 2);
        bn::sprite_position_manager::set(this->position, this->sprite);
    }

    if (bn::keypad::held(bn::keypad::key_type::LEFT)) {
        this->position.set_x(this->position.x() - 2);
        bn::sprite_position_manager::set(this->position, this->sprite);
    }

    if (bn::keypad::held(bn::keypad::key_type::RIGHT)) {
        this->position.set_x(this->position.x() + 2);
        bn::sprite_position_manager::set(this->position, this->sprite);
    }
}