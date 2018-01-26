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
char n2c(int n);
void preorder(struct node *p);
void inorder(struct node *p);
void postorder(struct node *p);

int main(void){
	int i;
	node_t *root;
	int ndata[] = {7, 2, 8, 1, 5, 4, 6, 3};
	int ndata_length = sizeof ndata/sizeof ndata[0];

	root = allocNode();
	setNode(root, ndata[0], NULL, NULL);
	for (i=1; i<ndata_length; ++i)
		insertNode(root, ndata[i]);
	
	printTree(root);
	printf("\n---preorder---\n");
	preorder(root);
	printf("\n---inorder---\n");
	inorder(root);
	printf("\n---postorder---\n");
	postorder(root);
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
	
	//printf("%*c [%d]\n", 5*level, ' ', n->label);
	printf("%*c [%c]\n", 5*level, ' ', n2c(n->label));
	
	if (n->left != NULL) {
		printTree(n->left);
	}
	level--;
}

char n2c(int n){
	char c;
	switch(n) {
		case 1: c = 'C'; break;
		case 2: c = 'B'; break;
		case 3: c = 'G'; break;
		case 4: c = 'E'; break;
		case 5: c = 'D'; break;
		case 6: c = 'F'; break;
		case 7: c = 'A'; break;
		case 8: c = 'H'; break;
		default: c = 'X'; break;
	}
	return c;
}

void preorder(struct node *p){
	if (p==NULL)
		return;
	printf("節%cに立ち寄りました\n", n2c(p->label));
	preorder(p->left);
	preorder(p->right);
}

void inorder(struct node *p) {
	if (p==NULL)
		return;
	inorder(p->left);
	printf("節%cに立ち寄りました\n", n2c(p->label));
	inorder(p->right);
}

void postorder(struct node *p) {
	if (p==NULL)
		return;
	postorder(p->left);
	postorder(p->right);
	printf("節%cに立ち寄りました\n", n2c(p->label));
}
