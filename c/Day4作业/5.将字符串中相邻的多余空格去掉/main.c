#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50

int main() {
	char str[N + 1];
	char *p, *start;
	int i,j=0,len = 0;
	while (printf("请输入一串包含多余空格的字符:"), rewind(stdin), gets(str)) {
		p = str;
		len = strlen(str);
		i = j = 0;
		if (*p == ' ') {//处理最前面的空格
			while (*p == ' ') {
				p++;
				i++;
			}
			memmove(str, p, len+1 - i);
			p = str;
		}
		while (*p) {
			len = strlen(str);
			i = 0;
			if(*p != ' '){
				p++;
				j++;
			}
			else{
				start = p;
				while (*p == ' ') {
					p++;
					i++;
				}
				if (*p) {//*p不是结束符，表示在字符串中间，留一个空格
					memmove(start + 1, p, len + 1 - i - j);
					p = start + 1;
				}
				else {//*p是结束符，表示到达末尾，不留空格
					memmove(start, p, len + 1 - i - j);
					p = start;
				}
				j++;
			}
		}
		puts(str);
	}
	return 0;
}