#include <stdio.h>
#include <stdlib.h>
#define N 4

typedef struct node {
	char str[N + 1];//用一位存‘\0’,表示字符串结束
	struct node *next;
}node,*pNode;

typedef struct{
	pNode head;
	pNode tail;
	int len;
}lineList,*pLineList;

void alpToNum(pNode);
int getNum(pLineList);
void listTailInsert(pLineList, char, int);
void listReverse(pLineList);//只反转链表，不改变结点中的字符串
void strReverse(char[], int);
void listAndStrReverse(pLineList);//既反转链表，又反转结点中的字符串
void listHeadAdjustAlign(pLineList);
void largeNumAdd(pLineList, pLineList, pLineList);
void listPrint(lineList);
void listDestory(pLineList);