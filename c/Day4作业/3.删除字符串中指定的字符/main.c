#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50

//�������ظ�Ԫ�������ڵ�
int main() {
	int i,start,len=0;
	char str[N + 1] = { 0 };
	memset(str, 'a', sizeof(str));
	char del = '\0';
	printf("������һ���ַ�:");
	gets(str);
	printf("����������ַ�����ɾ�����ַ�:");
	del=getchar();
	i = start = 0;
	while(str[i]!='\0') {
		len = strlen(str);
		if (str[i] != del) {
			i++;
		}
		else{
			start = i;
			while (str[i] == del) {	
				i++;
			}
			memmove(str + start,str + i, len-i+1);
			i = start;
		}	
	}
	puts(str);
	return 0;
}