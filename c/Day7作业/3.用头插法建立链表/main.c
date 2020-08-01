#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;
typedef struct node {
	Elemtype val;
	struct node *next;
}node, *pNode;

typedef struct {
	pNode head;
	pNode tail;
	int len;
}lineList, *pLineList;

void listPrint(lineList list) {
	pNode p;
	p = list.head;
	while (p) {
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
}

void listDestory(pLineList list) {
	pNode p, q;
	p = q = list->head;
	while (p) {
		q = p->next;
		free(p);//free֮��pָ��Ľṹ����������ݻ�ı�
		p = q;
	}
	list->head = NULL;
	list->tail = NULL;
	list->len = 0;
}
void listHeadInsert(pLineList list,int val) {
	pNode pNew = (pNode)calloc(1,sizeof(node));
	pNew->val = val;
	if (list->tail == NULL) {
		list->head = pNew;
		list->tail = pNew;
	}
	else {
		pNew->next = list->head;
		list->head = pNew;
	}
	list->len++;
}

int main() {
	lineList list;
	memset(&list, 0, sizeof(lineList));
	int val;
	printf("���������������:");
	while (scanf("%d", &val) != EOF) {
		listHeadInsert(&list, val);
	}
	listPrint(list);
	listDestory(&list);
	return 0;
}