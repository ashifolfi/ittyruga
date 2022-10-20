#ifndef IR_SHIP_H
#define IR_SHIP

#include "bn_core.h"
#include "bn_display.h"
#include "bn_sprite_ptr.h"

namespace ittyruga
{

    class ship
    {
    public:
        //static bn:unique_ptr<ship> create();
        ship();

        void update(bool visible);
    private:
        bn::sprite_ptr sprite;
    };

};
#endif