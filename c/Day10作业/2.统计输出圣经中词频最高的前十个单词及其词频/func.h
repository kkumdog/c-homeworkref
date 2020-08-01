#include <stdio.h>
#define WORDSIZE 32
#define HASHSIZE 1000000
#define NULLWORD (word[WORDSIZE]={0})

typedef struct entry {
	char word[WORDSIZE];//单词
	int count;//出现次数
}entry,*pEntry;

typedef struct{
	pEntry table;//指向hash表头元素
	int size;//hash表的实际大小
}hash;

unsigned int ELFHash(char*, unsigned int);
void hashInitialize(hash*);
void hashInserte(hash*,char[],unsigned int);
void hashQsort(hash*);
void showTop10(hash map);
int compare(const void*, const void*);
void hashPrint(hash);
void hashDestory(hash*);
