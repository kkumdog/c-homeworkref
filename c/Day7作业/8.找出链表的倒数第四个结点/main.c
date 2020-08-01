#include "func.h"

int main() {
	lineList list;
	int k,val;
	memset(&list, 0, sizeof(lineList));
	printf("请输入插入链表的数字:");
	while (scanf("%d", &val) != EOF) {
		listTailInsert(&list, val);
	}
	listPrint(list);
	printf("请输入你想得到的结点的位置(倒数)：");
	scanf("%d", &k);
	getFourthFromTheBottom(list,k);
	return 0;
}