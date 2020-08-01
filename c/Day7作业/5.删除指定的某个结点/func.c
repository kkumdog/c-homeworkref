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

void listElemDelete(pLineList list, Elemtype val) {
	pNode ppre = NULL, pcur = NULL, q = NULL;
	ppre = pcur = list->head;
	int exist = 0;
	if (pcur == NULL) {
		printf("List is NULL\n");
		return;
	}
	if (pcur->val == val) {//ɾ������ͷ��Ԫ��
		while (pcur->val == val) {
			ppre = pcur;
			pcur = pcur->next;
			free(ppre);
			list->len--;
			if (pcur == NULL) {
				list->head = NULL;
				list->tail = NULL;
				ppre = NULL;
				return;
			}
		}
		list->head = pcur;
		ppre = pcur;
	}
	while (pcur) {//ɾ�������м估β��Ԫ��(�Ż���)
		if (pcur->val == val) {
			exist = 1;
			while (pcur->val == val) {
				q = pcur->next;
				free(pcur);
				pcur = q;
				list->len--;
				if (pcur == list->tail) {
					ppre->next = pcur;
					list->tail = ppre;
					return;
				}
			}
			ppre->next = pcur;
		}
		ppre = pcur;
		pcur = pcur->next;
	}
	//while (pcur) {//ɾ�������м估β��Ԫ��
	//	if (pcur->val != val) {
	//		ppre = pcur;
	//		pcur = pcur->next;
	//	}
	//	else {
	//		exist = 1;
	//		while (pcur->val == val) {
	//			q = pcur->next;
	//			free(pcur);
	//			pcur = q;
	//			if (pcur == NULL) {
	//				ppre->next = pcur;
	//				list->tail = ppre;
	//				return;
	//			}
	//		}
	//		ppre->next = pcur;
	//		ppre = pcur;
	//		pcur = pcur->next;
	//	}
	//}
	if (exist == 0) {
		printf("Target elm is not in the list\n");
	}
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