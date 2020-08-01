#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 6
void elemMinAbs(int arry[],int *x,int *y){
	int i, j, minAbs;
	minAbs = abs(arry[0]-arry[1]);
	*x = arry[0];
	*y = arry[1];
	for (i = 0; i < N-1; i++) {
		for (j = i+1; j < N; j++) {
			if (abs(arry[i]-arry[j]) < minAbs) {
				minAbs = abs(arry[i]-arry[j]);
				*x = arry[i];
				*y = arry[j];
			}
		}
	}
}
int main() {
	int i,x,y;
	int arry[N] = { 0 };
	printf("请输入%d个整数：\n", N);
	for (i = 0; i < N; i++) {
		scanf("%d", &arry[i]);
	}
	elemMinAbs(arry, &x, &y);
	printf("x=%d\ny=%d\nminAbs=%d", x, y,abs(x-y));
	return 0;
}