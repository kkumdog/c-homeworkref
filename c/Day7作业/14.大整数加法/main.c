#include "func.h"

//两个大整数加法
int main() {
	lineList num1, num2, sum;
	//while (1) {
input1:
	memset(&num1, 0, sizeof(lineList));
	printf("请输入第一个大位整数:");
	if (!getNum(&num1)) {
		goto input1;
	}
input2:
	memset(&num2, 0, sizeof(lineList));
	printf("请输入第二个大位整数:");
	if (!getNum(&num2)) {
		goto input2;
	}
	memset(&sum, 0, sizeof(lineList));
	largeNumAdd(&num1, &num2, &sum);
	printf("两数之和为:");
	listPrint(sum);
	listDestory(&num1);
	listDestory(&num2);
	listDestory(&sum);//注意：若sum和num1或num2有重叠时，会重复free已经free过的结点。本程序只解决了在win32平台下可能出现的该问题。
	return 0;
}