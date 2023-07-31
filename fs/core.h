#ifndef __BLSD_FS_CORE
#define __BLSD_FS_CORE

#ifndef BLSD_PATH_SIZE
#define BLSD_PATH_SIZE 1024
#endif

#include "list.h"

int BLSD_InitFS(const char* path);
BLSD_FileList* BLSD_GetDirectoryContents();
const char* BLSD_GetCurrentDirectory();

#endif // !__BLSD_CORE
