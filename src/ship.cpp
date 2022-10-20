#include "bn_core.h"
#include "bn_math.h"
#include "bn_keypad.h"
#include "bn_display.h"
#include "bn_sprite_actions.h"
#include "bn_sprite_builder.h"

#include "bn_sprite_items_ship.h"

#include "ship.h"

using namespace ittyruga;

ship::ship() {
   this->sprite = bn::sprite_items::ship.create_sprite(0, 0);
}

void ship::update(bool visible) {
    this->sprite.set_visible(visible);
}