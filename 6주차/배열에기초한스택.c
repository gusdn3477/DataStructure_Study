#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100

void initStack(int *top);
void push(int *arr, int *top, int e);
void fullStackException();
void emptyStackException();
int pop(int *arr, int *top);
int isEmpty(int top);
int size(int top);
int top_(int *arr, int top);

int main(void) {

	int arr[MAX] = { 0 };
	int top;

	initStack(&top);

	push(arr, &top, 1);
	push(arr, &top, 2);
	printf("스택 최상위 요소 : %d\n", top_(arr, top));
	push(arr, &top, 3);
	printf("스택의 크기 : %d\n", size(top));
	push(arr, &top, 4);
	printf("스택 최상위 요소 : %d\n", top_(arr, top));
	printf("스택이 비었나요 ? : %d\n", isEmpty(top));
	pop(arr, &top);
	printf("스택 최상위 요소 : %d\n", top_(arr, top));
	pop(arr, &top);
	printf("스택 최상위 요소 : %d\n", top_(arr, top));
	pop(arr, &top);
	printf("스택 최상위 요소 : %d\n", top_(arr, top));
	pop(arr, &top);

	return 0;
}

void initStack(int *top) {
	*top = -1;
}

void push(int *arr, int *top, int e) {

	if (*top == MAX - 1)
		fullStackException();

	else
		arr[++(*top)] = e;
}

int pop(int *arr, int *top) {

	if (*top == -1)
		emptyStackException();

	else
		return arr[(*top)--];
}

int isEmpty(int top) {

	if (top == -1)
		return 1;

	return 0;
}

int size(int top) {

	return top + 1;
}

int top_(int *arr, int top) {

	if (isEmpty(top))
		emptyStackException();

	else
		return arr[top];
}

void fullStackException() {
	printf("스택이 가득 찼습니다.\n");
}

void emptyStackException() {
	printf("스택이 비었습니다.");
}