#include "func.h"

int main() {
	lineList list;
	int k,val;
	memset(&list, 0, sizeof(lineList));
	printf("������������������:");
	while (scanf("%d", &val) != EOF) {
		listTailInsert(&list, val);
	}
	listPrint(list);
	printf("����������õ��Ľ���λ��(����)��");
	scanf("%d", &k);
	getFourthFromTheBottom(list,k);
	return 0;
}