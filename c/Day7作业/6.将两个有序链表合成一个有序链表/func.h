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

void listSortInsert(pLineList, int);
void listPrint(lineList);
void listDestory(pLineList);
pLineList listMerge(pLineList, pLineList);