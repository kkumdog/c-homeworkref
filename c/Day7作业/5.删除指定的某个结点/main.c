#include "func.h"



int main() {
	lineList list;
	memset(&list, 0, sizeof(lineList));
	int val,deleteNum;
	printf("请输入欲插入的数:");
	while (scanf("%d", &val) != EOF) {
		listTailInsert(&list, val);
	}
	listPrint(list);
	printf("请输入欲删除的数：");
	scanf("%d", &deleteNum);
	listElemDelete(&list, deleteNum);
	listPrint(list);
	listDestory(&list);
	return 0;
}