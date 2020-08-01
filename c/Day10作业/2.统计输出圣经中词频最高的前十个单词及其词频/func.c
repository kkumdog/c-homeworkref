#include "func.h"
#include <stdlib.h>
#include <string.h>


unsigned int ELFHash(char* str, unsigned int len) {//网上找的字符串hash公式
	unsigned int hash = 0;
	unsigned int x = 0;
	unsigned int i = 0;
	for (i = 0; i < len; str++, i++) {
		hash = (hash << 4) + (*str);
		if ((x = hash & 0xF0000000L) != 0) {
			hash ^= (x >> 24);
		}
		hash &= ~x;
	}
	hash %= HASHSIZE;
	return hash;
}

void hashInitialize(hash *map) {
	map->table = (entry*)malloc(HASHSIZE * sizeof(entry));
	memset(map->table, 0, HASHSIZE * sizeof(entry));
	map->size = 0;
}

void hashInserte(hash *map, char word[], unsigned int len) {
	unsigned int index = 0;
	pEntry table = map->table;
	index = ELFHash(word, len);
	if (0 == strcmp(word, (table + index)->word)) {
		(table + index)->count++;
	}
	else {
		while (0 != (table + index)->word[0]) {
			index = (index+1) % HASHSIZE;
		}
		memcpy((table + index)->word, word, len);
		(table + index)->count++;
		map->size++;
	}
}

void hashQsort(hash *map) {//用qsort排结构体数组
	qsort(map->table, HASHSIZE, sizeof(entry), compare);
}

int compare(const void* left,const void* right) {
	pEntry p1 = (pEntry)left;
	pEntry p2 = (pEntry)right;
	if (p1->count < p2->count) {
		return 1;
	}
	else if (p1->count > p2->count) {
		return - 1;
	}
	else {
		return 0;
	}
}

void showTop10(hash map) {
	int i;
	pEntry pCur = map.table;
	printf("高频词汇\n");
	for (i = 0; i < 10; i++) {
		printf("%-30s%10d\n", pCur->word, pCur->count);
		pCur += 1;
	}
}

void hashPrint(hash map) {
	int i,len=0;
	pEntry pCur = map.table;
	printf("%-30s%10s\n", "单词", "出现频次");
	for (i = 0; i < HASHSIZE; i++) {
		if (pCur->count != 0) {
			printf("%-30s%10d\n", pCur->word, pCur->count);
		}
		pCur += 1;
	}
	printf("\n");
}
void hashDestory(hash *map) {
	if (NULL != map) {
		free(map->table);
		map->table = NULL;
	}
	map->size = 0;
}

int isAllNum(char str[]) {
	int i, len;
	len = strlen(str);
	for (i = 0; i < len; i++) {
		if (str[i] < '0' || str[i] > '9') {
			return 0;
		}
	}
	return 1;
}


