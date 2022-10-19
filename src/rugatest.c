#include <string.h>
#include "dusk.h"
#include "contrib/gbamap.h"

Sprite* ship;
//const int WALK_SPEED = 1;

/** virtual position */
typedef struct VPos {
    short x, y;
} VPos;

VPos ship_vpos;
// background position in relation to that of the rest of the game
VPos bg_vpos;

void rugaroom_start() {
    dusk_init_graphics_mode0();

    // load sprite atlas
    dusk_sprites_init();
    SpriteAtlas atlas = dusk_load_atlas("a_ship");
    dusk_sprites_upload_atlas(&atlas);

     // make ship sprite (&sprites[0])
    ship = dusk_sprites_make(0, 18, 21,
                               (Sprite){.x = SCREEN_WIDTH / 2 - 8,
                                        .y = SCREEN_HEIGHT / 2 - 8,
                                        .base_tid = 32,
                                        .page = 0,
                                        .flags = SPRITEFLAG_PRIORITY(3)});
}

void rugaroom_update() {
    dusk_frame();

    // input
    int y_move = key_tri_vert();
    int x_move = key_tri_horz();
    //bool moving = (y_move != 0 || x_move != 0);

    // update pos
    ship->x += x_move * 1;
    ship->y += y_move * 1;

    // update sprites
    dusk_sprites_update();
}

void rugaroom_end() {}

Scene rugatest_scene = {
    .start = rugaroom_start,
    .update = rugaroom_update,
    .end = rugaroom_end,
};