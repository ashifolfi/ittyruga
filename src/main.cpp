/*
    Ittyruga main.cpp
    
    (C) 2022 by K. "ashifolfi" J.
*/

#include "bn_core.h"
#include "bn_math.h"
#include "bn_keypad.h"
#include "bn_display.h"
#include "bn_sprite_actions.h"
#include "bn_sprite_builder.h"

#include "ship.h"

#include "entitymanager.h"

using namespace ittyruga;

int main()
{
    bn::core::init();

    //ship ittyruga = ship();
    
    entitymanager EntMan = entitymanager();
    
    EntMan.addEntity(new ship());

    while(true)
    {
        bn::core::update();
        EntMan.update();
    }
}
