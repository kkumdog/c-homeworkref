#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 1

void diamondPrint(int n) {
	int i,j,k;
	//打印上半部分
	for (i = 1; i <= n; i++) {
		j = n - i;
		k = i;
		while(j--)
			printf(" ");
		while(k--)
			printf("* ");
		printf("\n");
	}
	//打印下半部分
	for (i = 1; i <= n; i++) {
		j = i;
		k = n-i;
		while (j--)
			printf(" ");
		while (k--) {
			printf("* ");
		}
		printf("\n");
	}
	return;
}

int main() {
	int n;
	printf("请输入行数：");
	scanf("%d", &n);
	diamondPrint(n);
	return 0;
}