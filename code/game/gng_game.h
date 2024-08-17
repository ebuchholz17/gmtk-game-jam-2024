#ifndef GNG_GAME_H
#define GNG_GAME_H

enum c_bool { 
    false, true 
};

#include "gng_types.h"
#include "gng_platform.h"
#include "gng_assets.h"
#include "gng_sprites.h"
#include "gng_audio.h"

#include "hitbox/hitbox.h"
#include "bubble_game/bubble_game.h"

typedef struct spinning_triangle {
    f32 x;
    f32 y;
    f32 rotation;
} spinning_triangle;

typedef struct virtual_button {
    rect boundingBox;
    input_key button;
    b32 wasDown;
} virtual_button;

typedef struct virtual_input {
    virtual_button dPadUp;
    virtual_button dPadDown;
    virtual_button dPadLeft;
    virtual_button dPadRight;

    virtual_button topButton;
    virtual_button bottomButton;
    virtual_button leftButton;
    virtual_button rightButton;
} virtual_input;

typedef struct gng_game_state {
    b32 initialized;

    mem_arena memory;
    asset_man assetMan;
    sprite_man spriteMan;
    sound_man soundMan;

    f32 t;
    virtual_input vInput;

    bubble_game bubbleGame;

    f32 soundT;

} gng_game_state;

#endif
