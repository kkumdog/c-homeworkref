#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50

int main() {
	char str[N + 1];
	char *p, *start;
	int i,j=0,len = 0;
	while (printf("������һ����������ո���ַ�:"), rewind(stdin), gets(str)) {
		p = str;
		len = strlen(str);
		i = j = 0;
		if (*p == ' ') {//������ǰ��Ŀո�
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
				if (*p) {//*p���ǽ���������ʾ���ַ����м䣬��һ���ո�
					memmove(start + 1, p, len + 1 - i - j);
					p = start + 1;
				}
				else {//*p�ǽ���������ʾ����ĩβ�������ո�
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