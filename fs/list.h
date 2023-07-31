#ifndef __BLSD_FS_LIST
#define __BLSD_FS_LIST

#ifndef BLSD_FILENAME_SIZE
#define BLSD_FILENAME_SIZE 255
#endif


typedef struct BLSD_FileListNode {
	struct BLSD_FileListNode* next;
	char name[BLSD_FILENAME_SIZE];
} BLSD_FileListNode;

typedef struct BLSD_FileList {
	BLSD_FileListNode* head;
	BLSD_FileListNode* last;
} BLSD_FileList;


int BLSD_FreeFileList(BLSD_FileList* list);
BLSD_FileList* BLSD_NewFileList(const char* filename);
BLSD_FileList* BLSD_AppendFileList(BLSD_FileList* list, const char* filename);
BLSD_FileList* BLSD_PrependFileList(BLSD_FileList* list, const char* filename);

#endif
