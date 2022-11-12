#include <bn_core.h>
#include <bn_math.h>
#include <bn_keypad.h>
#include <bn_display.h>
#include <bn_sprite_actions.h>
#include <bn_sprite_builder.h>

#include "entity.h"

using namespace ittyruga;

entity::entity() {
}

void entity::update(bool visible) {
    this->sprite.set_visible(visible);
}