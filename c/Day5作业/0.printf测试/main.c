#include <stdlib.h>
#include <stdio.h>

int main() {
	int num = 0;
	float f = 0;
	char c = 0;
	//scanf("%f\n", &f);//%d����ӿհ׷���scanfҪ��������+�ǿհ׷��Ż����,
	//printf("%f\n", f);
	//while(scanf("%c", &c)!=EOF)
	//	printf("%c ", c);
	scanf("%c", &c);
	printf("%c", c);
}
//���������"2\n",scanf���ŵ�һ���ǿհ��ַ�����ʱ����"\n\n"�����ţ�Ȼ���䡮A\n��scanf����
//�������������е�����:"2\n\n\nA\n",scanf����2�������һ���ǿհ��ַ���
//      �ӻ�����������\n,���ǣ�������ֱ���õ�A�������ˣ��˺󻺳����л�ʣ\n
//ע�⣺����д��scanf("%f\n\n\n", &f)Ҳ��һ���ģ����ܶ��ٸ�\n,��һ���ǿհ׷�����