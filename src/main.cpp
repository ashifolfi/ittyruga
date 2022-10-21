#include "bn_core.h"
#include "bn_math.h"
#include "bn_keypad.h"
#include "bn_display.h"
#include "bn_sprite_actions.h"
#include "bn_sprite_builder.h"

#include "ship.h"

using namespace ittyruga;

int main()
{
    bn::core::init();

    ship ittyruga = ship();

    while(true)
    {
        ittyruga.update(true);
        bn::core::update();
    }
}
