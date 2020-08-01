#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showBatChart(int max,int mid,int min,char str[][6]) {
	int i;
	if (max == mid) {
		if (max == min) {
			printf("  %d       %d       %d\n",max,mid,min);
		}
		else {
			printf("  %d     %d\n",max,mid);
		}
	}
	else {
		printf("  %d\n",max);
	}
	for (i = 0; i < max - mid - 1;i++) {
		printf("*****\n");
	}
	if (max != mid) {
		if (mid == min) {
			printf("*****     %d       %d\n", mid, min);
		}
		else {
			printf("*****     %d\n", mid);
		}
	}
	for (i = 0; i < mid - min - 1;i++) {
		printf("*****   *****\n");
	}
	if (mid != min) {
		printf("*****   *****     %d\n", min);
	}
	for (i = 0; i < min; i++) {
		printf("*****   *****   *****\n");
	}
	printf("%s      %s     %s\n", str[0], str[1], str[2]);
}
int main() {
	char c;
	char s[6] = { 0 };
	char str[][6] = { "alp","num","oth" };
	int i,j,temp,max, mid, min;
	enum { alp, num, other };
	int count[3] = {0};
	printf("请输入一些字符:\n");
	while ( (c=getchar()) !='\n') {
		if ((c>='A' &&  c<='Z') || (c>='a' && c<='z'))  {
			count[alp]++;
		}
		else if (c >= '0' && c <= '9') {
			count[num]++;
		}
		else {
			count[other]++;
		}
	}
	//简单交换排序
	for (i = 0; i < 2; i++) {
		for (j = i + 1; j < 3; j++) {
			if (count[i] < count[j]) {
				temp = count[i];
				count[i] = count[j];
				count[j] = temp;
				strcpy(s, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], s);
			}
		}
	}
	showBatChart(count[0],count[1],count[2],str);
	return 0;
}

/*	三目运算符求三数大小
	max = (alp > num) ? ((alp > other) ? alp : num) : (num > other ? num : other);
	min = (alp < num) ? ((alp < other) ? alp : other) : (num < other ? num :other );
	mid = (alp > num) ? (num > other ? num : (num < other ? num : other)) : (num < other ? num : (alp > other ? alp : other));
*/

/*简单插入排序
void insertSort(int arry[], int n) {
	int i,j,temp;
	for (i = 1; i < n; i++) {
		if (arry[i] < arry[i - 1]) {
			temp = arry[i];
			for (j = i - 1; arry[j] > temp && j>=0; j--) {
				arry[j + 1] = arry[j];
			}
			arry[++j] = temp;
		}
	}
}
*/