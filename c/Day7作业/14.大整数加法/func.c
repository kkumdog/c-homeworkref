#include "func.h"

void listTailInsert(pLineList list, char c,int isNewList) {
	static i = 0;
	if (isNewList) {
		i = 0;//如果构建新表，则将静态计数变量置为0
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
	list->tail->str[i++] = c;//保存成原样，不能直接变为数字，如将‘0’变为0，后续统计字符串到这就结束了
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
			printf("输入错误!\n");
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

void listReverse(pLineList list) {//只逆置链表，结点中的元素不变
	pNode pre, p, q;//q用于记录原本的p->next
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

void listAndStrReverse(pLineList list) {//逆置后链表可能为(1)->(2,3,4,5)
	pNode p;
	listReverse(list);//将链表反转，使低位在前
	p = list->head;
	while (p != list->tail->next) {//结点中的字符串也要反转
		strReverse(p->str, strlen(p->str));
		p = p->next;
	}
}

void listHeadAdjustAlign(pLineList list) {//将链表首对齐，调整为(1,2,3,4)->(5)
	pNode p;
	int i,len=0, moveDistance=0;//moveDistance表示需要前移多少个元素
	p = list->head;
	while (p) {
		len = strlen(p->str);
		moveDistance = N - len;
		if (len == N || p->next==NULL) {//首结点满字符串或是最后一个结点，结束调整
			break;
		}
		for (i = 0; i < moveDistance; i++,len++) {
			p->str[len] = p->next->str[i];
		}
		for (i = 0; i + moveDistance <= N; i++) {//取到N，刚好在结束时把'\0'取过来
			p->next->str[i] = p->next->str[i + moveDistance];
		}
		for (; i < N; i++) {
			p->next->str[i] = 0;//把其后至字符串结尾全置为0，避免在加最后一个结点的数字时出错
		}
		p = p->next;
	}
}

void largeNumAdd(pLineList num1, pLineList num2, pLineList sum) {
	pNode p, q, r;
	int i = 0, j = 0, len = 0, d, isNewList = 1;//d存储每一位加出来的值
	listAndStrReverse(num1);
	listAndStrReverse(num2);
	listHeadAdjustAlign(num1);//解决:(1）->(2,3,4,5)变为(1,2，3，4)->(5)的问题
	listHeadAdjustAlign(num2);
	p = num1->head;
	q = num2->head;
	while (p&&q) {//将每一位的数字加起来存在sum中，注意此时是逆序的
		len = strlen(p->str) > strlen(q->str) ? strlen(p->str) : strlen(q->str);
		alpToNum(p);//计算完长度再转化为真正的数字，防止将数字0错认为字符串结尾
		alpToNum(q);
		for (i = 0; i < len; i++) {
			d = p->str[i] + q->str[i];
			d += '0';//以字符形式存进去，以正确找到字符串结尾的'\0'
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
	//处理进位
	r = sum->head;
	while (r) {
		len = strlen(r->str);
		for (i = 0; i < len ; i++) {
			r->str[i] -= '0';//前面为了正确找'\0'，以字符形式存放，计算时换回数字
			if (i < len - 1 && r->str[i] > 9) {
				r->str[i] %= 10;
				r->str[i + 1] += 1;
			}
			if (i == len - 1 && r->str[i] > 9) {//某节点尾元素进位需进位到下一节点
					r->str[i] %= 10;
					if (r->next == NULL) {//如果是尾结点，则需要新建一个结点保存进位
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
			r->str[i] += '0';//计算出一位就转换为字符
		}
		r = r->next;
	}
	//将链表逆置即为结果
	listAndStrReverse(sum);
}

void listPrint(lineList list) {
	pNode p;
	int i;
	p = list.head;
	while (p) {//打印到NULL
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
		if (p->next ==0xdddddddd ) {//wind下free(p)之后会将p->next置为0xdddddddd，此处偷懒可解决重复free问题，其它平台另想他法
			break;
		}
		q = p->next;
		free(p);//free之后p指向的结构体里面的数据会改变
		p = q;
	}
	list->head = NULL;
	list->tail = NULL;
	list->len = 0;
}
