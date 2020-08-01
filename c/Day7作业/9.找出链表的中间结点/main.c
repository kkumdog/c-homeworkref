#include "func.h"

int main() {
	lineList list,evenPosList;
	int k, val;
	memset(&list, 0, sizeof(lineList));
	memset(&evenPosList, 0, sizeof(lineList));
	printf("请输入插入链表的数字:");
	while (scanf("%d", &val) != EOF) {
		listTailInsert(&list, val);
	}
	listPrint(list);
	listDivide(&list, &evenPosList);
	listPrint(list);
	listPrint(evenPosList);
	return 0;
}