#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>

typedef struct node {
	struct node *left;
	struct node *right;
	int label;
} node_t;

node_t *allocNode(void);
void setNode(node_t *n, int x, node_t *left, node_t *right);
node_t *insertNode(node_t *n, int x);
void printTree(node_t *n);

int main(void){
	//3,8,6,5,4,9,2,7,1
	node_t *root;
	root = allocNode();
	setNode(root, 3, NULL, NULL);
	
	insertNode(root,8);
	printf("***** TREE:add 8 *****\n");
	printTree(root);
	
	insertNode(root,6);
	printf("***** TREE:add 6 *****\n");
	printTree(root);
	
	insertNode(root,5);
	printf("***** TREE:add 5 *****\n");
	printTree(root);
	
	insertNode(root,4);
	printf("***** TREE:add 4 *****\n");
	printTree(root);
	
	insertNode(root,9);
	printf("***** TREE:add 9 *****\n");
	printTree(root);
	
	insertNode(root,2);
	printf("***** TREE:add 2 *****\n");
	printTree(root);
	
	insertNode(root,7);
	printf("***** TREE:add 7 *****\n");
	printTree(root);
	
	insertNode(root,1);
	printf("***** TREE:add 1 *****\n");
	printTree(root);

	return EXIT_SUCCESS;
}

node_t *allocNode(void){
	//大きさsizeof(node_t)バイトを1個分をメモリ領域に確保。
	//mallocではなくcallocは、確保した領域を0で初期化する。
	return (node_t *)calloc(1, sizeof(node_t));
}

void setNode(node_t *n, int x, node_t *left, node_t *right){
	n->left = left;
	n->right = right;
	n->label = x;
}

node_t *insertNode(node_t *n, int x){
	if (NULL == n) {
		n = allocNode();
		setNode(n, x, NULL, NULL);
	} else {
		if (x < n->label) {
			n->left = insertNode(n->left, x);
		} else if (x > n->label) {
			n->right = insertNode(n->right, x);
		} else {
			// x == n->label
			printf("ERROR:Registered\n");
		}
	}
	return n;
}

void printTree(node_t *n){
	static int level = 0;
	int i;
	level++;
	
		if (n->right != NULL) {
		printTree(n->right);
	}
	
	for (i=1; i<level; i++) {
		printf("  ");
	}
	printf("%d\n",n->label);
	
	if (n->left !=NULL) {
		printTree(n->left);
	}
	
	level--;
}
