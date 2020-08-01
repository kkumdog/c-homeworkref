#include <stdio.h>
#include <stdlib.h>
#define N 1001

long getRepELem(int arry[]) {
	int i;
	long sum1, sum2;
	sum1 = sum2 = 0;
	for (i = 0; i < N; i++) {
		sum1 += arry[i];
		sum2 += i;
	}
	return sum1 - sum2;
}
int main() {
	int i;
	int arry[N] = { 0 };
	for (i = 0; i < 1000; i++) {
		arry[i] = i+1;
	}
	arry[N - 1] = 800;
	printf("%d\n", getRepELem(arry));
	return 0;
}