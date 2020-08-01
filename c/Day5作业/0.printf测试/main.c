#include <stdlib.h>
#include <stdio.h>

int main() {
	int num = 0;
	float f = 0;
	char c = 0;
	//scanf("%f\n", &f);//%d后面接空白符，scanf要读到数字+非空白符才会结束,
	//printf("%f\n", f);
	//while(scanf("%c", &c)!=EOF)
	//	printf("%c ", c);
	scanf("%c", &c);
	printf("%c", c);
}
//如键盘输入"2\n",scanf卡着等一个非空白字符，此时再输"\n\n"还卡着，然后输‘A\n’scanf结束
//分析：缓冲区中的数据:"2\n\n\nA\n",scanf读到2后继续等一个非空白字符，
//      从缓冲区中拿走\n,不是，丢弃，直到拿到A，结束了，此后缓冲区中还剩\n
//注意：上面写成scanf("%f\n\n\n", &f)也是一样的，不管多少个\n,等一个非空白符结束