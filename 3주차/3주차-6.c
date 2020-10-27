#include <stdio.h>
#include <string.h>

int recursive(int a, int b);

int main(void) {

	int a, b,c;
	scanf("%d %d", &a, &b);
	c = recursive(a, b);

	printf("%d", c);
	return 0;
}

int recursive(int a, int b) {

	if (b == 0) {
		return a;
	}

	else {
		return recursive(b, a%b);
	}

}