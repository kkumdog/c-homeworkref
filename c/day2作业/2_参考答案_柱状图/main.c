#include <stdlib.h>
#include <stdio.h>

void showBarChart(int max, int mid, int min, char (*str)[6]) {
	int i;
	for (i = 0; i < max+1; i++) {
		if (i == 0) {
			printf("%3d   ", max);
		}
		else {
			printf("***** ");
		}
		if (i == max - mid) {
			printf("%3d   ", mid);
		}
		else if (i > max - mid) {
			printf("***** ");
		}
		if (i == max - min) {
			printf("%3d   ", min);
		}
		else if (i > max - min) {
			printf("***** ");
		}
		printf("\n");
	}
	printf("%4s  %4s  %4s  \n", str[0],str[1],str[2]);
}




int main() {
	char c;
	char s[6] = { 0 };
	char str[][6] = { "alp","num","oth" };
	int i, j, temp, max, mid, min;
	enum { alp, num, other };
	int count[3] = { 0 };
	printf("ÇëÊäÈëÒ»Ð©×Ö·û:\n");
	while ((c = getchar()) != '\n') {
		if ((c >= 'A' &&  c <= 'Z') || (c >= 'a' && c <= 'z')) {
			count[alp]++;
		}
		else if (c >= '0' && c <= '9') {
			count[num]++;
		}
		else {
			count[other]++;
		}
	}
	//¼òµ¥½»»»ÅÅÐò
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
	showBarChart(count[0], count[1], count[2], str);
	return 0;
}