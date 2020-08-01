#include <stdio.h>
#include <stdlib.h>

int main() {
	int i,year, month, day,total;
	int base[13] = {0, 31,28,31,30,31,30,31,31,30,31,30,31 };
	while (printf("请输入年 月 日："),scanf("%d %d %d", &year, &month, &day) != EOF) {
		total = 0;
		for (i = 1; i < month; i++) {
			total += base[i];
		}
		total += day;
		if (month > 2) {
			total += (year % 4 == 0 && year % 100 || year % 400 == 0);
		}
		printf("%4d-%02d-%02d是当年的第%d天\n", year,month,day,total);
	}
	return 0;
}