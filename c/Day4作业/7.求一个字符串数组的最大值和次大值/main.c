#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50

void findBigAndSubBig(char str[][N + 1], int len, char **big, char **subbig) {
	int i;
	*subbig = *big =str[0];
	for (i = 1; i < len; i++) {
		if (strcmp(str[i], *big)>0) {
			*subbig = *big;
			*big = str[i];
		}
		else if(strcmp(str[i],*subbig)>0){
			*subbig = str[i];
		}
	}
}

int main() {
	char str[5][N + 1] = { 0 };
	char *big,*subbig;
	int i=0;
	printf("请输入5个字符串，以空格隔开:");
	while (i<5 ) {
		scanf("%s", str[i++]);
	}
	rewind(stdin);
	findBigAndSubBig(str, 5, &big, &subbig);
	printf("最大者和次大者分别是:%s %s", big, subbig);
	return 0;
}