#include <stdio.h>
#include <stdlib.h>
#define N 50

int main() {
	char str[50 + 1] = { 0 };
	int i, j=0;
	char temp='\0';
	int len=0;
	printf("请输入一串包含数字和字母的字符串:\n");
	gets(str);
	len = strlen(str);
	for (i = 1; i<len;i++) {
		if (str[i]>= '0' &&  str[i] <= '9') {
			temp = str[i];
			for (j = i - 1; (!(str[j]>= '0' &&  str[j]<= '9')) && j>=0; j--) {
					str[j + 1] = str[j];
			}
			str[j+1] = temp;
		}
	}
	puts(str);
	return 0;
}