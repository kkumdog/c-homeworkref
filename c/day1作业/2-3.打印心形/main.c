#include <stdio.h>
#include <stdlib.h>

void heartPrint(int n) {
	int i, j,row1;
	//打印上半部分
	row1 = n / 2 - 2;
	for (i = 0; i <row1; i++) {
		for (j = row1-i; j > 0; j--) {
			printf(" ");
		}
		for (j = i + 2; j > 0; j--) {
			printf("* ");
		}
		for (j = 2*(row1 - i); j > 0; j--) {
			printf(" ");
		}
		if (n % 2 != 0) {
			printf("  ");
		}
		for (j = i + 2; j > 0; j--) {
			printf("* ");
		}
		printf("\n");
	}
	//打印下半部分
	for (i = 0; i < n; i++) {
		for (j = i; j >0; j--) {
			printf(" ");
		}
		for (j = n - i; j > 0; j--) {
			printf("* ");
		}
		printf("\n");
	}
}

int main() {
	int n;
	printf("请输入边长:");
	scanf("%d", &n);
	heartPrint(n);
	return 0;
}