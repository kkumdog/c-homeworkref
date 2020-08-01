#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define N 50

void strReverse(char str[],int len) {
	int i,j;
	char c = '\0';
	for (i = 0, j = len - 1; i < j; i++,j--) {
		c = str[i];
		str[i] = str[j];
		str[j] = c;
	}
}
int main() {
	char str[N + 1] = { 0 };
	int i,head,nohead,len=0;
	while (printf("请输入一串字符:"), rewind(stdin), gets(str) != NULL) {
		len = strlen(str);
		head = 0;
		nohead =1;
		strReverse(str, len);
		printf("第一次翻转:%s\n", str);
		for (i = 0; i <=len; i++) {
			if (str[i] != ' '&& nohead==1) {//在无头情况下遇到的第一个非空格字符为头
				head=i;
				nohead = 0;
			}
			if (str[i] == ' '&& nohead == 0) {//在有头的情况下遇到的第一个空格为尾
				strReverse(str + head, i - head );
				nohead = 1;
			}
			if (i == len ) {//如果已到字符串末尾，尾就是len
				strReverse(str + head, i - head);
			}
		}
		printf("翻转后的字符串:%s\n", str);
	}
	return 0;
}