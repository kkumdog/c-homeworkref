#include <stdio.h>
#include <stdlib.h>

int main() {
	char c;
	int d;
begin:
	d = 0;
	printf("请输入二进制:");
	while ( scanf("%c",&c)!= EOF) {
		if (c > '1' || c < '0') {
			if (c != '\n') {
				printf("请输入正确的二进制!\n");
				rewind(stdin);
				goto begin;
			}
		}
		if (c == '\n') {
			printf("对应的十进制:%d\n", d);
			printf("请输入二进制继续或输入ctrl+z结束：");
			d = 0;
		}
		else {
			d = d*2 + c-'0';
		}
	}
	return 0;
}