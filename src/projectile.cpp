#include <bn_core.h>
#include <bn_math.h>
#include <bn_keypad.h>
#include <bn_display.h>
#include <bn_sprite_actions.h>
#include <bn_sprite_builder.h>

#include "projectile.h"
#include "bn_sprite_items_proj_basic.h"

using namespace ittyruga;

projectile::projectile(int polarity) : entity() {
    this->sprite = bn::sprite_items::proj_basic.create_sprite(0, 0);
    this->spriteframe = polarity;
}

void projectile::update(bool visible) {
    this->sprite.set_visible(visible);
    
    this->sprite.set_tiles(bn::sprite_items::proj_basic.tiles_item().create_tiles(this->spriteframe));
    
    // move the projectile upwards at a constant rate
    // TODO: Implement angled movement
    this->position.set_y(this->position.y() - 2);
    bn::sprite_position_manager::set(this->position, this->sprite);
}