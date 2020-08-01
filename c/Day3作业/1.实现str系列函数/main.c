#include <stdio.h>
#include <stdlib.h>
#define N 50

int myStrlen(const char s[]) {
	int i;
	for (i = 0; s[i] != '\0'; i++);
	return i;
}

int myStrcmp(const char s1[], const char s2[]) {
	int i;
	for (i = 0; s1[i] == s2[i] && i<N; i++);
	if (s1[i] > s2[i]) {
		printf("%s > %s\n", s1, s2);
		return 1;
	}
	else if (s1[i] < s2[i]) {
		printf("%s < %s\n", s1, s2);
		return -1;
	}
	else {
		printf("%s = %s\n", s1, s2);
		return 0;
	}
}

void myStrcpy(char to[], const char from[]) {//不安全
	int i,len=0;
	len = myStrlen(from);
	for (i = 0; i < len + 1;i++ ) {
		to[i] = from[i];
	}
	to[i] = '\0';
}

void myStrcat(char ret[], const char s[]) {
	int i,j,len1=0,len2=0;
	len1 = myStrlen(ret);
	len2 = myStrlen(s);
	for (i = 0,j=len1; i < len2;) {
		if (j == N) {
			break;
		}
		ret[j++] = s[i++];
	}
}

int main() {
	char str[2][N+1] = { 0 };
	char temp[N + 1] = { 0 };
	while (printf("请输入两个字符串，每个以换行结束:\n"),gets(str[0])!= NULL && gets(str[1]) != NULL) {
		int i;
		printf("1.字符串长度:%s=%d  %s=%d\n", str[0], myStrlen(str[0]), str[1], myStrlen(str[1]));
		printf("2.按ASIII码比较：");
		myStrcmp(str[0], str[1]);
		myStrcpy(temp, str[0]);
		myStrcpy(str[0], str[1]);
		myStrcpy(str[1], temp);
		printf("3.交换两个字符串:\n%s\n%s\n", str[0], str[1]);
		myStrcat(str[0], str[1]);
		printf("4.将两个字符串拼接起来:%s\n",str[0]);

	}
	return 0;
}