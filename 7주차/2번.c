#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int data;
	struct _Node *next;
}Node;

typedef struct _Set {
	Node* head; // ù ��带 ����ų head ����Դϴ�.
}Set;

Set *addNode(Set *set, int data);
Set *Union(Set *A, Set *B);
Set *intersect(Set *A, Set *B);
void freeNode(Set *set);
void printSet(Set *set);

int main(void) {

	int N, M,x;

	Set *A = (Set *)malloc(sizeof(Set));
	Set *B = (Set *)malloc(sizeof(Set));
	Set *unionSet = NULL;
	Set *intersectSet = NULL;

	A->head = NULL;
	B->head = NULL;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		A = addNode(A, x);
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &x);
		B = addNode(B, x);
	}

	unionSet = Union(A, B);
	intersectSet = intersect(A, B);

	printSet(unionSet);
	printf("\n");
	printSet(intersectSet);

	freeNode(A);
	freeNode(B);
	freeNode(unionSet);
	freeNode(intersectSet);

	free(A);
	free(B);
	free(unionSet);
	free(intersectSet);

	return 0;
}

Set *addNode(Set *set, int data) {

	if (set->head == NULL) {
		Node *newNode = (Node *)malloc(sizeof(Node));
		newNode->data = data;
		newNode->next = NULL;
		set->head = newNode;
	}

	else {

		Node *curr = set->head;
		while (curr->next != NULL) {
			curr = curr->next;
		}

		Node *newNode = (Node *)malloc(sizeof(Node));
		newNode->data = data;
		newNode->next = curr->next;
		curr->next = newNode;
	}

	return set;
}

Set *Union(Set *A, Set *B) {

	Node *currA = A->head;
	Node *currB = B->head;
	Set *Unionset = (Set *)malloc(sizeof(Set));
	Unionset->head = NULL;

	//A, B ��� NULL�� �ƴ� �� ���� ������ ����� �Ѵ�.
	while (currA != NULL && currB != NULL) {
		
		if (currA->data < currB->data) {
			//addNode ����ϸ� �ɵ�.
			Unionset = addNode(Unionset, currA->data);
			currA = currA->next;
		}

		else if (currA->data > currB->data) {
			Unionset = addNode(Unionset, currB->data);
			currB = currB->next;
		}

		else {
			Unionset = addNode(Unionset, currA->data);
			currA = currA->next;
			currB = currB->next;
		}
	}

	//currA�� ���� �ƴ϶��, ��� Unionset�� ��´�.
	while (currA != NULL) {
		Unionset = addNode(Unionset, currA->data);
		currA = currA->next;
	}

	//currB�� ���� �ƴ϶��, ��� Unionset�� ��´�.
	while (currB != NULL) {
		Unionset = addNode(Unionset, currB->data);
		currB = currB->next;
	}

	if (Unionset->head == NULL)
		Unionset = addNode(Unionset, 0);

	return Unionset;
}

Set *intersect(Set *A, Set *B) {

	Node *currA = A->head;
	Node *currB = B->head;
	Set *interSet = (Set *)malloc(sizeof(Set));
	interSet->head = NULL;

	//A,B ���Ұ� ��ġ�� ��� interSet�� �־��ش�.
	while (currA != NULL && currB != NULL) {

		if (currA->data < currB->data) {
			currA = currA->next;
		}

		else if (currA->data > currB->data) {
			currB = currB->next;
		}

		else {
			interSet = addNode(interSet, currA->data);
			currA = currA->next;
			currB = currB->next;
		}
	}

	if (interSet->head == NULL)
		interSet = addNode(interSet, 0);

	return interSet;
}

void freeNode(Set *set) {

	Node *curr = set->head;
	while (curr != NULL) {
		Node *save = curr;
		curr = curr->next;
		free(save);
	}

}

void printSet(Set *set) {

	Node *curr = set->head;
	while (curr != NULL) {
		printf("%d ", curr->data);
		curr = curr->next;
	}
}