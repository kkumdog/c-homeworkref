#include "func.h"

void listSortInsert(pLineList list, int val) {
	pNode pNew = (pNode)calloc(1, sizeof(node));
	pNew->val = val;
	pNode ppre = NULL, pcur = NULL;
	ppre = pcur = list->head;
	if (list->head == NULL) {
		list->head = pNew;
		list->tail = pNew;
	}
	else if (val <= list->head->val) {//插入位置在头前
		pNew->next = list->head;
		list->head = pNew;
	}
	else if (val >= list->tail->val) {//插入位置在尾后
		list->tail->next = pNew;
		list->tail = pNew;
	}
	else {//插入位置在中间
		while (pcur) {
			if (val < pcur->val) {
				ppre->next = pNew;
				pNew->next = pcur;
				break;
			}
			ppre = pcur;
			pcur = pcur->next;
		}
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

pLineList listMerge(pLineList list1, pLineList list2) {
	pNode p1, p2, pre, q;
	pLineList pMergeList,temp;
	if (list1->head == NULL) {
		pMergeList = list2;
		return pMergeList;
	}
	if (list2->head == NULL) {
		pMergeList = list1;
		return pMergeList;
	}
	if (list2->head->val < list1->head->val) {//保证链首元素较小的链为list1
		temp = list1;
		list1 = list2;
		list2 = temp;
	}
	p1 = pre = list1->head;
	p2 = q = list2->head;
	pMergeList = list1;
	while (p2) {
		while (p1) {
			if (p1->val > p2->val) {
				pre->next = p2;
				q = p2->next;//用q记录p2原来的next
				p2->next = p1;
				p2 = q;
				pre = pre->next;
				break;
			}
			pre = p1;
			p1 = p1->next;
		}
		if (p1 == NULL) {
			pre->next = p2;
			pMergeList->tail = list2->tail;
			break;
		}
	}
	pMergeList->len = list1->len + list2->len;
	return pMergeList;
}