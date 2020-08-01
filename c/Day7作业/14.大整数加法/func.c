#include "func.h"

void listTailInsert(pLineList list, char c,int isNewList) {
	static i = 0;
	if (isNewList) {
		i = 0;//��������±��򽫾�̬����������Ϊ0
	}
	if (list->head == NULL) {
		pNode pNew = (pNode)calloc(1, sizeof(node));
		list->head = pNew;
		list->tail = pNew;
		list->len++;
	}
	if (N == i) {
		pNode pNew = (pNode)calloc(1, sizeof(node));
		pNew->next = list->tail->next;
		list->tail->next = pNew;
		list->tail = pNew;
		list->len++;
		i = 0;
	}
	list->tail->str[i++] = c;//�����ԭ��������ֱ�ӱ�Ϊ���֣��罫��0����Ϊ0������ͳ���ַ�������ͽ�����
}

int getNum(pLineList list) {
	char c = '\0';
	int isNewList = 1;
	while ((c = getchar()) != '\n') {
		if (c >= '0' && c <= '9') {
			if (isNewList) {
				listTailInsert(list, c, 1);
				isNewList = 0;
			}
			else {
				listTailInsert(list, c, 0);
			}
		}
		else {
			printf("�������!\n");
			rewind(stdin);
			return 0;
		}
	}
	return 1;
}

void alpToNum(pNode p) {
	int i;
	for (i = 0; p->str[i]; i++) {
		p->str[i] -= '0';
	}
}

void listReverse(pLineList list) {//ֻ������������е�Ԫ�ز���
	pNode pre, p, q;//q���ڼ�¼ԭ����p->next
	pre = q = NULL;

	p = list->head;
	if (list->head == NULL) {
		return;
	}
	while (p) {
		q = p->next;
		p->next = pre;
		pre = p;
		p = q;
	}
	list->tail = list->head;
	list->head = pre;
}

void strReverse(char str[], int len) {
	int i, j;
	char c = '\0';
	for (i = 0, j = len - 1; i < j; i++, j--) {
		c = str[i];
		str[i] = str[j];
		str[j] = c;
	}
}

void listAndStrReverse(pLineList list) {//���ú��������Ϊ(1)->(2,3,4,5)
	pNode p;
	listReverse(list);//������ת��ʹ��λ��ǰ
	p = list->head;
	while (p != list->tail->next) {//����е��ַ���ҲҪ��ת
		strReverse(p->str, strlen(p->str));
		p = p->next;
	}
}

void listHeadAdjustAlign(pLineList list) {//�������׶��룬����Ϊ(1,2,3,4)->(5)
	pNode p;
	int i,len=0, moveDistance=0;//moveDistance��ʾ��Ҫǰ�ƶ��ٸ�Ԫ��
	p = list->head;
	while (p) {
		len = strlen(p->str);
		moveDistance = N - len;
		if (len == N || p->next==NULL) {//�׽�����ַ����������һ����㣬��������
			break;
		}
		for (i = 0; i < moveDistance; i++,len++) {
			p->str[len] = p->next->str[i];
		}
		for (i = 0; i + moveDistance <= N; i++) {//ȡ��N���պ��ڽ���ʱ��'\0'ȡ����
			p->next->str[i] = p->next->str[i + moveDistance];
		}
		for (; i < N; i++) {
			p->next->str[i] = 0;//��������ַ�����βȫ��Ϊ0�������ڼ����һ����������ʱ����
		}
		p = p->next;
	}
}

void largeNumAdd(pLineList num1, pLineList num2, pLineList sum) {
	pNode p, q, r;
	int i = 0, j = 0, len = 0, d, isNewList = 1;//d�洢ÿһλ�ӳ�����ֵ
	listAndStrReverse(num1);
	listAndStrReverse(num2);
	listHeadAdjustAlign(num1);//���:(1��->(2,3,4,5)��Ϊ(1,2��3��4)->(5)������
	listHeadAdjustAlign(num2);
	p = num1->head;
	q = num2->head;
	while (p&&q) {//��ÿһλ�����ּ���������sum�У�ע���ʱ�������
		len = strlen(p->str) > strlen(q->str) ? strlen(p->str) : strlen(q->str);
		alpToNum(p);//�����곤����ת��Ϊ���������֣���ֹ������0����Ϊ�ַ�����β
		alpToNum(q);
		for (i = 0; i < len; i++) {
			d = p->str[i] + q->str[i];
			d += '0';//���ַ���ʽ���ȥ������ȷ�ҵ��ַ�����β��'\0'
			if (isNewList) {
				listTailInsert(sum, d, 1);
				isNewList = 0;
			}
			else {
				listTailInsert(sum, d, 0);
			}
		}
		p = p->next;
		q = q->next;
	}
	if (p) {
		i = 0;
		sum->tail->next = p;
		sum->tail = num1->tail;
		while (p) {
			p = p->next;
			i++;
		}
		sum->len += i;
	}
	if (q) {
		i = 0;
		sum->tail->next = q;
		sum->tail = num2->tail;
		while (q) {
			q = q->next;
			i++;
		}
		sum->len += i;
	}
	//�����λ
	r = sum->head;
	while (r) {
		len = strlen(r->str);
		for (i = 0; i < len ; i++) {
			r->str[i] -= '0';//ǰ��Ϊ����ȷ��'\0'�����ַ���ʽ��ţ�����ʱ��������
			if (i < len - 1 && r->str[i] > 9) {
				r->str[i] %= 10;
				r->str[i + 1] += 1;
			}
			if (i == len - 1 && r->str[i] > 9) {//ĳ�ڵ�βԪ�ؽ�λ���λ����һ�ڵ�
					r->str[i] %= 10;
					if (r->next == NULL) {//�����β��㣬����Ҫ�½�һ����㱣���λ
						pNode pNew = (pNode)calloc(1, sizeof(node));
						pNew->str[0] = '1';
						r->next = pNew;
						sum->tail = pNew;
						sum->len++;
					}
					else {
						r->next->str[0] += 1;
					}
			}
			r->str[i] += '0';//�����һλ��ת��Ϊ�ַ�
		}
		r = r->next;
	}
	//���������ü�Ϊ���
	listAndStrReverse(sum);
}

void listPrint(lineList list) {
	pNode p;
	int i;
	p = list.head;
	while (p) {//��ӡ��NULL
		for (i = 0; p->str[i]; i++) {
			printf("%c", p->str[i]);
		}
		if (p->next) {
			printf(",");
		}
		p = p->next;
	}
	printf("\n");
}

void listDestory(pLineList list) {
	pNode p, q;
	p = q = list->head;
	while (p) {
		if (p->next ==0xdddddddd ) {//wind��free(p)֮��Ὣp->next��Ϊ0xdddddddd���˴�͵���ɽ���ظ�free���⣬����ƽ̨��������
			break;
		}
		q = p->next;
		free(p);//free֮��pָ��Ľṹ����������ݻ�ı�
		p = q;
	}
	list->head = NULL;
	list->tail = NULL;
	list->len = 0;
}
