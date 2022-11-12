/*
    Entity manager. makes dynamic entity creation possible
    
    (C) 2022 by K. "ashifolfi" J.
*/
#pragma once

#include <vector>

#include "bn_core.h"
#include "bn_display.h"
#include "bn_fixed_point.h"
#include "bn_sprite_ptr.h"

#include "entity.h"

namespace ittyruga
{
    class entitymanager
    {
    public:
        entitymanager();

        void addEntity(entity* ent);
        void update();
    private:
        std::vector<entity*> entList;
    };
};