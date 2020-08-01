#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define N 6

//使用计数排序思想
void elmOverHalf(int arry[]) {
	int i, max;
	bool flag = false;
	max = arry[0];
	for (i = 1; i < N; i++) {
		if (arry[i] > max) {
			max = arry[i];
		}
	}
	max++;
	int* countArry=(int*)malloc(max*sizeof(int));
	memset(countArry,0,max*sizeof(int));
	for (i = 0; i < N;i++ ) {
		countArry[arry[i]]++;
	}
	for (i = 0; i < max; i++) {
		if (countArry[i] > N/2) {
			printf("%d", i);
			flag = true;
		}
	}
	free(countArry);
	if (flag == false) {
		printf("没有这样的数\n");
	}
}
int main(){
	int i,arry[N];
	printf("请输入%d个整数:\n",N);
	for (i = 0; i < N; i++) {
		scanf("%d", &arry[i]);
	}
	printf("出现次数超过%d的数:\n", N / 2);
	elmOverHalf(arry);
	return 0;
}