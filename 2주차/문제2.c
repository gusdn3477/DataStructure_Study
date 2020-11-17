#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int modulo(int a, int b);

int main(void) {

	int a, b,c;
	
	scanf("%d %d", &a, &b);

	c = modulo(a, b);
	printf("%d", c);

	return 0;
}

int modulo(int a, int b) {

	if (a < b)
		return a;
	else
		return modulo(a - b, b);

}