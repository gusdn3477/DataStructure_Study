#include <stdio.h>
#include <stdlib.h>

void push(char *stack, char c, int *top, int *max);
char pop(char *stack, int *top);
char peek(char *stack, int *top);
void print(char *stack, int *top);
int isEmpty(int *top);

int main(void) {

	int stack[101] = { 0 }; // ��Ģ������ push �� ���� �����Ƿ� int�� �迭�� �����մϴ�.
	char str[101] = { '\0' };
	int N;
	int a, b;
	int max = 101;
	int top = -1;
	char c;
	char *p = NULL;

	scanf("%d", &N);
	getchar();

	for (int i = 0; i < N; i++) {
		scanf("%s", str);
		for (p = str; *p != '\0'; p++) {
			if (*p == '+') {
				a = pop(stack, &top);
				b = pop(stack, &top);
				push(stack, b + a, &top, &max);
			}

			else if (*p == '-') {
				a = pop(stack, &top);
				b = pop(stack, &top);
				push(stack, b - a, &top, &max);
			}
			else if (*p == '*') {
				a = pop(stack, &top);
				b = pop(stack, &top);
				push(stack, b * a, &top, &max);
			}
			else if (*p == '/') {
				a = pop(stack, &top);
				b = pop(stack, &top);
				push(stack, b / a, &top, &max);
			}
			else {
				a = *p - '0'; //���ڷ� ���� ���ÿ� �ֽ��ϴ�.
				push(stack, a, &top, &max);
			}
		}

		a = pop(stack, &top);
		printf("%d\n", a);
	}
	return 0;
}

void push(char *stack, int c, int *top, int *max) {

	if (*top < *max - 1) { //������ pop �ε����� 100 �̸��� ��츸 push�� �Ѵ�.
		stack[++(*top)] = c;
	}

	else
		printf("������ ���� á���ϴ�.");
}

int pop(char *stack, int *top) {

	if (*top >= 0) { // ������ top�� �ε����� 0�� �̻󿡸� pop�� �Ѵ�.
		return stack[(*top)--];
	}

}

char peek(char *stack, int *top) {

	if (*top >= 0) // ������ top �ε����� 0�� �̻��� ��츸 ���� ��Ҹ� ��ȯ�Ѵ�.
		return stack[*top];

}

void print(int *stack, int *top) {

	for (int i = 0; i <= *top; i++) { // 0���� top���� ����Ѵ�.
		printf("%d", stack[i]);
	}
	printf("\n");

}

int isEmpty(int *top) {

	if (*top < 0) //top�� 0 �̸��� ��쿣 ������ �� ���̹Ƿ� 1�� ��ȯ�Ѵ�.
		return 1;
	else
		return 0; // �׷��� ���� ���, 0�� ��ȯ�Ѵ�.
}