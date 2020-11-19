#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isBalanced(char *str);

int main(void) {

	char str[MAX] = { '\0' };
	scanf("%s", str);

	printf("%d\n", isBalanced(str));
	scanf("%s", str);
	printf("%d\n", isBalanced(str));
	scanf("%s", str);
	printf("%d\n", isBalanced(str));
	scanf("%s", str);
	printf("%d\n", isBalanced(str));

	return 0;
}

bool isBalanced(char *str) {

	char check[MAX] = { '\0' };
	char *p = NULL;
	int top = -1;
	int len = strlen(str);

	for (p = str; p < str + len; p++) {
		if (*p == '(' || *p == '{' || *p == '[')
			check[++top] = *p;

		if (*p == ')') {
			if (check[top] == '(')
				check[top--] = '\0';
			else
				return false;
		}

		if (*p == '}') {
			if (check[top] == '{')
				check[top--] = '\0';
			else
				return false;
		}

		if (*p == ']') {
			if (check[top] == '[')
				check[top--] = '\0';
			else
				return false;
		}
	}

	if (top == -1)
		return true;
	else
		return false;
}
