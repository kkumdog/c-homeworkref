#include <stdio.h>
#include <stdlib.h>
#define M 5
#define N 7

void interElem(int arry1[], int arry2[]) {
	int i, j;
	i = j = 0;
	while (i < M && j < N) {
		while (arry1[i] < arry2[j]) {
			i++;
			if (i == M) {
				break;
			}
		}
		while (arry1[i] > arry2[j]) {
			j++;
			if (i == N) {
				break;
			}
		}
		if (arry1[i] == arry2[j]) {
			printf("%d ", arry1[i]);
			i++;
			j++;
		}
	}
	printf("\n");
}
int main() {
	int arry1[5] = { 1,3,5,7,9 };
	int arry2[7] = { 1,2,3,6,8,9 };
	printf("两数组的公共元素为：");
	interElem(arry1, arry2);
	return 0;
}

