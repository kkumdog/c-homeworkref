#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50

int main() {
	char str[N + 1] = { 0 };
	char *p, *pre;
	int i = 0,len=0;
	while (printf("ÇëÊäÈëÒ»´®×Ö·û´®:"), rewind(stdin), gets(str)) {
		pre = str;
		p = str + 1;
		while (*p) {
			len = strlen(str);
			i = 0;
			if (*pre != *p) {
				p++;
				pre++;
			}
			else {
				while (*p == *pre) {
					p++;
					i++;
				}
				memmove(pre + 1, p, len - i);
				p = pre + 1;
			}
		}
		puts(str);
	}
	return  0;
}