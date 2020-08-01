#include <stdio.h>
#include <stdlib.h>
#define N 32

//仅支持整数
void decToBinary(int n) {
	int i,j,k;
	char remainder[N + 1];
	for (i = 0; i < N + 1; i++) {
		remainder[i++] = '0';
	}
	i = 0;
	while (n>1) {
		remainder[i++] = n%2 + '0';
		n /= 2;
	}
	remainder[i] = n + '0';
	for (j = N -1- i,k=0; j >0; j--) {
		if (k != 4) {
			printf("%c", '0');
			k++;
		}
		else {
			printf("%c", '\0');
			k = 0;
		}
	}
	for (j = i,k=0; j >= 0; j--) {
		if (k != 4) {
			printf("%c", remainder[j]);
			k++;
		}
		else {
			printf("%c", '\0');
			k = 0;
		}
	}
	printf("\n");
}
int main() {
	int n;
	while (printf("请输入一个整数："),scanf("%d", &n) != EOF) {
		decToBinary(n);
	}
	
	return 0;
}