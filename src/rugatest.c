#include <string.h>
#include "dusk.h"
#include "contrib/gbamap.h"

Scene rugatest_scene = {
    .start = rugaroom_start,
    .update = rugaroom_update,
    .end = rugaroom_end,
};