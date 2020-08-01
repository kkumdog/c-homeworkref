#include "func.h"

void listTailInsert(pLineList list, Elemtype val) {
	pNode pNew = (pNode)calloc(1, sizeof(node));//�Զ���ʼ��Ϊ0
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
		free(p);//free֮��pָ��Ľṹ����������ݻ�ı�
		p = q;
	}
	list->head = NULL;
	list->tail = NULL;
	list->len = 0;
}

void getFourthFromTheBottom(lineList list, int k){
	pNode p,q;
	int i;
	if (list.len < k) {
		printf("������С��%d\n",k);
		return;
	}
	p = q = list.head;
	for (i = 0; i < k; i++) {
		p = p->next;
	}
	while (p) {
		p = p->next;
		q = q->next;
	}
	printf("����ĵ�����%d����㣺%d\n", k, q->val);
	return;
}