#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 1

void diamondPrint(int n) {
	int i,j,k;
	//��ӡ�ϰ벿��
	for (i = 1; i <= n; i++) {
		j = n - i;
		k = i;
		while(j--)
			printf(" ");
		while(k--)
			printf("* ");
		printf("\n");
	}
	//��ӡ�°벿��
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
	printf("������������");
	scanf("%d", &n);
	diamondPrint(n);
	return 0;
}