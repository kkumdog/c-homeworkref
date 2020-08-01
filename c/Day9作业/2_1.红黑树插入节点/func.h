#include <stdio.h>
#include <stdlib.h>

typedef int Type;

typedef struct RBTreeNode {
	unsigned char color;
	Type val;
	struct RBTreeNode *left;
	struct RBTreeNode *right;
	struct RBTreeNode *parent;
}Node,*RBtree;

typedef struct rb_root {
	Node *node;
}RBRoot;
