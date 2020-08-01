#include <stdlib.h>
#include <stdio.h>

typedef char ElemType;

typedef struct{
	ElemType val;
	struct node *left;
	struct node *right;
}node,*pNode;

typedef struct{
	pNode treeNode;
	struct queNode *next;
}queNode,*pQueNode;

typedef struct {
	pQueNode head;
	pQueNode tail;
	int len;
}Queue_t,*pQueue_t;

levelTreeBuilding(pNode*,pQueue_t*,ElemType);
void TreePreOrder(pNode);