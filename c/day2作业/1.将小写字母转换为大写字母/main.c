#include <stdio.h>
#include <stdlib.h>

int main() {
	char c;
	printf("ÇëÊäÈëĞ¡Ğ´×ÖÄ¸£º\n");
	while (scanf("%c", &c) != EOF) {
		if (c <= 'z' && c >= 'a') {
			printf("%c", c - 32);
		}
	}
	return 0;
}