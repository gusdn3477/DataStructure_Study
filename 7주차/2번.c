#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int data;
	struct _Node *next;
}Node;

typedef struct _Set {
	Node* head; // 첫 노드를 가리킬 head 노드입니다.
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

	//A, B 모두 NULL아 아닐 때 까지 합집합 계산을 한다.
	while (currA != NULL && currB != NULL) {
		
		if (currA->data < currB->data) {
			//addNode 사용하면 될듯.
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

	//currA가 끝이 아니라면, 모두 Unionset에 담는다.
	while (currA != NULL) {
		Unionset = addNode(Unionset, currA->data);
		currA = currA->next;
	}

	//currB가 끝이 아니라면, 모두 Unionset에 담는다.
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

	//A,B 원소가 겹치는 경우 interSet에 넣어준다.
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