#include <stdio.h>
#include <stdlib.h>

void push(char *stack, char c, int *top, int *max);
char pop(char *stack, int *top);
char peek(char *stack, int *top);
void print(char *stack, int *top);
int isEmpty(int *top);

int main(void) {

	int stack[101] = { 0 }; // 사칙연산은 push 될 일이 없으므로 int형 배열로 설정합니다.
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
				a = *p - '0'; //숫자로 만들어서 스택에 넣습니다.
				push(stack, a, &top, &max);
			}
		}

		a = pop(stack, &top);
		printf("%d\n", a);
	}
	return 0;
}

void push(char *stack, int c, int *top, int *max) {

	if (*top < *max - 1) { //스택의 pop 인덱스가 100 미만인 경우만 push를 한다.
		stack[++(*top)] = c;
	}

	else
		printf("스택이 가득 찼습니다.");
}

int pop(char *stack, int *top) {

	if (*top >= 0) { // 스택의 top의 인덱스가 0인 이상에만 pop을 한다.
		return stack[(*top)--];
	}

}

char peek(char *stack, int *top) {

	if (*top >= 0) // 스택의 top 인덱스가 0인 이상인 경우만 현재 요소를 반환한다.
		return stack[*top];

}

void print(int *stack, int *top) {

	for (int i = 0; i <= *top; i++) { // 0부터 top까지 출력한다.
		printf("%d", stack[i]);
	}
	printf("\n");

}

int isEmpty(int *top) {

	if (*top < 0) //top이 0 미만인 경우엔 스택이 빈 것이므로 1을 반환한다.
		return 1;
	else
		return 0; // 그러지 않은 경우, 0을 반환한다.
}