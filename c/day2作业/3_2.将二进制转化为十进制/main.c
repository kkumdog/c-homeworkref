#include <stdio.h>
#include <stdlib.h>

int main() {
	char c;
	int d;
begin:
	d = 0;
	printf("�����������:");
	while ( scanf("%c",&c)!= EOF) {
		if (c > '1' || c < '0') {
			if (c != '\n') {
				printf("��������ȷ�Ķ�����!\n");
				rewind(stdin);
				goto begin;
			}
		}
		if (c == '\n') {
			printf("��Ӧ��ʮ����:%d\n", d);
			printf("����������Ƽ���������ctrl+z������");
			d = 0;
		}
		else {
			d = d*2 + c-'0';
		}
	}
	return 0;
}