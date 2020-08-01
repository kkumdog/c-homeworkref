#include <stdio.h>
#include <stdlib.h>
#define N 101

int aloneNum(int arry[]) {
	int i,ret=0;
	for (i = 0; i < N; i++) {
		ret ^= arry[i];
	}
	return ret;
}
int main(){
	int i;
	int arry[N] = { 0 };
	for (i = 0; i < 50; i++) {
		arry[i] = i;
	}
	for (i = 50; i < 100; i++) {
		arry[i] = i-50;
	}
	arry[100] = 66;
	printf("¹Âµ¥µÄÊý:%d\n", aloneNum(arry));
	return 0;
}