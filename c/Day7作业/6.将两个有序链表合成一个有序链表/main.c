#include "func.h"

int main() {
	lineList list1, list2;
	pLineList newlist;
	int val;
	memset(&list1, 0, sizeof(lineList));
	memset(&list2, 0, sizeof(lineList));
	printf("����������һ�����������:");
	while (scanf("%d", &val) != EOF) {
		listSortInsert(&list1, val);
	}
	printf("���������ڶ������������:");
	while (scanf("%d", &val) != EOF) {
		listSortInsert(&list2, val);
	}
	listPrint(list1);
	listPrint(list2);
	newlist = listMerge(&list1, &list2);
	listPrint(*newlist);
	return 0;
}