#include "func.h"

void listTailInsert(pLineList list, Elemtype val) {
	pNode pNew = (pNode)calloc(1, sizeof(node));//自动初始化为0
	pNew->val = val;
	if (list->head == NULL) {
		list->head = pNew;
		list->tail = pNew;
	}
	else {
		pNew->next = list->tail->next;
		list->tail->next = pNew;
		list->tail = pNew;
	}
	list->len++;
}

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
		free(p);//free之后p指向的结构体里面的数据会改变
		p = q;
	}
	list->head = NULL;
	list->tail = NULL;
	list->len = 0;
}

void listReverse(pLineList list) {
	pNode pre, p, q;//q用于记录原本的p->next
	pre = q = NULL;
	p = list->head;
	if (list->head == NULL) {
		return;
	}
	while (p) {
		q = p->next;
		p->next = pre;
		pre = p;
		p = q;
	}
	list->tail = list->head;
	list->head = pre;
}