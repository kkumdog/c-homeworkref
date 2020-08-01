#include <stdio.h>
#include <stdlib.h>
#define N 4

typedef struct node {
	char str[N + 1];//��һλ�桮\0��,��ʾ�ַ�������
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
void listReverse(pLineList);//ֻ��ת�������ı����е��ַ���
void strReverse(char[], int);
void listAndStrReverse(pLineList);//�ȷ�ת�����ַ�ת����е��ַ���
void listHeadAdjustAlign(pLineList);
void largeNumAdd(pLineList, pLineList, pLineList);
void listPrint(lineList);
void listDestory(pLineList);