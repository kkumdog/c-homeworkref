#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50

//数组中重复元素是相邻的
int main() {
	int i,start,len=0;
	char str[N + 1] = { 0 };
	memset(str, 'a', sizeof(str));
	char del = '\0';
	printf("请输入一串字符:");
	gets(str);
	printf("请输入想从字符串中删除的字符:");
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