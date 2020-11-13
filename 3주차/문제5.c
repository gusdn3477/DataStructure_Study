#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hanoi(int N, char start, char mid, char end);

int main(void) {

	int N;
	scanf("%d", &N);
	hanoi(N, 'A', 'B', 'C');

	return 0;
}

void hanoi(int N, char start, char mid, char end) {

	if (N == 1) {
		printf("%c %c\n", start, end);
	}

	else {
		hanoi(N - 1, start, end, mid);
		printf("%c %c\n", start, end);
		hanoi(N - 1, mid, start, end);
	}
}
