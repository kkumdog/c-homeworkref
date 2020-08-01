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



void listTailInsert(pLineList, Elemtype);
void getFourthFromTheBottom(lineList,int k);
void listPrint(lineList);
void listDestory(pLineList);