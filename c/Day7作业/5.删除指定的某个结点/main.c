#include "func.h"



int main() {
	lineList list;
	memset(&list, 0, sizeof(lineList));
	int val,deleteNum;
	printf("���������������:");
	while (scanf("%d", &val) != EOF) {
		listTailInsert(&list, val);
	}
	listPrint(list);
	printf("��������ɾ��������");
	scanf("%d", &deleteNum);
	listElemDelete(&list, deleteNum);
	listPrint(list);
	listDestory(&list);
	return 0;
}