#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isLeapYear(int year) {
	return year % 4 == 0 && year % 100 || year % 400 == 0;
	printf("%d\n������\n", year);
}
int main() {
	int i,j,distance,temp;
	int year[2] = { 0 }, month[2] = { 0 }, day[2] = { 0 }, len[2] = {0};
	int base[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	for (i = 0; i < 2; i++) {
		//��ȡ����
		printf("�������%d������\n", i+1);
	l_year:
		printf("��(1-9999):");
		scanf("%d", &year[i]);
		rewind(stdin);
		if (year[i] <= 0 || year[i] > 9999) {
			printf("��������ȷ�����\n");
			goto l_year;
		}
	l_mon:
		printf("��(1-12):");
		scanf("%d", &month[i]);
		rewind(stdin);
		if (month[i] < 1 || month[i] > 12) {
			printf("��������ȷ���·�\n");
			goto l_mon;
		}
	l_day:
		printf("��(1-31):");
		scanf("%d", &day[i]);
		rewind(stdin);
		if (day[i] < 1 || day[i] > 32) {
			printf("��������ȷ������\n");
			goto l_day;
		}
		if (day[i] > 28) {
			if (month[i] == 2) {
				if (!isLeapYear(year[i])) {
					printf("%d��%d��û�и����ڣ�����������\n", year[i], month[i]);
					goto l_day;
				}
				else{
					if(day[i]!=29){
						printf("%d��%d��û�и����ڣ�����������\n", year[i], month[i]);
						goto l_day;
					}
				}
			}
			if (month[i] == 4 || month[i] == 6 || month[i] == 9 || month[i] == 11) {
				if (day[i] > 30) {
					printf("%d��%d��û�и����ڣ�����������\n", year[i], month[i]);
					goto l_day;
				}
			}
		}
		distance = 0;
		//�����i�������Ǹ���ĵڼ���
		for (j = 1; j < month[i]; j++) {
			len[i] += base[j];
		}
		if (month[i] > 2 && isLeapYear(year)) {
			len[i] += 1;
		}
		len[i] += day[i];
	}
	//��������֮����������
	if (year[0] > year[1]) {
		for (i = year[1]; i < year[0]; i++) {
			distance += 365;
			if (isLeapYear(i)) {
				distance += 1;
			}
		}
		distance += len[0] - len[1];
	}
	else if(year[0] < year[1]){
		for (i = year[0]; i < year[1]; i++) {
			distance -= 365;
			if (isLeapYear(i)) {
				distance -= 1;
			}
		}
		distance += len[0] - len[1];
	}
	else {
			distance += len[0] - len[1];
	}
	printf("%4d-%02d-%02d��%4d-%02d-%02d���%d��\n", year[0], month[0], day[0], year[1], month[1], day[1], distance);
	return 0;
}
