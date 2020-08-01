#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int id;
	char name[24];
	float score[3];
}stu,*pStu;

void sortById(pStu[], int);
void sortByscore(pStu[], int);
void showAllInfo(pStu[], int);
void showBestInfo(pStu[], int);
void destory(pStu[], int);