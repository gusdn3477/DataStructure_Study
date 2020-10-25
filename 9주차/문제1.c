#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(char *name, char c, int *top, int *max);
char pop(char *name, int *top);
void print(char *stack, int *top);
void duplicate(char *stack, int N, int *top);
void peek(char *stack, int *top);
void upRotate(char *stack, int h, int *top);
void downRotate(char *stack, int h, int *top);


int main(void) {

	int N, M;
	int top = -1;
	int a;
	int c;
	int len = 0;
	char *stack = NULL;
	char *p = NULL;
	char *q = NULL;
	char str[20] = { '\0' };

	scanf("%d", &N);
	stack = (char *)malloc(sizeof(char) * (N + 1));

	scanf("%d", &M);
	getchar();
	for (int i = 0; i < M; i++) {
		gets(str);
		len = strlen(str);
		for (int i = 0; i < len; i++) {
			if (str[i] == ' ') {
				str[i] = '\0';
				q = str + (i + 1);
			}
		}

		if (strcmp(str, "POP") == 0) {
			pop(stack, &top);
		}

		else if (strcmp(str, "PEEK") == 0) {
			peek(stack, &top);
		}

		else if (strcmp(str, "PRINT") == 0) {
			print(stack, &top);
		}

		else if (strcmp(str, "PUSH") == 0) {
			c = *q;
			push(stack, c, &top, &N);
		}

		else if (strcmp(str, "UpR") == 0) {
			a = *q - '0';
			upRotate(stack, a, &top, &N);
		}

		else if (strcmp(str, "DownR") == 0) {
			a = *q - '0';
			downRotate(stack, a, &top, &N);
		}

		else if (strcmp(str, "DUP") == 0) {
			duplicate(stack, N, &top);
		}

		else {
			printf("다시 입력해 주세요.\n");
		}
	}
	free(stack);

	return 0;
}

void push(char *name, char c, int *top, int *max) {

	if (*top >= *max - 1) {
		printf("Stack FULL\n");
	}

	else {
		name[++(*top)] = c;
	}
}

char pop(char *name, int *top) {

	if (*top < 0) {
		printf("Stack Empty\n");
		return -1;
	}

	else {
		return name[(*top)--];
	}

}

void print(char *stack, int *top) {

	for (int i = *top; i >= 0; i--) {
		printf("%c", stack[i]);
	}

	printf("\n");
}

void peek(char *stack, int *top) {

	printf("%c\n" ,stack[*top]);
}

void duplicate(char *stack, int N, int *top) {

	char c = pop(stack, top);

	if (c != -1) {
		push(stack, c, top, &N);
		push(stack, c, top, &N);
	}

}

void upRotate(char *stack, int h, int *top) {

	char ch = 'a';

	if (h <= *top) {
		ch = stack[*top];
		for (int i = *top; i > *top - h + 1; i--) {
			stack[i] = stack[i - 1];
		}
		stack[*top - h + 1] = ch;
	}
}

void downRotate(char *stack, int h, int *top) {

	char ch = 'a';

	if (h <= *top) {
		ch = stack[*top - h + 1];
		for (int i = *top - h + 1; i < *top; i++) {
			stack[i] = stack[i + 1];
		}
		stack[*top] = ch;
	}

}