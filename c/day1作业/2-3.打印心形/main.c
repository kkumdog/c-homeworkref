#include <stdio.h>
#include <stdlib.h>

void heartPrint(int n) {
	int i, j,row1;
	//��ӡ�ϰ벿��
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
	//��ӡ�°벿��
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
	printf("������߳�:");
	scanf("%d", &n);
	heartPrint(n);
	return 0;
}