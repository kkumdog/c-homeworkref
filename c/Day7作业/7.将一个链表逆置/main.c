#include "func.h"

int main() {
	lineList list;
	memset(&list, 0, sizeof(lineList));
	int val;
	printf("���������������:");
	while (scanf("%d", &val) != EOF) {
		listTailInsert(&list, val);
	}
	listPrint(list);
	printf("���ú������:\n");
	listReverse(&list);
	listPrint(list);
	listDestory(&list);
	return 0;
}