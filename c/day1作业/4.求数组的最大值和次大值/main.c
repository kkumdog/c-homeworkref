#include <stdio.h>
#include <stdlib.h>
#define N 8
void getMaxSubmax(int arry[]) {
	int i, max, submax;
	max = submax = arry[0];
	for (i = 1; i < N; i++) {
		if (arry[i] > max) {
			submax = max;
			max = arry[i];
		}
		else if (arry[i] > submax) {
			submax = arry[i];
		}
	}
	printf("Max:%d\nSubMax:%d", max, submax);
}
int main() {
	int i;
	int arry[N] = { 0,1,10,3,4,5,7,2 };
	printf("ÇëÊäÈë8¸öÊı:\n");
	for (i = 0; i < N; i++) {
		scanf("%d", &arry[i]);
	}
	getMaxSubmax(arry);
	return 0;
}