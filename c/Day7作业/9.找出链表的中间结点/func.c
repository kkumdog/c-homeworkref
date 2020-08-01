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

void listDivide(pLineList list,pLineList pevenPoseList) {//原链表保存奇数位置的元素，偶数位置的元素组成一个新链表
	pNode p,q;
	p = list->head;
	if (p == NULL) {
		printf("原链表为空\n");
		return;
	}
	if (p->next == NULL) {
		printf("原链表仅有一个元素\n");
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
		list->len--;//p每跳过一个元素，list->len减一
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
		pevenPoseList->len++;//只有q跳到存在元素上，pevenPoseList->len才加一
	}
	return;
}