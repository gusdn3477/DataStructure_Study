#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int modulo(int a, int b);

int main(void) {

	int a, b;
	int ans;

	scanf("%d %d", &a, &b);
	ans = modulo(a, b);
	printf("%d", ans);

	return 0;
}

int modulo(int a, int b) {

	int c = a / b;

	for (int i = 0; i < c; i++)
		a -= b;

	return a;

}