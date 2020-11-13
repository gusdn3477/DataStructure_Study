#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void func(int x);

int main(void) {

	int N;
	scanf("%d", &N);

	func(N);
	
	return 0;
}

void func(int x) {

	if (x > 0) {
		func(x / 10);
		printf("%d\n", x % 10);
	}

	else
		return;
}