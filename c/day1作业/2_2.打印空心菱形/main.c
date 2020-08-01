#include <stdio.h>
#include <stdlib.h>

void diamondprint2(int n) {
	int i,j,k;
	//打印上半部分
	for (i = 1; i <= n; i++) {
		for (j = n - i; j > 0; j--) {
			printf(" ");
		}
		printf("*");
		if (i == 1) {
			printf("\n");
			continue;
		}
		k = 2*i-3;
		while(k--){
			printf(" ");
		}
		printf("*\n");
	}
	//打印下半部分
	for (i = 1; i <=n-1; i++){
		j = i;
		while(j--){
			printf(" ");
		}
		printf("*");
		if (i != n-1) {
			k = 2*(n-i)-3;
			while (k--) {
				printf(" ");
			}
			printf("*\n");
		}
		else {
			printf("\n");
		}
	}
}

int main(){
	int n;
	printf("请输入行数：");
	scanf("%d", &n);
	diamondprint2(n);
	return 0;
}