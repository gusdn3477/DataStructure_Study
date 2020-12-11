#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void enqueue(int *arr, int *front, int *rear, int q, int data);
void dequeue(int *arr, int *front, int *rear, int q);
void printQueue(int *arr, int q);
int isFull(int *front, int *rear, int q);
int isEmpty(int *front, int *rear, int q);

int main(void) {

	int *arr = NULL;
	int n;
	int front = 0, rear = 0;
	char ch;
	int num, q;
	scanf("%d", &q);
	arr = (int *)malloc(sizeof(int) * q);

	if (arr == NULL) {
		printf("동적 할당 실패!\n");
	}

	else {

		for (int i = 0; i < q; i++)
			arr[i] = 0;

		scanf("%d", &n);
		getchar();
		for (int i = 0; i < n; i++) {
			scanf("%c", &ch);
			getchar();
			if (ch == 'I') {
				scanf("%d", &num);
				enqueue(arr, &front, &rear, q, num);
				getchar();
			}

			else if (ch == 'P')
				printQueue(arr, q);

			else if (ch == 'D')
				dequeue(arr, &front, &rear, q);
		}

		free(arr);
	}

	return 0;
}

void enqueue(int *arr, int *front, int *rear, int q, int data) {
	
	if (isFull(front, rear, q) == 1) {
		printf("overflow ");
		printQueue(arr, q);
		return;
	}
	(*rear) = ((*rear) + 1) % q;
	arr[*rear] = data;
}

void dequeue(int *arr, int *front, int *rear, int q) {

	if (isEmpty(front, rear, q) == 1) {
		printf("underflow\n");
		return;
	}

	(*front) = ((*front) + 1) % q;
	arr[*front] = 0;
}

void printQueue(int *arr, int q) {

	int *p = NULL;

	for (p = arr; p < arr + q; p++) {
		printf("%d ", *p);
	}
	printf("\n");
}

int isFull(int *front, int *rear, int q) {

	if ((*rear + 1) % q == *front)
		return 1;
	else
		return 0;
}

int isEmpty(int *front, int *rear, int q) {

	if (*front == *rear)
		return 1;
	else
		return 0;
}