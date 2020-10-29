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
			if (*p >= 'A' && *p <= 'Z') // 알파벳의 경우, 출력
				printf("%c", *p);

			else if (*p == '(') { // '(' 인 경우
				push(stack, *p, &top, &max); // '('의 경우, 스택에 집어넣는다.
			}

			else if (*p == ')') { // ')'의 경우, '('을 만나기 전 까지 모두 출력해주고, 마지막으로 pop을 해줘서 '('도 제거한다.
				while (peek(stack, &top) != '(') {
					c_pop = pop(stack, &top);
					printf("%c", c_pop);
				}
				pop(stack, &top);
			}

			else {
				if (isEmpty(&top) == 1) // 스택이 비었으면 바로 push 한다.
					push(stack, *p, &top, &max);

				else { //그렇지 않은 경우,
					check = peek(stack, &top); // 스택의 최상위에 있는 요소를 check 변수에 담은 뒤에
					if (checkPriority(check) >= checkPriority(*p)) { // 우선순위를 비교하여 stack의 최상위에 있는 것이 우선순위가 높은 경우, 빼낸 뒤 출력한 뒤, push를 해준다.

						while (checkPriority(check) >= checkPriority(*p) && isEmpty(&top) != 1) {
							c_pop = pop(stack, &top);
							if (c_pop == '&' || c_pop == '|') { // &&와 ||은 각각 &,|로 축소되었으므로 두 번 출력하는 과정을 거친다.
								printf("%c", c_pop);
								printf("%c", c_pop);							}
							else
								printf("%c", c_pop);
						}
						push(stack, *p, &top, &max);
					}

					else
						push(stack, *p, &top, &max); // 새로 들어갈 것이 우선순위가 높으면 그냥 push한다.
				}
			}
		}

		while (isEmpty(&top) != 1) { // 피연산자가 다 출력된 뒤, 스택에 남아있는 연산자를 모두 출력해준다.
			c_pop = pop(stack, &top);
			if (c_pop == '&' || c_pop == '|') {
				printf("%c", c_pop);
				printf("%c", c_pop);
			}
			
			else if (c_pop == 'p'){
				printf("++");
			}
			
			else if (c_pop == 'n'){
				printf("--");
			}
			
			else
				printf("%c", c_pop);
		}
		printf("\n");
		initStack(stack, &max, &top); // 스택을 초기화 해 준다.
	}
	return 0;
}

void push(char *stack, char c, int *top, int *max) {

	if (*top < *max - 1) { //스택의 pop 인덱스가 100 미만인 경우만 push를 한다.
		stack[++(*top)] = c;
	}

	else
		printf("스택이 가득 찼습니다.");
}

char pop(char *stack, int *top) {

	char c = stack[*top];
	if (*top >= 0) { // 스택의 top의 인덱스가 0인 이상에만 pop을 한다.
		return stack[(*top)--];
	}
}

char peek(char *stack, int *top) {

	if (*top >= 0) // 스택의 top 인덱스가 0인 이상인 경우만 현재 요소를 반환한다.
		return stack[*top];

}

void print(char *stack, int *top) {

	for (int i = *top; i >= 0; i--) { // 0부터 top까지 출력한다.
		printf("%c", stack[i]);
	}
	printf("\n");

}

int isEmpty(int *top) {

	if (*top < 0) //top이 0 미만인 경우엔 스택이 빈 것이므로 1을 반환한다.
		return 1;
	else
		return 0; // 그러지 않은 경우, 0을 반환한다.
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

void makeSimplify(char *str) { // ++, --, &&, || 같은 경우 문자로 처리하기에 불편하므로 같은 문자가 두 번 반복되는 경우 하나로 줄여주는 함수이다.

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
		stack[i] = '\0'; // stack의 모든 요소들을 '\0'으로 초기화
	*top = -1;
}
