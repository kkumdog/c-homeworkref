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

void listDivide(pLineList list,pLineList pevenPoseList) {//ԭ����������λ�õ�Ԫ�أ�ż��λ�õ�Ԫ�����һ��������
	pNode p,q;
	p = list->head;
	if (p == NULL) {
		printf("ԭ����Ϊ��\n");
		return;
	}
	if (p->next == NULL) {
		printf("ԭ�������һ��Ԫ��\n");
		return;
	}
	pevenPoseList->head = q = p->next;
	pevenPoseList->len++;
	while (p) {
		if (p->next==NULL) {
			list->tail = p;
			pevenPoseList->tail = q;
			break;
		}
		p->next = p->next->next;
		list->len--;//pÿ����һ��Ԫ�أ�list->len��һ
		if (p->next == NULL) {
			list->tail = p;
			pevenPoseList->tail = q;
			break;
		}
		p = p->next;
		q->next = p->next;
		if (q->next == NULL) {
			pevenPoseList->tail = q;
			list->tail = p;
			break;
		}
		q = q->next;
		pevenPoseList->len++;//ֻ��q��������Ԫ���ϣ�pevenPoseList->len�ż�һ
	}
	return;
}