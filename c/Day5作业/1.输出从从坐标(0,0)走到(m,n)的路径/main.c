#include <stdlib.h>
#include <stdio.h>
#define N 100

typedef struct {
	int x;
	int y;
}Node;
Node coordinate[N];
int count = 0;

void findWays(int m, int n, int basex, int basey, int step) {
	int i;
	if (basex == m && basey == n) {
		count++;
		for (i = 0; i <= step; i++) {
			if (i != step) {
				printf("(%d,%d)->", coordinate[i].x, coordinate[i].y);
			}
			else {
				printf("(%d,%d)", coordinate[i].x, coordinate[i].y);
			}
			
		}
		printf("\n");
		return;
	}
	if (basex < m && basey <= n) {
		coordinate[step + 1].x = basex + 1;
		coordinate[step + 1].y = basey;
		findWays(m, n, basex + 1, basey, step + 1);
	}
	if (basey < n && basex <= m) {
		coordinate[step + 1].x = basex;
		coordinate[step + 1].y = basey + 1;
		findWays(m, n, basex, basey + 1, step + 1);
	}
}

int main() {
	int m, n, basex, basey;
	m = n = basex = basey = 0;
	while (1) {
		printf("��������ʼ����(basex,basey):");
		scanf("(%d,%d)", &basex, &basey);
		rewind(stdin);
		printf("���������뵽���λ������(x,y):");
		scanf("(%d,%d)", &m, &n);//��������(���֣�����),x,y����ȡ����ȷ��ֵ
		rewind(stdin);
		coordinate[0].x = basex;
		coordinate[0].y = basey;
		count = 0;
		findWays(m, n, basex, basey, 0);
		printf("��(%d,%d)��(%d,%d)һ�������ϵ�%d��·��\n", basex, basey, m, n, count);
	}
	return 0;
}