#include "func.h"

int main() {
	lineList list;
	memset(&list, 0, sizeof(lineList));
	int val;
	printf("请输入欲插入的数:");
	while (scanf("%d", &val) != EOF) {
		listTailInsert(&list, val);
	}
	listPrint(list);
	printf("逆置后的链表:\n");
	listReverse(&list);
	listPrint(list);
	listDestory(&list);
	return 0;
}