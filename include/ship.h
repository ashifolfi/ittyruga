#ifndef IR_SHIP_H
#define IR_SHIP_H

#include "bn_core.h"
#include "bn_display.h"
#include "bn_sprite_items_ship.h"
#include <bn_fixed_point.h>

namespace ittyruga
{

    class ship
    {
    public:
        ship();

        void update(bool visible);
    private:
        bn::sprite_ptr sprite = bn::sprite_items::ship.create_sprite(0, 0);
        bn::fixed_point position = bn::fixed_point(0,0);
        int polarity = 1;
    };

};
#endif