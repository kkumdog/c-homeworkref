#include <stdlib.h>
#include <stdio.h>

int main() {
	int a[3] = { 6,8,9 }, b[3]= {6,8,9};
	int *p,i,j=0;
	p = a;
	printf("原数组:\n");
	for (i = 0; i < 3; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	j=*p++;
	printf("执行j=*p++后数组变为\n");
	for (i = 0; i < 3; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("j=%d,*p=%d\n", j, *p);
	p = b;
	j = (*p)++;
	printf("执行j=(*p)++后数组变为\n");
	for (i = 0; i < 3; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");
	printf("j=%d,*p=%d\n", j, *p);
	return 0;
}