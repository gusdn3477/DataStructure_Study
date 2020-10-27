#include <stdio.h>
#include <stdlib.h>

void recursive(int N);

int main(void) {

	int N;
	scanf("%d", &N);
	recursive(N);

	return 0;
}

void recursive(int N) {

	int **a = NULL;
	int start = 1;
	a = (int **)malloc(sizeof(int *) * N);

	if (a == NULL) {
		printf("동적 할당 실패");
	}

	for (int i = 0; i < N; i++) {
		a[i] = (int *)malloc(sizeof(int) * N);
	}

	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < N; j++) {
				a[i][j] = start++;
			}
		}

		else {
			for (int j = N - 1; j >= 0; j--) {
				a[i][j] = start++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf(" %d", a[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < N; i++) {
		free(a[i]);
	}
	free(a);
}