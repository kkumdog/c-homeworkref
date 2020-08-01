#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;
typedef struct node {
	Elemtype val;
	struct node *next;
}node,*pNode;

typedef struct {
	pNode head;
	pNode tail;
	int len;
}lineList,*pLineList;

void listTailInsert(pLineList list,Elemtype val) {
	pNode pNew =(pNode)calloc(1, sizeof(node));//自动初始化为0
	pNew->val = val;
	if ( list->head== NULL) {
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
	pNode p,q;
	p = q = list->head;
	while(p){
		q = p->next;
		free(p);//free之后p指向的结构体里面的数据会改变
		p = q;
	}
	list->head = NULL;
	list->tail = NULL;
	list->len = 0;
}
int main(){
	lineList list;
	memset(&list, 0, sizeof(lineList));
	int val;
	printf("请输入欲插入的数:");
	while (scanf("%d", &val) != EOF) {
		listTailInsert(&list, val);
	}
	listPrint(list);
	listDestory(&list);
	return 0;
}