#define MAX 1001
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(char *stack, char c, int *top);
char pop(char *stack, int *top);
char peek(char *stack, int *top);
int empty(char *stack, int *top);

int main(void) {

	char str[MAX] = { '\0' };
	char stack[MAX] = { '\0' };
	char *p = NULL;
	int top = -1;
	int count = 0;
	int flag = 1;

	gets(str);
	
	for (p = str; *p != '\0'; p++) {
		if (*p == '(' || *p == '[' || *p == '{' || *p == ')' || *p == ']' || *p == '}')
			count++;
	}

	for (p = str; *p != '\0'; p++) {
		if (*p == '(' || *p == '[' || *p == '{')
			push(stack, *p, &top);

		if ((*p == ')' || *p == ']' || *p == '}') && empty(stack, &top) == 1) {
			flag = 0;
			break;
		}

		if (*p == ')' || peek(stack, &top) == '(') {
			pop(stack, &top);
		}

		if (*p == ']' || peek(stack, &top) == '[') {
			pop(stack, &top);
		}

		if (*p == '}' || peek(stack, &top) == '{') {
			pop(stack, &top);
		}
	}

	if (flag == 1 && empty(stack, &top) == 1) {
		printf("OK_%d", count);
	}

	else {
		printf("Wrong_%d", count);
	}

	return 0;
}

void push(char *stack, char c, int *top) {

	if (*top >= MAX - 1) {
		printf("STACK FULL");
	}

	else {
		stack[++(*top)] = c;
	}

}

char pop(char *stack, int *top) {

	if (*top < 0) {
		return -1;
	}

	else {
		return stack[(*top)--];
	}
}

char peek(char *stack, int *top) {

	if(*top < 0)
		return stack[*top];
}

int empty(char *stack, int *top) {

	if (*top < 0)
		return 1;
	else
		return 0;
}