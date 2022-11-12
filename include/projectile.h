#ifndef IR_PROJBASE_H
#define IR_PROJBASE_H

#include "bn_core.h"
#include "bn_display.h"
#include <bn_fixed_point.h>

#include "entity.h"

namespace ittyruga
{

    class projectile : public entity
    {
    public:
        projectile(int polarity);

        void update(bool visible) override;
    private:
        int polarity = 0;
        // no last polarity as projectiles have fixed polarity
    };

};
#endif