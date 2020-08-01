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
		free(p);//free之后p指向的结构体里面的数据会改变
		p = q;
	}
	list->head = NULL;
	list->tail = NULL;
	list->len = 0;
}
void listSortInsert(pLineList list, int val) {
	pNode pNew = (pNode)calloc(1, sizeof(node));
	pNew->val = val;
	pNode ppre=NULL, pcur=NULL;
	ppre = pcur = list->head;
	if (list->head == NULL) {
		list->head = pNew;
		list->tail = pNew;
	}
	else if(val <=list->head->val){//插入位置在头前
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

int main() {
	lineList list;
	memset(&list, 0, sizeof(lineList));
	int val;
	printf("请输入欲插入的数:");
	while (scanf("%d", &val) != EOF) {
		listSortInsert(&list, val);
	}
	listPrint(list);
	listDestory(&list);
	return 0;
}