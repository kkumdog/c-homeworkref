#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define N 6

//ʹ�ü�������˼��
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
		printf("û����������\n");
	}
}
int main(){
	int i,arry[N];
	printf("������%d������:\n",N);
	for (i = 0; i < N; i++) {
		scanf("%d", &arry[i]);
	}
	printf("���ִ�������%d����:\n", N / 2);
	elmOverHalf(arry);
	return 0;
}