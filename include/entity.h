/*
    Basic entity class used for the main entity list in a scene
    
    (C) 2022 by K. "ashifolfi" J.
*/
#pragma once

#include "bn_core.h"
#include "bn_display.h"
#include "bn_sprite_items_ship.h"
#include <bn_fixed_point.h>
#include "bn_sprite_ptr.h"

namespace ittyruga
{

    class entity
    {
    public:
        entity();

        virtual void update(bool visible);
        
        bn::sprite_ptr sprite = bn::sprite_items::ship.create_sprite(0, 0);
        bn::fixed_point position = bn::fixed_point(0,0);
        int spriteframe = 0;
    private:
       
    };

};