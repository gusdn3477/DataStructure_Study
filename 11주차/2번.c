#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
	int data;
	struct _Node *prev;
	struct _Node *next;
}Node;

typedef struct _Deque {
	Node *front;
	Node *rear;
}Deque;

void AF(Deque *dq, int x);
void AR(Deque *dq, int x);
int DF(Deque *dq);
int DR(Deque *dq);
void P(Deque *dq);

int main(void) {

	int n;
	int num = 0;
	int check;
	int len = 0;
	char str[10];
	char *p = NULL;

	Deque *dq = (Deque *)malloc(sizeof(Deque));
	if (dq == NULL)
		printf("동적 할당 실패");

	dq->front = NULL;
	dq->rear = NULL;

	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		gets(str);
		len = strlen(str);

		for (p = str; *p != '\0'; p++) {
			if (*p == ' ')
				*p = '\0';
		}

		for (p = str; p < str + len; p++) {
			if (*p == '\0') {
				p++;
				num = atoi(p);
				break;
			}
		}

		p = str;

		if (strcmp(p, "AF") == 0) {
			//AF 함수 실행
			AF(dq, num);
		}

		else if (strcmp(p, "AR") == 0) {
			AR(dq, num);
		}

		else if (strcmp(p, "DF") == 0) {
			check = DF(dq);
			if (check == -1)
				break;
		}

		else if (strcmp(p, "DR") == 0) {
			check = DR(dq);
			if (check == -1)
				break;
		}

		else if (strcmp(p, "P") == 0) {
			P(dq);
		}

	}

	Node *curr = dq->front;

	while (curr != NULL) {
		Node *a = curr;
		curr = curr->next;
		free(a);
	}

	free(dq);

	return 0;
}

void AF(Deque *dq, int x) {

	Node *newNode = (Node *)malloc(sizeof(Node));

	if (dq->front == NULL) {
		newNode->next = NULL;
		newNode->prev = NULL;
		newNode->data = x;
		dq->front = newNode;
		dq->rear = newNode;
	}

	else {
		newNode->data = x;
		newNode->next = dq->front;
		newNode->prev = NULL;
		dq->front->prev = newNode;
		dq->front = newNode;
	}

}

void AR(Deque *dq, int x) {

	Node *newNode = (Node *)malloc(sizeof(Node));

	if (dq->rear == NULL) {
		newNode->next = NULL;
		newNode->prev = NULL;
		newNode->data = x;
		dq->front = newNode;
		dq->rear = newNode;
	}

	else {
		newNode->next = NULL;
		newNode->prev = dq->rear;
		newNode->data = x;
		dq->rear->next = newNode;
		dq->rear = newNode;
	}

}

int DF(Deque *dq) {

	Node *newNode = dq->front;
	if (newNode == NULL) {
		printf("underflow\n");
		return -1; //원소는 양의 정수만 허용되므로, -1을 반환시켜 종료 여부 충족시킨다.
	}

	if (dq->front == dq->rear) { // 노드가 1개밖에 없는 경우
		int a = newNode->data;
		dq->front = newNode->next;
		dq->rear = newNode->prev;
		free(newNode);
		return a;
	}

	int a = newNode->data;
	dq->front = newNode->next;
	dq->front->prev = NULL;

	free(newNode);
	return a;
}

int DR(Deque *dq) {

	Node *newNode = dq->rear;

	if (newNode == NULL) {
		printf("underflow\n");
		return -1;
	}

	if (dq->front == dq->rear) { // 노드가 1개밖에 없는 경우
		int a = newNode->data;
		dq->front = newNode->next;
		dq->rear = newNode->prev;
		free(newNode);
		return a;
	}

	int a = newNode->data;
	dq->rear = newNode->prev;
	dq->rear->next = NULL;

	free(newNode);
	return a;
}

void P(Deque *dq) {

	Node *curr = dq->front;

	while (curr != NULL) {
		printf(" %d", curr->data);
		curr = curr->next;
	}
	printf("\n");
}