#include <stdio.h>
#include <stdlib.h>

void recursive(int N, int M);

int main(void) {

	int N, M;
	scanf("%d %d", &N, &M);
	recursive(N, M);

	return 0;
}

void recursive(int N, int M) {

	int **a = NULL;
	int start = 1;
	int x = 0, y = 0;
	int i, j;
	int x_temp, y_temp;
	a = (int **)malloc(sizeof(int *) * N);

	if (a == NULL) {
		printf("동적 할당 실패");
	}

	for (i = 0; i < N; i++) {
		a[i] = (int *)malloc(sizeof(int) * M);
		if (a[i] == NULL) {
			printf("동적 할당 실패!");
		}
	}

	// 열 먼저 하고, 행 먼저 돌아야 할듯..

	for (i = 0; i < M; i++) {
		x_temp = i;
		y_temp = 0;

		while (x_temp >= 0 && y_temp < N) {
			a[y_temp][x_temp] = start++;
			y_temp++;
			x_temp--;
		}
	}

	for (j = 1; j < N; j++) {
		x_temp = M - 1;
		y_temp = j;

		while (x_temp >= 0 && y_temp < N) {
			a[y_temp][x_temp] = start++;
			y_temp++;
			x_temp--; 
		}
	}


	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			printf(" %2d", a[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < N; i++) {
		free(a[i]);
	}
	free(a);
}