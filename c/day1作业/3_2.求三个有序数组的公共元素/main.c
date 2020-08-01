#include <stdio.h>
#include <stdlib.h>
#define N 5
void interElem(int arry1[], int arry2[], int result[]) {
	int i, j, k;
	i = j = k = 0;
	while (i < N && j < N) {
		while (arry1[i] < arry2[j]) {
			i++;
			if (i == N) {
				break;
			}
		}
		while (arry1[i] > arry2[j]) {
			j++;
			if (j == N) {
				break;
			}
		}
		if (arry1[i] == arry2[j]) {
			result[k++] = arry1[i];
			i++;
			j++;
		}
	}
}
int main() {
	int i;
	int arry1[N] = { 1,2,3,4,5 };
	int arry2[N] = { 2,4,5,7,9 };
	int arry3[N] = { 1,4,5,8,10 };
	int b1[N] = { 0 };
	int b2[N] = { 0 };
	interElem(arry1, arry2, b1);
	interElem(arry3, b1, b2);
	printf("公共元素为：");
	for (i = 0; b2[i]; i++) {
		printf("%d ", b2[i]);
	}
	printf("\n");
	return 0;
}