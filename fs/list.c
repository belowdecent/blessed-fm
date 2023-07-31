#include <stdlib.h>
#include <string.h>

#include "list.h"

static BLSD_FileListNode* BLSD_NewFileListNode(
	BLSD_FileListNode* next, 
	const char* filename
) {
	BLSD_FileListNode* new_node = malloc(sizeof(BLSD_FileListNode));
	*new_node = (BLSD_FileListNode) {
		.next = next,
		.name = {0}
	};
	strcpy(new_node->name, filename);

	return new_node;
}


int BLSD_FreeFileList(BLSD_FileList* list) {
	if (list == NULL)
		return 0;

	BLSD_FileListNode* head = list->head;
	if (head == NULL)
		return 0;

	BLSD_FileListNode* tail = head->next;
	while (tail) {
		BLSD_FileListNode* next = tail->next;
		free(tail);
		tail = next;
	}

	free(head);
	free(list);
	return 0;
}

BLSD_FileList* BLSD_NewFileList(const char* filename) {
	BLSD_FileList* list = malloc(sizeof(BLSD_FileList));

	list->head = BLSD_NewFileListNode(NULL, filename);
	list->last = list->head;

	return list;
}

BLSD_FileList* BLSD_AppendFileList(BLSD_FileList* list, const char* filename) {
	if (list == NULL) {
		return BLSD_NewFileList(filename);
	}

	list->last->next = BLSD_NewFileListNode(NULL, filename);
	list->last = list->last->next;
	return list;
}

BLSD_FileList* BLSD_PrependFileList(BLSD_FileList* list, const char* filename) {
	if (list == NULL) {
		return BLSD_NewFileList(filename);
	}

	list->head = BLSD_NewFileListNode(list->head, filename);
	return list;
}
