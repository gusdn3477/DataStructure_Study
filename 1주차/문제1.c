#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum(int n);

int main(void) {

	int N,M;
	scanf("%d", &N);
	M = sum(N);
	printf("%d", M);

	return 0;
}

int sum(int n) {

	int ans = 0;
	int sum_ = 0;

	for (int i = 1; i <= n; i++) {
		ans += i;
		sum_ += ans;
	}
	return sum_;
}