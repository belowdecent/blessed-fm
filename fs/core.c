#include "core.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char current_directory[BLSD_PATH_SIZE];

int BLSD_InitFS(const char* path) {
	int result = chdir(path);
	if (result)
		return result;

	getcwd(current_directory, sizeof(current_directory));
	return 0;
}

const char* BLSD_GetCurrentDirectory() {
	return current_directory;
}

BLSD_FileList* BLSD_GetDirectoryContents() {
	FILE* ls_output = popen("ls -1FX --group-directories-first", "r");
	char output[255];
	BLSD_FileList* list = NULL;

	while (fgets(output, 255, ls_output)) {
		list = BLSD_AppendFileList(list, output);
	}

	pclose(ls_output);
	return list;
}
