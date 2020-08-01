#include <stdio.h>
#include <stdlib.h>
#define N 50

int main() {
	char str[N + 1] = { 0 };
	printf("ÇëÊäÈëÒ»ĞĞ×Ö·û´®:");
	while (scanf("%s", str)) {
		printf("%s\n", str);
	}
	return 0;
}