#include "func.h"

//�����������ӷ�
int main() {
	lineList num1, num2, sum;
	//while (1) {
input1:
	memset(&num1, 0, sizeof(lineList));
	printf("�������һ����λ����:");
	if (!getNum(&num1)) {
		goto input1;
	}
input2:
	memset(&num2, 0, sizeof(lineList));
	printf("������ڶ�����λ����:");
	if (!getNum(&num2)) {
		goto input2;
	}
	memset(&sum, 0, sizeof(lineList));
	largeNumAdd(&num1, &num2, &sum);
	printf("����֮��Ϊ:");
	listPrint(sum);
	listDestory(&num1);
	listDestory(&num2);
	listDestory(&sum);//ע�⣺��sum��num1��num2���ص�ʱ�����ظ�free�Ѿ�free���Ľ�㡣������ֻ�������win32ƽ̨�¿��ܳ��ֵĸ����⡣
	return 0;
}