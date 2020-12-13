#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{

	struct _Node *left;
	int data;
	struct _Node *right;

}Node;

typedef struct _Tree {
	Node *curr;
}Tree;

Node *makeNode(int data);
void *makeTree(Node *parent, Node *left, Node *right);

int main(void) {

	Tree t[9];
	Node *node[9];
	int N;

	node[8] = makeNode(80);
	node[7] = makeNode(130);
	node[6] = makeNode(120);
	node[5] = makeNode(90);
	node[4] = makeNode(70);
	node[3] = makeNode(50);
	node[2] = makeNode(30);
	node[1] = makeNode(20);

	makeTree(node[6], node[7], node[8]);
	makeTree(node[2], node[4], node[5]);
	makeTree(node[3], NULL, node[6]);
	makeTree(node[1], node[2], node[3]);


	scanf("%d", &N);

	if (N < 1 || N > 8)
		printf("-1");

	else {
		if (node[N] != NULL)
			printf("%d ", node[N]->data);

		if (node[N]->left != NULL)
			printf("%d ", node[N]->left->data);

		if (node[N]->right != NULL)
			printf("%d ", node[N]->right->data);
	}

	for (int i = 1; i <= 8; i++)
		free(node[i]);

	return 0;
}

Node *makeNode(int data) {

	Node *newNode = (Node *)malloc(sizeof(Node));

	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

void *makeTree(Node *parent, Node *left, Node *right) {

	parent->left = left;
	parent->right = right;
}