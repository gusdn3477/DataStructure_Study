#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int coef;
	int exp;
	struct _Node *next;
}Node;

typedef struct _List {
	Node *header;
	Node *curr;
}List;

void initList(List **list);
void addNode(List *list, int coef, int exp);
List *addPoly(List *list, List *list2);


int main(void) {

	int N, M;
	int arr[100] = { 0 };
	int arr2[100] = { 0 };
	Node *node = NULL; // 순회하면서 free할 용도
	List *list = NULL;
	List *list2 = NULL;
	List *list_sum = NULL; // 합 받을 리스트

	initList(&list);
	initList(&list2);

	scanf("%d", &N);
	for (int j = 0; j < N * 2; j++) {
		scanf("%d", &arr[j]);
	}

	for (int j = 0; j < N * 2; j = j + 2) {
		addNode(list, arr[j], arr[j + 1]);
	}

	scanf("%d", &M);
	for (int j = 0; j < M * 2; j++) {
		scanf("%d", &arr2[j]);
	}

	for (int j = 0; j < M * 2; j = j + 2) {
		addNode(list2, arr2[j], arr2[j + 1]);
	}

	list_sum = addPoly(list, list2);
	list_sum->curr = list_sum->header->next;

	while (list_sum->curr != NULL) {
		printf(" %d %d", list_sum->curr->coef, list_sum->curr->exp);
		list_sum->curr = list_sum->curr->next;
	}

	list->curr = list->header;
	list2->curr = list2->header;

	while (list->curr != NULL) {
		node = list->curr;
		list->curr = list->curr->next;
		free(node);
	}

	while (list2->curr != NULL) {
		node = list2->curr;
		list2->curr = list2->curr->next;
		free(node);
	}

	list_sum->curr = list_sum->header;

	while (list_sum->curr != NULL) {
		node = list_sum->curr;
		list_sum->curr = list_sum->curr->next;
		free(node);
	}

	free(list);
	free(list2);
	free(list_sum);
	return 0;
}

void initList(List **list) {

	Node *head = (Node *)malloc(sizeof(Node));
	*list = (List *)malloc(sizeof(List));
	(*list)->header = head;
	(*list)->curr = (*list)->header;
	head->next = NULL;
}

void addNode(List *list, int coef, int exp) {

	Node *node = (Node *)malloc(sizeof(Node));
	node->coef = coef;
	node->exp = exp;

	list->curr->next = node;
	node->next = NULL;
	list->curr = node;
}

List* addPoly(List *list, List *list2) {

	Node *node = list->header->next;
	Node *node2 = list2->header->next;
	List *list_sum = (List *)malloc(sizeof(List));
	initList(&list_sum);

	while (node != NULL && node2 != NULL) {

		if (node->exp > node2->exp) {
			addNode(list_sum, node->coef, node->exp);
			node = node->next;
		}

		else if (node->exp < node2->exp) {
			addNode(list_sum, node2->coef, node2->exp);
			node2 = node2->next;
		}

		else {
			int coef_sum = node->coef + node2->coef;
			if (coef_sum != 0) {
				addNode(list_sum, coef_sum, node->exp);
			}
			node = node->next;
			node2 = node2->next;
		}
	}

	//아직 남아있는 다항식을 붙여준다. (둘 중 무엇이 남았는지는 모름)
	while (node != NULL) {
		addNode(list_sum, node->coef, node->exp);
		node = node->next;
	}

	while (node2 != NULL) {
		addNode(list_sum, node2->coef, node2->exp);
		node2 = node2->next;
	}
	

	return list_sum;
}