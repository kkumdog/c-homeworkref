#include "func.h"
#define N 5 

typedef pStu pStuArray[N];

int main(){
	int i,id=0,ret=0;
	char name[24] = {0};
	float score1=0,score2=0,score3=0;
	pStu pstuArray[N];
	memset(pstuArray,0,sizeof(pstuArray));
	printf("请输入%d个学生的信息:\n",N);
	i = 0;
	while (i<5 && (ret=scanf("%d%s%f%f%f", &id, name, &score1,&score2, &score3))!=EOF) {//可以直接从txt文件复制多行数据过来，此时相当于读文件
		if (ret !=5 ) {//注意由于%f会跳过空白符，所以数据中有缺失的地方要以*补足,这样才能正确发现输入错误
			printf("第%d行数据有缺失，请修改后重新导入完整数据\n",i+1);
			//rewind(stdin);//对于从记事本复制过来的多行数据，每次清空只会清空一行的数据，也就是遇到\n就认为输入结束，清空只会清空至\n的数据，下次循环，下行数据由重新进入缓冲区
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