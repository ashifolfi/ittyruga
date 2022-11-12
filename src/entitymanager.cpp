#include <bn_core.h>
#include <bn_math.h>
#include <bn_keypad.h>
#include <bn_display.h>
#include <bn_sprite_actions.h>
#include <bn_sprite_builder.h>

#include "entitymanager.h"

using namespace ittyruga;

entitymanager::entitymanager() {
    
}

void entitymanager::addEntity(entity* ent) {
   this->entList.push_back(ent);
}

void entitymanager::update() {
    for(entity* ent : this->entList) {
        ent->update(true);
    }
}