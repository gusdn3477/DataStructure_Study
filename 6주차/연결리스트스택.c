#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _List {
	int data;
	struct _List *next;
}List;

void initStack(List **list);
List *getNode(void);
void push(List **list,int e);
int pop(List **list);
int top(List *list);
int isEmpty(List *list);
void emptyStackException();
int size(List *list);

int main(void) {

	List *p = NULL;
	List *q;
	initStack(&p);
	
	push(&p, 1);
	printf("%d\n", pop(&p));
	printf("%d\n", size(p));
	pop(&p);
	push(&p, 2);
	push(&p, 4);
	printf("%d\n", size(p));

	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}

	return 0;
}


void initStack(List **list) {
	*list = NULL;
}

void push(List **list, int e) {

	if (*list == NULL) { // List가 빈 경우
		(*list) = getNode();
		(*list)->data = e;
		(*list)->next = NULL;
	}

	else {
		List *newNode = getNode();
		newNode->next = *list;
		*list = newNode;
	}
}

int top(List *list) {

	if (isEmpty(list)) {
		emptyStackException();
	}

	else {
		printf("%d\n", list->data);
	}
}

int size(List *list) {

	if (isEmpty(list)) {
		return 0;
	}

	else {
		int count = 1;

		while (list->next != NULL) {
			list = list->next;
			count++;
		}
		return count;
	}

}
int pop(List **list) {

	if (isEmpty(*list)) {
		emptyStackException();
		return;
	}

	else {
		List *save = *list;
		int a;
		*list = (*list)->next;
		a = save->data;
		free(save);
		return a;
	}
}

List *getNode(void) {
	List *newNode = (List *)malloc(sizeof(List));
	return newNode;
}

void emptyStackException() {
	printf("스택이 비었습니다.\n");
}

int isEmpty(List *list) {

	if (list == NULL)
		return 1;

	return 0;
}