#include "func.h"


levelTreeBuilding(pNode *root, pQueue_t *que, ElemType val)
{//队列头元素指示建树的根节点
	pNode treeNew=NULL;
	pQueNode queNew=NULL,q=NULL,queHead=NULL;//q用于释放空间
	pQueue_t Que;
	queNew = (pQueNode)calloc(1, sizeof(queNode));
	treeNew = (pNode)calloc(1, sizeof(node));
	treeNew->val = val;
	queNew->treeNode = treeNew;
	if (NULL == *root) {
		*root = treeNew;//树根为空，队列必为空，接着还要处理队列
		Que = (pQueue_t)calloc(1, sizeof(Queue_t));
		Que->head = queNew;
		Que->tail = queNew;
		Que->len++;
		*que = Que;
	}
	else {
		queHead = (*que)->head;
		(*que)->tail->next = queNew;
		(*que)->tail = queNew;
		(*que)->len++;
		if (NULL == queHead->treeNode->left) {
			queHead->treeNode->left = treeNew;

		}
		else if (NULL == queHead->treeNode->right) {
			queHead ->treeNode->right = treeNew;
			q = queHead;
			(*que)->head = queHead->next;
			(*que)->len--;
			free(q);
			q = NULL;
		}
	}
}

void TreePreOrder(pNode root) {
	if (root) {
		printf("%c ", root->val);
		TreePreOrder(root->left);
		TreePreOrder(root->right);
	}
	return;
}
