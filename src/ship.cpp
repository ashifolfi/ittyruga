#include <bn_core.h>
#include <bn_math.h>
#include <bn_keypad.h>
#include <bn_display.h>
#include <bn_sprite_actions.h>
#include <bn_sprite_builder.h>
#include <bn_sprite_animate_actions.h>

#include "ship.h"
#include "projectile.h"

using namespace ittyruga;

int anim_ticker = 0;

int fire_cooldown = 0;

ship::ship() {
}

void ship::swap_polarity() {
    if (this->polarity == 1) {
         this->polarity = 2;
    }
    else {
       this->polarity = 1;
    }
}

void ship::update(bool visible) {
    this->sprite.set_visible(visible);
    
    // swap polarity
    if (bn::keypad::pressed(bn::keypad::key_type::A)) {
        this->swap_polarity();
    }
    
    // fire
    if (bn::keypad::pressed(bn::keypad::key_type::B)) {
        
    }
    
    // My dumbass cannot figure out how animations work in this engine so I made my own system :D
    if (this->lastpolarity != this->polarity)
    {
        if (this->polarity > this->lastpolarity)
        {
            if (this->spriteframe < 4)
                if (anim_ticker == 4) {
                    this->spriteframe++;
                    anim_ticker = 0;
                }
                else
                    anim_ticker++;
            else
                this->lastpolarity = this->polarity;       
        }
        else
        {
            if (this->spriteframe > 0)
                if (anim_ticker == 4) {
                    this->spriteframe--;
                    anim_ticker = 0;
                }
                else
                    anim_ticker++;
            else
                this->lastpolarity = this->polarity;
        }
    }
        
    this->sprite.set_tiles(bn::sprite_items::ship.tiles_item().create_tiles(this->spriteframe));

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