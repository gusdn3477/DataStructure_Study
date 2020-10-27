#include <stdio.h>
#include <stdlib.h>

void print_dal();

int main(void) {

	print_dal();

	return 0;
}

void print_dal() {

	int arr[100][100] = { 0 };
	int N,M;
	int N2, M2;
	int x = -1, y = 0;
	int start = 1;

	scanf("%d %d", &N, &M);
	N2 = N - 1;
	M2 = M;

	while (start <= N * M) {
		for (int i = 0; i < M2; i++)
			arr[y][++x] = start++;

		M2--;
		for (int i = 0; i < N2; i++)
			arr[++y][x] = start++;

		N2--;

		for (int i = 0; i < M2; i++)
			arr[y][--x] = start++;

		M2--;

		for (int i = 0; i < N2; i++)
			arr[--y][x] = start++;

		N2--;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}

}
