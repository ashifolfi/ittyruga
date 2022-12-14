#ifndef IR_SHIP_H
#define IR_SHIP_H

#include "bn_core.h"
#include "bn_display.h"
#include "bn_sprite_items_ship.h"
#include <bn_fixed_point.h>

#include "entity.h"

namespace ittyruga
{

    class ship : public entity
    {
    public:
        ship();

        void update(bool visible) override;
        void swap_polarity();
    private:
        int polarity = 1;
        int lastpolarity = 1;
    };

};
#endif