#include "func.h"

int main() {
	lineList list1, list2;
	pLineList newlist;
	int val;
	memset(&list1, 0, sizeof(lineList));
	memset(&list2, 0, sizeof(lineList));
	printf("请输入插入第一个链表的数字:");
	while (scanf("%d", &val) != EOF) {
		listSortInsert(&list1, val);
	}
	printf("请输入插入第二个链表的数字:");
	while (scanf("%d", &val) != EOF) {
		listSortInsert(&list2, val);
	}
	listPrint(list1);
	listPrint(list2);
	newlist = listMerge(&list1, &list2);
	listPrint(*newlist);
	return 0;
}