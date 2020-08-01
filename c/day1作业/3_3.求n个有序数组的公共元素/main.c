#include <stdio.h>
#include <stdlib.h>
#define M 5
#define N 6

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
	int arry[M][N] = { {0,1,2,3,4,5},{1,2,3,4,5,6},{2,3,4,5,6,7},{3,4,5,6,7,8},{4,5,6,7,8,9} };
	int b[M - 1][N] = { {0} ,{0},{0},{0} };
	interElem(arry[0], arry[1], b[0]);
	for (i = 2; i < M; i++) {
		interElem(arry[i], b[i - 2], b[i - 1]);
	}
	printf("公共元素为：");
	for (i = 0; b[M - 2][i]; i++) {
		printf("%d ", b[M - 2][i]);
	}
	printf("\n");
	return 0;
}