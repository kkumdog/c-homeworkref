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
		if (c >= '0' && c <= '9') {//倒着放方便低位对齐
			str[i++] = c;//保存成原样，不能直接变为数字，如将‘0’变为0，后续统计字符串到这就结束了
		}
		else {
			printf("输入错误!\n");
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
				sum[i + 1] += '0';//如果进位到a[len],需要将a[len]也变为字符输出
			}
		}
		sum[i] += '0';//每调整一位就将其变为字符，防止出现'\0'，无法输出
	}
	len = strlen(sum);
	for (i = len - 1; i >= 0; i--) {
		printf("%c", sum[i]);
	}
	printf("\n");
}


//两个大整数加法
int main() {
	char num1[N + 1] = { 0 }, num2[N + 1] = {0}, buff[N + 1] = { 0 };
	char sum[N + 2] = { 0 };//当两个数的位数都为N时，结果为N+1位
	int i,j,len1=0,len2=0,lenSum=0;
	while (1) {
	input1:
		printf("请输入第一个大位整数:");
		memset(buff, 0, sizeof(buff));
		if (!getNum(buff)) {
			goto input1;
		}
		memset(num1, 0, sizeof(num1));
		for (i = 0, j = strlen(buff) - 1; j >= 0;) {//将数倒着存，方便个位对齐
			num1[i++] = buff[j--];
		}
	input2:
		printf("请输入第二个大位整数:");
		memset(buff, 0, sizeof(buff));
		if (!getNum(buff)) {
			goto input2;
		}
		memset(num2, 0, sizeof(num2));
		for (i = 0, j = strlen(buff) - 1; j >= 0;) {
			num2[i++] = buff[j--];
		}
		memset(sum, 0, sizeof(sum));
		printf("两数之和为:");
		largeNumAdd(num1, num2, sum);
	}
	return 0;
}