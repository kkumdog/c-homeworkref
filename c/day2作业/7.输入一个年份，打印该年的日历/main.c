#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf env;

void inputCheck(int y) {
	if (y < 1 || y > 9999) {
		printf("请输入一个正确的年份(1-9999)\n");
		longjmp(env, 1);
	}
}

int isLeapYear(int y) {
	return y % 4 == 0 && y % 100 || y % 400 == 0;
}

//计算给定日期是该年的第几天
int dayRank(int y, int m, int d) {
	int i, sum = 0;
	int mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	for (i = 1; i < m; i++) {
		sum += mon[i];
	}
	if (i > 2 && isLeapYear(y)) {
		sum++;
	}
	sum += d;
	return sum;
}

//计算给定日期是星期几
int whatWeekDay(int y, int m, int d) {//基准日期：2020-03-01：星期天
	int i, rank, baserank, baseyear, distance;
	rank = baserank = distance = 0;
	baseyear = 2020;
	//计算输入日期距基准日期的距离
	rank = dayRank(y, m, d);
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
	if (i == 0) {
		i = 7;
	}
	return i;
}

//横向打印两个月的日历
void showTwoMonCalender(int y, int m) {
	int i, j, k,interrupt1, interrupt2,weekDay1,weekDay2,flag,addSpace;
	weekDay1 = weekDay2 = flag = 0;
	addSpace = 1;//用于控制第二个月份前是否添加空格
	int mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	printf("|%2d  MON TUS WED THU FRI SAT SUN%3d  MON TUS WED THU FRI SAT SUN |\n", m, m + 1);
	weekDay1 = whatWeekDay(y, m, 1);
	weekDay2 = whatWeekDay(y, m + 1, 1);
	interrupt1 = weekDay1;
	interrupt2 = weekDay2;
	if (m+1 == 2) {
		flag = isLeapYear(y);
	}
	printf("|   ");//一共4个
	for (k = 0; k < weekDay1 - 1; k++) { //打印第一行左侧可能的空格
		printf("    ");//4个
	}
	i = j = 1;
	while (i <= mon[m] || j <= mon[m + 1]) {
		if (i != 1) {
			printf("|   ");//一共4个
		}
		while (1) {
			if (i <= mon[m]) {
				printf("%4d", i);
				i++;
			}
			else {
				printf("    ");//4个
			}
			if (interrupt1 % 7 == 0) {
				interrupt1++;
				break;
			}
			interrupt1++;
		}
		printf("    ");//打印间隔4个
		if (addSpace) {//第二个月份只有第一行可能需要添加空格
			for (k = 0; k < weekDay2 - 1; k++) { 
				printf("    ");//4个
			}
			addSpace = 0;
		}
		while(1){
			if (j <= mon[m+1] + flag) {
				printf("%4d", j);
				j++;
			}
			else {
				printf("    ");//4个
			}
			if (interrupt2 % 7 == 0) {
				interrupt2++;
				printf(" |\n");
				break;
			}
			interrupt2++;
		}
	}

}

//打印某年的日历
void showCalenderOfYear(int y) {
	int month=1;
	printf("|-------------------The Calender Of Year %d-------------------\n", y);
	while (month <= 11) {
		showTwoMonCalender(y, month);
		month +=2;
	}
}

int main() {
	int year;
	setjmp(env);
	while (printf("请输入一个年份："),rewind(stdin), scanf("%d", &year)) {
		inputCheck(year);
		showCalenderOfYear(year);
	}
	return 0;
}