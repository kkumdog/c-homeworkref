#include "func.h"

int main() {
	char c;
	pNode root=NULL;
	pQueue_t que=NULL;
	while (scanf("%c", &c) != EOF) {
		if (c == '\n') {
			break;
		}
		levelTreeBuilding(&root,&que,c);
	}
	TreePreOrder(root);
	return 0;
}