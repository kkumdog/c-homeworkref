#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main(int argc, char* argv[]) {
	FILE *fp;
	hash word_count;
	char word[WORDSIZE] = { 0 };
	int i, j, ret = 0;
	time_t start, end;
	if (argc != 2) {
		printf("error argc,please add input file!");
		return;
	}	
	fp = fopen(argv[1], "r");
	if (NULL == fp) {
		perror("fopen");
		return;
	}
	start = time(NULL);
	hashInitialize(&word_count);
	while ((ret = fscanf(fp, "%s", word)) != EOF) {
		//puts(word);
		if (isAllNum(word)) {
			continue;
		}
		hashInserte(&word_count, word, (unsigned int)strlen(word));
	}
	hashQsort(&word_count);
	//hashPrint(word_count);
	showTop10(word_count);
	end = time(NULL);
	printf("use %d second\n", end - start);
	hashDestory(&word_count);
	return 0;
}