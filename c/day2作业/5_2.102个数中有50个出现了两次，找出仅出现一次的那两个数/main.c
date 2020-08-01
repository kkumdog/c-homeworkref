#include <stdio.h>
#include <stdlib.h>
#define N 102

void aloneTwo(int arry[],int *num1,int *num2) {
	int i,j,k,ret,ref;
	int heap[2][101] = { {0},{0} };
	ret = ref = 0;
	for (i = 0; i < 102; i++) {
		ret ^= arry[i];
	}
	ref = ret & (-ret);//找到某数对应的二进制数的最低位‘1’，ref的二进制值为除该位为‘1’外，其余全为0
	for (i=j=k=0; i < 102; i++) {
		if (arry[i] & ref) {
			heap[0][j++] = arry[i];
		}
		else {
			heap[1][k++] = arry[i];
		}
	}
	for (i = 0; i < j; i++) {
		*num1 ^= heap[0][i];
	}
	for (i = 0; i < k; i++) {
		*num2 ^= heap[1][i];
	}
}
int main() {
	int i,num1,num2;
	num1 = num2 = 0;
	int arry[N] = { 0 };
	for (i = 0; i < 50; i++) {
		arry[i] = i;
	}
	for (i = 50; i < 100; i++) {
		arry[i] = i-50;
	}
	arry[100] = 77;
	arry[101] = 99;
	aloneTwo(arry, &num1, &num2);
	printf("孤单的两个数:%d %d\n", num1, num2);
	return 0;
}