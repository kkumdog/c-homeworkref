#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define N 100

int getNum(char *str) {
	int i=0;
	char c = '\0';
	while ((c=getchar())!='\n') {
		if (i >N-1) {
			rewind(stdin);
			break;
		}
		if (c >= '0' && c <= '9') {//���ŷŷ����λ����
			str[i++] = c;//�����ԭ��������ֱ�ӱ�Ϊ���֣��罫��0����Ϊ0������ͳ���ַ�������ͽ�����
		}
		else {
			printf("�������!\n");
			rewind(stdin);
			return 0;
		}
	}
	return 1;
}

void largeNumAdd(char* num1,char* num2,char* sum) {
	int i,j,k,len = 0;
	for (i = 0; num1[i]; i++) {
		num1[i] -= '0';
	}
	for (j = 0; num2[j]; j++) {
		num2[j] -= '0';
	}
	len = i >= j ? i : j;
	for (k = 0;k<len ; k++) {
		sum[k] = num1[k] + num2[k];
	}
	for (i = 0; i < len; i++) {
		if (sum[i] > 9) {
			sum[i] = sum[i] % 10;
			sum[i + 1] += 1;
			if (i == len - 1) {
				sum[i + 1] += '0';//�����λ��a[len],��Ҫ��a[len]Ҳ��Ϊ�ַ����
			}
		}
		sum[i] += '0';//ÿ����һλ�ͽ����Ϊ�ַ�����ֹ����'\0'���޷����
	}
	len = strlen(sum);
	for (i = len - 1; i >= 0; i--) {
		printf("%c", sum[i]);
	}
	printf("\n");
}


//�����������ӷ�
int main() {
	char num1[N + 1] = { 0 }, num2[N + 1] = {0}, buff[N + 1] = { 0 };
	char sum[N + 2] = { 0 };//����������λ����ΪNʱ�����ΪN+1λ
	int i,j,len1=0,len2=0,lenSum=0;
	while (1) {
	input1:
		printf("�������һ����λ����:");
		memset(buff, 0, sizeof(buff));
		if (!getNum(buff)) {
			goto input1;
		}
		memset(num1, 0, sizeof(num1));
		for (i = 0, j = strlen(buff) - 1; j >= 0;) {//�������Ŵ棬�����λ����
			num1[i++] = buff[j--];
		}
	input2:
		printf("������ڶ�����λ����:");
		memset(buff, 0, sizeof(buff));
		if (!getNum(buff)) {
			goto input2;
		}
		memset(num2, 0, sizeof(num2));
		for (i = 0, j = strlen(buff) - 1; j >= 0;) {
			num2[i++] = buff[j--];
		}
		memset(sum, 0, sizeof(sum));
		printf("����֮��Ϊ:");
		largeNumAdd(num1, num2, sum);
	}
	return 0;
}