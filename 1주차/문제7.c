#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int N;
	int *arr = NULL;
	int *arr2 = NULL;
	int *arr3 = NULL;

	scanf("%d", &N);
	arr = (int *)malloc(sizeof(int) * N);
	arr2 = (int *)malloc(sizeof(int) * N);
	arr3 = (int *)malloc(sizeof(int) * N);
	if (arr == NULL || arr2 == NULL || arr3 == NULL)
		printf("동적 할당 실패!");

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr2[i]);

	for (int i = 0; i < N; i++) {
		arr3[i] = arr[i] + arr2[N - i - 1];
	}

	for (int i = 0; i < N; i++) {
		printf(" %d", arr3[i]);
	}

	free(arr);
	free(arr2);
	free(arr3);
	return 0;
}
