#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define N 50

int main() {
	char str[N + 1] = {0};
	int i,j,len,total,flag;
	i = len = total = flag = 0;
	while (printf("������һ���ַ�:"),rewind(stdin), gets(str) != NULL){
		len = strlen(str);
		for (i = 0; i < len; i++) {
			if (str[i] == ' '&& flag) {
				total++;
				flag = 0;
			}
			else {
				flag = 1;
			}
		}
		printf("���й�����%d������\n", total);
	}
	return 0;
}