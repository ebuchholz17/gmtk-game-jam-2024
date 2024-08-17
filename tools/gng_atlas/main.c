#include <stdio.h>

#include "gng_atlas.c"
#include "gng_memory.c"
#include "gng_string.c"
#include "windows_platform.c"

mem_arena initMemArena (u32 capacity) {
    mem_arena memoryArena = {0};
    memoryArena.capacity = capacity;
    memoryArena.base = malloc(capacity);
    memoryArena.current = memoryArena.base;
    return memoryArena;
}

int main (int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: [dir of images] [output file name]\n");
    }
    char *dir = argv[1];
    char *name = argv[2];

    mem_arena memory = initMemArena(100 * 1024 * 1024);
    mem_arena tempMemory = initMemArena(100* 1024 * 1024);

    char_ptr_list imageFilePaths = getFilePathsInDirOfType(dir, "*.png", &memory, &tempMemory);
    for (u32 i = 0; i < imageFilePaths.numValues; i++) {
        char *fileName = imageFilePaths.values[i];
        image_data img = {0};
        i32 numComponents = 0;
        img.data = stbi_load(fileName, &img.width, &img.height, &numComponents, 0);
        printf("test\n");
    }
}
