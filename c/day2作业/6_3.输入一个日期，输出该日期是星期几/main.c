#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <math.h>
#define DEBUG 0
jmp_buf env;

int isLeapYear(int y) {
	return y % 4 == 0 && y % 100 || y % 400 == 0;
}

void inputCheck(int year, int month, int day) {
	int mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (year<= 0 || year>9999) {
		printf("请输入正确的年份(0-9999)!\n");
		longjmp(env,1);
	}
	if (day <= 0 || day > 31) {
		printf("%4d-%02d没有%02d天，请重新输入正确的日期!\n", year, month, day);
		longjmp(env, 2);
	}
	if (day > 28) {
		if (month == 2) {
			if (!isLeapYear(year)) {
				printf("%4d-%02d没有%02d天，请重新输入正确的日期!\n", year, month, day);
				longjmp(env, 3);
			}
			else {
				if (day > 29) {
					printf("%4d-%02d没有%02d天，请重新输入正确的日期!\n", year, month, day);
					longjmp(env, 4);
				}
			}
		}
		if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day > 30) {
				printf("%4d-%02d没有%02d天，请重新输入正确的日期!\n", year, month, day);
				longjmp(env, 5);
			}
		}
	}
}

int whichDay(int year,int month,int day){
	int mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int i,total=0;
	for (i = 1; i < month;i++) {
		total += mon[i];
	}
	total += day;
	if (month > 2 && isLeapYear(year)) {
		total += 1;
	}
	if(DEBUG && printf("%4d-%02d-%02d 是%4d的第%02d天\n", year, month, day, year, total));
	return total;
}

int main() {
	int i,year, month, day,baseyear,len,baselen,distance;
	int mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	char week[7][12] = { "sunday","monday","tuesday","wednesday","thursday","friday","saturday" };
	year = month = day = 0;
	setjmp(env);
	while (printf("请输入年月日："),rewind(stdin), scanf("%d%d%d", &year, &month, &day) != EOF) {
		inputCheck(year, month, day);
		distance = len = baselen = 0;
		baseyear = 2020;
		//计算给定日期相距基准日期(2020-03-01：星期天)多少天
		len = whichDay(year, month, day);
		baselen = whichDay(2020, 3, 1);
		if (year < baseyear) {
			for (i = year; i < baseyear; i++) {
				distance -= 365;
				if (isLeapYear(i)) {
					distance -= 1;
				}
			}
			distance += len - baselen ;
		} 
		else if(year > baseyear) {
			for (i = baseyear; i < year; i++) {
				distance += 365;
				if (isLeapYear(i)) {
					distance += 1;
				}
			}
			distance += len-baselen;
		}
		else {
			distance += len- baselen;
		}
		if(DEBUG && printf("%4d-%02d-%02d 距离 %4d-%02d-%02d %d天\n", year, month, day, 2020, 3, 1,distance));
		//计算星期几
		if (distance >= 0) {//如果在基准日期之后
			i = distance % 7;
		}
		else {
			i = (7 - (-distance)%7 ) % 7;
		}
		printf("%4d-%02d-%02d is %s\n",year, month, day, week[i]);
		}
	return 0;
}

/*
		if (raw_year > raw_baseyear){////如果日期在基准日期之后
			i = distance % 7;
		}
		else if(raw_year == raw_baseyear){
			if (len > baselen) {
				i = distance % 7;
			}
			else {
				i = (7 - distance % 7) % 7;
			}
		}
		else {
			i = (7 - distance % 7) % 7;
		}
		printf("%4d-%02d-%02d is %s\n", year, month, day, week[i]);
*/