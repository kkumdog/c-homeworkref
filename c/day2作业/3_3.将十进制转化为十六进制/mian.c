#include <stdio.h>
#include <stdlib.h>
#define N 8

void decToHex(int n) {
	char str[N + 1];
	int i, m,remainder;
	m = 0;
	for (i = 0; i < N + 1; i++) {
		str[i] = '0';
	}
	if (0 == n) {
		printf("%c\n", '0');
	}
	if(n<0){
		m = n;
		n = -n;
	}
	i = 0;
	while (n) {
		remainder = n % 16;
		n /= 16;
		if (remainder > 9) {
			str[i++]=remainder+55;
		}
		else {
			str[i++] = remainder + '0';
		}
	}
	if (m < 0) {
		printf("%c", '-');
	}
	while (i) {
		printf("%c", str[--i]);
	}
	printf("\n");
}

 int main() {
	 int n;
	 while (printf("请输入一个十进制整数："),scanf("%d", &n) != EOF) {
		 decToHex(n);
	 }
	return 0;
}