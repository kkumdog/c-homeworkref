#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf env;
int mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
char week[7][12] = { "sunday","monday","tuesday","wednesday","thurday","friday","saturday" };

void inputCheck(int y,int m){
	if (y > 9999 || y <1) {
		printf("请输入正确的年份(1-9999)!\n");
		longjmp(env, 1);
	}
	if (m <1 || m > 12) {
		printf("请输入正确的月份(1-12)!\n");
		longjmp(env, 2);
	}
}
int isLeapYear(int y) {
	return y % 4 == 0 && y % 100 || y % 400 == 0;
}

int dayRank(int y, int m, int d) {
	int i,sum=0;
	for (i = 1; i < m; i++) {
		sum += mon[i];
	}
	if (i > 2 && isLeapYear(y)) {
		sum++;
	}
	sum += d;
	return sum;
}
//基准日期：2020-03-01：星期天
int whatWeekDay(int y, int m, int d) {
	int i,rank, baserank,baseyear,distance;
	rank = baserank = distance = 0;
	baseyear = 2020;
	//计算输入日期距基准日期的距离
	rank=dayRank(y, m, d);
	baserank = dayRank(2020, 3, 1);
	if (y > baseyear) {
		for (i = baseyear; i < y; i++) {
			distance += 365;
			if (isLeapYear(i)) {
				distance++;
			}
		}
		distance += rank - baserank;
	}
	else if (y < baseyear) {
		for (i = y; i < baseyear; i++) {
			distance -= 365;
			if (isLeapYear(i)) {
				distance--;
			}
		}
		distance += rank - baserank;
	}
	else {
		distance += rank - baserank;
	}
	//计算输入日期是星期几
	if (distance >= 0) {
		i = distance % 7;
	}
	else {
		i = (7 - (-distance % 7)) % 7;
	}
//	printf("%4d-%02d-%02d is %s\n", y, m, d, week[i]);
	return i;
}

void showCalender(int y, int m) {
	int i,j,flag=0,weekDay = 0;
	weekDay= whatWeekDay(y, m, 1);
	if (weekDay == 0) {
		weekDay = 7;
	}
	printf("MON TUS WED THR FRI SAT SUN\n");
	for (i = 0; i < weekDay-1; i++) {
		printf("    ");
	}
	if (m == 2) {
		flag = isLeapYear(y);
	}
	for (i = 1,j=weekDay; i <= mon[m]+flag; i++,j++) {
		printf("%-4d", i);
		if (j % 7 == 0) {
			printf("\n");
		}
	}
	printf("\n");
}
int main() {
	int year, month,weekDay=0;
	setjmp(env);
	while (printf("请输入年月:"),rewind(stdin),scanf("%d%d", &year, &month)!=EOF) {
		inputCheck(year,month);
		showCalender(year, month);
	}
	return 0;
}