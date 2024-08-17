#ifndef GNG_ATLAS_H
#define GNG_ATLAS_H

#define ASSERT(exp) if (!(exp)) { *((int *)0) = 0xDEAD; }

enum c_bool { 
    false, true 
};

#include "gng_types.h"

typedef char *char_ptr;
#define LIST_TYPE char_ptr
#include "list.h"

typedef struct image_data {
    char *name;
    i32 width;
    i32 height;
    u8 *data;
} image_data;
#define LIST_TYPE image_data
#include "list.h"


#endif
