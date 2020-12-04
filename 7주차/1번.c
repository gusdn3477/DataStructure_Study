#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int data;
	struct _Node *next;
}Node;

/*typedef struct _Set {
	Node *head;
}Set;*/

Node* addNode(Node *A, int num);
int subset(Node *A, Node *B);

int main(void)
{
	Node* A = NULL;
	Node* B = NULL;
	Node* C = NULL;
	int N, M;
	int ans;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &M);
		A = addNode(A, M);
	}

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &M);
		B = addNode(B, M);
	}

	ans = subset(A, B);
	printf("%d\n", ans);



	Node *curr = A;

	while (curr != NULL) {
		Node *a = curr;
		curr = curr->next;
		free(a);
	}

	curr = B;

	while (curr != NULL) {
		Node *a = curr;
		curr = curr->next;
		free(a);
	}

	return 0;
}

Node* addNode(Node *A, int num) {
	
	if (A == NULL) {
		Node *newNode = (Node *)malloc(sizeof(Node));
		if (newNode == NULL) {
			printf("동적 할당 실패!\n");
			return;
		}
		newNode->data = num;
		newNode->next = NULL;
		A = newNode;
	}

	else {

		Node *newNode = (Node *)malloc(sizeof(Node));
		if (newNode == NULL) {
			printf("동적 할당 실패!\n");
			return;
		}
		Node *curr = A;
		newNode->data = num;

		while (curr->next != NULL) {
			curr = curr->next;
		}
		newNode->next = curr->next;
		curr->next = newNode;
	}

	return A;
}

int subset(Node *A, Node *B) {

	Node *curr = A;
	Node *curr2 = B;

	while (curr != NULL && curr2 != NULL) {

		if (curr->data < curr2->data)
			curr = curr->next;

		else if (curr->data > curr2->data) {
			curr2 = curr2->next;
		}

		else {
			curr = curr->next;
			curr2 = curr2->next;
		}

	}

	if (curr == NULL)
		return 0;

	else
		return curr->data;
}