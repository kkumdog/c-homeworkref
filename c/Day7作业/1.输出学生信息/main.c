#include "func.h"
#define N 5 

typedef pStu pStuArray[N];

int main(){
	int i,id=0,ret=0;
	char name[24] = {0};
	float score1=0,score2=0,score3=0;
	pStu pstuArray[N];
	memset(pstuArray,0,sizeof(pstuArray));
	printf("������%d��ѧ������Ϣ:\n",N);
	i = 0;
	while (i<5 && (ret=scanf("%d%s%f%f%f", &id, name, &score1,&score2, &score3))!=EOF) {//����ֱ�Ӵ�txt�ļ����ƶ������ݹ�������ʱ�൱�ڶ��ļ�
		if (ret !=5 ) {//ע������%f�������հ׷���������������ȱʧ�ĵط�Ҫ��*����,����������ȷ�����������
			printf("��%d��������ȱʧ�����޸ĺ����µ�����������\n",i+1);
			//rewind(stdin);//���ڴӼ��±����ƹ����Ķ������ݣ�ÿ�����ֻ�����һ�е����ݣ�Ҳ��������\n����Ϊ������������ֻ�������\n�����ݣ��´�ѭ�����������������½��뻺����
			//while ((c=getchar())!=EOF) {
			//	putchar(c);
			//}
			return -1;
		}
		pStu pNew = (pStu)calloc(1, sizeof(stu));
		pNew->id = id;
		strcpy(pNew->name, name);
		pNew->score[0] = score1;
		pNew->score[1] = score2;
		pNew->score[2] = score3;
		pstuArray[i++] = pNew;
	}
//	sortById(pstuArray, N);
//	sortByscore(pstuArray, N);
//	showAllInfo(pstuArray, N);
	showBestInfo(pstuArray, N);
	destory(pstuArray, N);
	return 0;
}