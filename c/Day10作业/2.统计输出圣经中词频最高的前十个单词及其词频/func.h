#include <stdio.h>
#define WORDSIZE 32
#define HASHSIZE 1000000
#define NULLWORD (word[WORDSIZE]={0})

typedef struct entry {
	char word[WORDSIZE];//����
	int count;//���ִ���
}entry,*pEntry;

typedef struct{
	pEntry table;//ָ��hash��ͷԪ��
	int size;//hash���ʵ�ʴ�С
}hash;

unsigned int ELFHash(char*, unsigned int);
void hashInitialize(hash*);
void hashInserte(hash*,char[],unsigned int);
void hashQsort(hash*);
void showTop10(hash map);
int compare(const void*, const void*);
void hashPrint(hash);
void hashDestory(hash*);
