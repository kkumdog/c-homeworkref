#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[]) {
	int ret=0;
	char c;
	FILE *fpIn = fopen(argv[1], "r");
	FILE *fpOut = fopen(argv[2], "w+");
	if (NULL == fpIn || NULL==fpOut) {
		perror("fopen");
		return;
	}
	c = fgetc(fpIn);
	if (EOF == c) {
		perror("fgetc");
		return;
	}
	while (c != EOF) {
		if (c >= 'A' && c <= 'Z') {
			c = c + 32;
		}
		else if (c <= '9' && c >= '0' || (c>='a' && c<= 'z')|| c == '\n' );
		else{
			c = ' ';
		}
		putchar(c);
		fputc(c,fpOut);
		fseek(fpOut, 0, SEEK_CUR);
		c = fgetc(fpIn);
	}
	fclose(fpIn);
	fclose(fpOut);
	return 0;
}