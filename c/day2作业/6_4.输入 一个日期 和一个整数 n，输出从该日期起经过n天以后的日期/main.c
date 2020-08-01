#include <stdio.h>
#include <stdlib.h>

int isLeapYear(int y) {
	return y % 4 == 0 && y % 100 || y % 400 == 0;
}

int main() {
	int i,year, month, day, n, raw_y, raw_m, raw_d,raw_n,sum=0;
	int mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	printf("请输入年 月 日:");
	scanf("%d%d%d", &year, &month, &day);
	raw_y = year;
	raw_m = month;
	raw_d = day;
	printf("请输入经过的天数:");
	scanf("%d", &n);
	raw_n = n;
	//先计算出该日期距离年初的天数
	for (i = 1; i < month; i++) {
		sum += mon[i];
	}
	if (month > 2 && isLeapYear(year)) {
		sum++;
	}
	sum += day;
	//计算日期
	n += sum;
	while (n < 0) {
		year--;
		n += 365;
		if (isLeapYear(year)) {
			n++;
		}
	}
	for (i = 1; n > mon[i];) {
		n -= mon[i];
		if (i == 2 && isLeapYear(year)) {
			n--;
		}
		i++;
		if (i == 13) {
			i = 1;
			year++;
		}
	}
	printf("%4d-%02d-%02d经过%d天后是%4d-%02d-%02d\n", raw_y, raw_m, raw_d, raw_n, year, i, n);
	return 0;
}