#include <stdio.h>
#include <stdlib.h>
#define N 32

int countOne(int n) {
	int i,j,count;
	j=N,count = 0;
	while (j--) {
		i = n & 1;
		n = n >> 1;
		if (i == 1) {
			count++;
		}
	}
	return count;
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		printf("��Ӧ�Ķ�������1�ĸ�����%d\n",countOne(n));
	}
	return 0;
}