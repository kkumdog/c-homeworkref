#include "func.h"
#define N 5

void sortById(pStu p[], int len) {
	int i,j=0;
	pStu temp;
	for (i = 1; i <len; i++) {
		if (p[i]->id < p[i-1]->id) {
			temp = p[i];
			for (j = i-1; j >= 0 && temp->id < p[j]->id; j--) {
					p[j+1] = p[j];
			}
			p[j+1] = temp;
		}
	}
}

void sortByscore(pStu p[], int len) {
	int i, j = 0;
	float score = 0;
	pStu temp;
	for (i = 1; i <len; i++) {
		if (p[i]->score[0] + p[i]->score[1]+p[i]->score[2] > p[i-1]->score[0] + p[i-1]->score[1] + p[i-1]->score[2]) {
			temp = p[i];
			for (j = i - 1; j >= 0 && temp->score[0] + temp->score[1]+ temp->score[2] > p[j]->score[0] + p[j]->score[1] + p[j]->score[2];j--){
					p[j + 1] = p[j];
			}
			p[j+1] = temp;
		}
	}
}

void showAllInfo(pStu p[], int len) {
	int i = 0;
	float score = 0;
	for (i = 0; i < len; i++) {
		score = p[i]->score[0] + p[i]->score[1] + p[i]->score[2];
		printf("%-2d %-6s %-6.2f %-6.2f %-6.2f %-6.2f\n", p[i]->id, p[i]->name, p[i]->score[0], p[i]->score[1], p[i]->score[2],score);
	}
}
void showBestInfo(pStu p[], int len) {
	int i,j=0,k=0,t=0,n=0;
	int best[3][N] = { 0 };//ʹ�ö�ά���飬�洢���Ƴɼ���õ�ͬѧ����Ϣ(���ܲ�ֹһ��)
	float max1=0, max2=0, max3=0;
	max1 = p[0]->score[0];
	max2 = p[0]->score[1];
	max3 = p[0]->score[2];
	best[0][0] = 1;//��һ��ͬѧ���1���Ա�������ʱ����Ϊ0��Ϊ��������
	best[1][0] = 1;
	best[2][0] = 1;
	for (i = 1; i < len; i++) {
		if (p[i]->score[0] > max1) {
			max1 = p[i]->score[0];
			best[0][0] = i+1;//��Ӧ��һ��ͬѧ��Ϊ1
			j = 0;
		}
		else if (p[i]->score[0] == max1) {
			best[0][++j] = i + 1;
		}
		if (p[i]->score[1] > max2) {
			max2 = p[i]->score[1];
			best[1][0] = i+1;
			k=0;
		}
		else if (p[i]->score[1] == max2) {
			best[1][++k] = i + 1;
		}
		if (p[i]->score[2] > max3) {
			max3 = p[i]->score[2];
			best[2][0] = i+1;
			t = 0;
		}
		else if (p[i]->score[2] == max3) {
			best[2][++t] = i + 1;
		}
	}
	for (i = 0; i < 3; i++) {
		printf("��%d�ſγɼ���ߵ�ѧ����:\n", i + 1);
		for (j = 0; best[i][j] && j < N; j++) {
			float score = 0;
			n = best[i][j];
			score = p[n-1]->score[0] + p[n-1]->score[1] + p[n-1]->score[2];//ǰ���±�ӹ�1���˴�������
			printf("%-2d %-6s %-6.2f %-6.2f %-6.2f %-6.2f\n", p[n-1]->id, p[n-1]->name, \
				p[n-1]->score[0], p[n-1]->score[1], p[n-1]->score[2], score);
		}	
	}
}
void destory(pStu p[], int len) {
	int i;
	for (i = 0; i < len&&p[i]; i++) {
		free(p[i]);
		p[i] = NULL;
	}
}