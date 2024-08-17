#include "windows_platform.h"

#define MAX_NUM_IMAGES 1000

char_ptr_list getFilePathsInDirOfType (char *dirPath, char *type, mem_arena *memory, mem_arena *tempMemory) {
    char_ptr_list filePaths = char_ptr_listInit(memory, MAX_NUM_IMAGES * sizeof(char *));

    char *searchPattern = appendString(dirPath, type, tempMemory);
    WIN32_FIND_DATAA fileFindData = {0};
    HANDLE searchHandle = FindFirstFileA(searchPattern, &fileFindData);

    if (searchHandle != INVALID_HANDLE_VALUE) {
        char_ptr_listPush(&filePaths, appendString(dirPath, fileFindData.cFileName, memory));

        while (FindNextFileA(searchHandle, &fileFindData)) {
            char_ptr_listPush(&filePaths, appendString(dirPath, fileFindData.cFileName, memory));
        }
    }
    
    return filePaths;
}
