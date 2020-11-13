#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int func(int x);

int main(void) {

	int N,M;
	scanf("%d", &N);

	M = func(N);
	printf("%d", M);

	return 0;
}

int func(int x) {

	if (x == 1)
		return 1;
	else
		return x + func(x-1);
}