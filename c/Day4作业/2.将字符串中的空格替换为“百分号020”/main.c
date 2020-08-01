#include <stdio.h>
#include <stdlib.h>
#define N 50

int main() {
	char str[N + 1] = { 0 };
	int isSpace;
	char *p,*q;
	printf("请输入一行包含空格的字符:\n");
	while (gets(str) != NULL) {
		isSpace = 0;
		p = str;
		while (*p) {
			if (*p == ' ') {
				isSpace++;
			}
			p++;
		}
		p = str;
		char *newStr = (char*)malloc(sizeof(str) + 3 * isSpace * sizeof(char)+1);
		q = newStr;
		while (*p) {
			if (*p !=' ') {
				*q++ = *p++;
			}
			else {
				*q = '%';
				*(q + 1) = '2';
				*(q + 2) = '0';
				*(q + 3) = '2';
				q += 4;
				p++;
			}
		}
		*q = '\0';
		puts(newStr);
		free(newStr);
		newStr = NULL;
		return 0;
	}
}