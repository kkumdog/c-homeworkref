#include <stdio.h>
#include <stdlib.h>
#define N 103
#define DEBUG 0

void aloneTwo(short arry[], int len,short *num1, short *num2) {
	short i,ret, ref;
	ret = ref = 0;
	for (i = 0; i < len; i++) {
		ret ^= arry[i];
		if (DEBUG) {
			printf("%d ", arry[i]);
		}
	}
	if (DEBUG) {
		printf("\n");
	}
	ref = ret & (-ret);//�ҵ�ĳ����Ӧ�Ķ������������λ��1����ref�Ķ�����ֵΪ����λΪ��1���⣬����ȫΪ0
	for (i = 0; i < len; i++) {
		if (arry[i] & ref) {
			*num1 ^= arry[i];
		}
		else {
			*num2 ^= arry[i];
		}
	}

}

void aloneThree(short arry[], short *num1, short *num2, short *num3) {
	short i,j,ret1,ret2,ref;
	short countHeap1,countHeap2;
	ref=0;
	short heap[2][N] = { {0},{0} };
	for (i = 0; i < 16; i++) {
		countHeap1 = countHeap2 = 0;
		ret1 = ret2 = 0;
		ref = 1<<i;
		if(DEBUG)
			printf("��%d��:\n",i);
		for (j = 0; j < N; j++) {
			if (arry[j] & ref) {
				heap[0][countHeap1++] = arry[j];
				ret1 ^= arry[j];
			}
			else {
				heap[1][countHeap2++] = arry[j];
				ret2 ^= arry[j];
			}
		}
		if (DEBUG) {
			for (j = 0; j < countHeap1; j++) {
				printf("%d ", heap[0][j]);
			}
			printf("\n");
			for (j = 0; j < countHeap2; j++) {
				printf("%d ", heap[1][j]);
			}
			printf("\n");
		}
		//��������һ�ѵ�����ż���������Ϊ0��������һ���¶���һ���ڵڶ���
		if ((0 == countHeap1 % 2) && (ret1 != 0)) {
			*num1 = ret2;
			aloneTwo(heap[0], countHeap1,num2, num3);
			break;
		}
		//�������ڶ��ѵ�����ż���������Ϊ0��������һ���¶���һ���ڵ�һ��
		else if ((0 == countHeap2 % 2) && (ret2 != 0)) {
			*num1 = ret1;
			aloneTwo(heap[1],countHeap2,num2, num3);
			break;
		}
	}
}
int main() {
	short i, num1, num2,num3;
	num1 = num2 = num3 = 0;
	short arry[N] = { 0 };
	for (i = 0; i < 50; i++) {
		arry[i] = i;
	}
	for (i = 50; i < 100; i++) {
		arry[i] = i - 50;
	}
	arry[100] = 55;
	arry[101] = 64;
	arry[102] = 99;
	aloneThree(arry, &num1, &num2, &num3);
	printf("�¶���������:%d %d %d\n", num1, num2, num3);
	return 0;
}