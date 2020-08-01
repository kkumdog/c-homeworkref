#include <stdio.h>
#include <stdlib.h>

int main() {
	char c;
	long long dec = 0;
begin:
	printf("请输入十六进制数:\n");
	while (scanf("%c", &c)) {
		if (c >='0' && c<='9' ) {
			dec = dec * 16 + c-'0';
		}
		else if (c >= 'A' && c <= 'F') {
			dec = dec * 16 + c - 55;
		}
		else if (c >= 'a' && c <= 'f') {
			dec = dec * 16 + c - 87;
		}
		else if (c=='\n') {
			printf("%lld\n", dec);
			dec = 0;
		}
		else {
			rewind(stdin);
			printf("输入的十六进制数有误！\n");
			goto begin;
		}
	}
	return 0;
}