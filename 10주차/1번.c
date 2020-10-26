#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(char *stack, char c, int *top, int *max);
void initStack(char *stack, int *max, int *top);
char pop(char *stack, int *top);
char peek(char *stack, int *top);
void print(char *stack, int *top);
int isEmpty(int *top);
int checkPriority(char c);
void makeSimplify(char *str);

int main(void) {

	char stack[101] = { '\0' };
	char str[101] = { '\0' };
	int N;
	int max = 101;
	int top = -1;
	char c_pop;
	char check;
	char *p = NULL;

	scanf("%d", &N);
	getchar();

	for (int i = 0; i < N; i++) {
		scanf("%s", str);
		makeSimplify(str);

		for (p = str; *p != '\0'; p++) {
			if (*p >= 'A' && *p <= 'Z') // ���ĺ��� ���, ���
				printf("%c", *p);

			else if (*p == '(') { // '(' �� ���
				push(stack, *p, &top, &max); // '('�� ���, ���ÿ� ����ִ´�.
			}

			else if (*p == ')') { // ')'�� ���, '('�� ������ �� ���� ��� ������ְ�, ���������� pop�� ���༭ '('�� �����Ѵ�.
				while (peek(stack, &top) != '(') {
					c_pop = pop(stack, &top);
					printf("%c", c_pop);
				}
				pop(stack, &top);
			}

			else {
				if (isEmpty(&top) == 1) // ������ ������� �ٷ� push �Ѵ�.
					push(stack, *p, &top, &max);

				else { //�׷��� ���� ���,
					check = peek(stack, &top); // ������ �ֻ����� �ִ� ��Ҹ� check ������ ���� �ڿ�
					if (checkPriority(check) >= checkPriority(*p)) { // �켱������ ���Ͽ� stack�� �ֻ����� �ִ� ���� �켱������ ���� ���, ���� �� ����� ��, push�� ���ش�.

						while (checkPriority(check) >= checkPriority(*p) && isEmpty(&top) != 1) {
							c_pop = pop(stack, &top);
							if (c_pop == '&' || c_pop == '|') { // &&�� ||�� ���� &,|�� ��ҵǾ����Ƿ� �� �� ����ϴ� ������ ��ģ��.
								printf("%c", c_pop);
								printf("%c", c_pop);							}
							else
								printf("%c", c_pop);
						}
						push(stack, *p, &top, &max);
					}

					else
						push(stack, *p, &top, &max); // ���� �� ���� �켱������ ������ �׳� push�Ѵ�.
				}
			}
		}

		while (isEmpty(&top) != 1) { // �ǿ����ڰ� �� ��µ� ��, ���ÿ� �����ִ� �����ڸ� ��� ������ش�.
			c_pop = pop(stack, &top);
			if (c_pop == '&' || c_pop == '|') {
				printf("%c", c_pop);
				printf("%c", c_pop);
			}
			else
				printf("%c", c_pop);
		}
		printf("\n");
		initStack(stack, &max, &top); // ������ �ʱ�ȭ �� �ش�.
	}
	return 0;
}

void push(char *stack, char c, int *top, int *max) {

	if (*top < *max - 1) { //������ pop �ε����� 100 �̸��� ��츸 push�� �Ѵ�.
		stack[++(*top)] = c;
	}

	else
		printf("������ ���� á���ϴ�.");
}

char pop(char *stack, int *top) {

	char c = stack[*top];
	if (*top >= 0) { // ������ top�� �ε����� 0�� �̻󿡸� pop�� �Ѵ�.
		return stack[(*top)--];
	}
}

char peek(char *stack, int *top) {

	if (*top >= 0) // ������ top �ε����� 0�� �̻��� ��츸 ���� ��Ҹ� ��ȯ�Ѵ�.
		return stack[*top];

}

void print(char *stack, int *top) {

	for (int i = *top; i >= 0; i--) { // 0���� top���� ����Ѵ�.
		printf("%c", stack[i]);
	}
	printf("\n");

}

int isEmpty(int *top) {

	if (*top < 0) //top�� 0 �̸��� ��쿣 ������ �� ���̹Ƿ� 1�� ��ȯ�Ѵ�.
		return 1;
	else
		return 0; // �׷��� ���� ���, 0�� ��ȯ�Ѵ�.
}

int checkPriority(char c) {

	if (c == '!' || c == 'p' || c == 'n')
		return 6;

	else if (c == '*' || c == '/') {
		return 5;
	}

	else if (c == '+' || c == '-') {
		return 4;
	}

	else if (c == '>' || c == '<') {
		return 3;
	}

	else if (c == '&') {
		return 2;
	}

	else if (c == '|') {
		return 1;
	}

	else
		return 0;
}

void makeSimplify(char *str) { // ++, --, &&, || ���� ��� ���ڷ� ó���ϱ⿡ �����ϹǷ� ���� ���ڰ� �� �� �ݺ��Ǵ� ��� �ϳ��� �ٿ��ִ� �Լ��̴�.

	char *p = NULL;
	char *q = NULL;
	int len = 0;

	for (p = str; *p != '\0'; p++) {
		if (*p == '+' && *(p + 1) == '+') {
			*p = 'p';
			for (q = p + 1; *q != '\0'; q++) {
				*q = *(q + 1);
			}
		}

		else if (*p == '-' && *(p + 1) == '-') {
			*p = 'n';
			for (q = p + 1; *q != '\0'; q++) {
				*q = *(q + 1);
			}
		}

		else if (*p == '&' && *(p + 1) == '&') {
			for (q = p + 1; *q != '\0'; q++) {
				*q = *(q + 1);
			}
		}

		else if (*p == '|' && *(p + 1) == '|') {
			for (q = p + 1; *q != '\0'; q++) {
				*q = *(q + 1);
			}
		}
	}
}

void initStack(char *stack, int *max, int *top) {

	for (int i = *max - 1; i >= 0; i--)
		stack[i] = '\0'; // stack�� ��� ��ҵ��� '\0'���� �ʱ�ȭ
	*top = -1;
}