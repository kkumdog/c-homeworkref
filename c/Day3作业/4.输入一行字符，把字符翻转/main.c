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
	while (printf("������һ���ַ�:"), rewind(stdin), gets(str) != NULL) {
		len = strlen(str);
		head = 0;
		nohead =1;
		strReverse(str, len);
		printf("��һ�η�ת:%s\n", str);
		for (i = 0; i <=len; i++) {
			if (str[i] != ' '&& nohead==1) {//����ͷ����������ĵ�һ���ǿո��ַ�Ϊͷ
				head=i;
				nohead = 0;
			}
			if (str[i] == ' '&& nohead == 0) {//����ͷ������������ĵ�һ���ո�Ϊβ
				strReverse(str + head, i - head );
				nohead = 1;
			}
			if (i == len ) {//����ѵ��ַ���ĩβ��β����len
				strReverse(str + head, i - head);
			}
		}
		printf("��ת����ַ���:%s\n", str);
	}
	return 0;
}