#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *period(int *arr, int N);

int main(void) {

	int N;
	int arr[100] = { 0 };
	int *p;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	p = period(arr, N);

	for (int i = 0; i < N; i++)
		printf("%d ", p[i]);

	free(p);
	return 0;
}

int *period(int *arr, int N) {

	int *p = (int *)malloc(sizeof(int) * N);

	if (p == NULL) {
		printf("동적 할당 실패!\n");
		return -1;
	}

	for (int i = 0; i < N; i++)
		p[i] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (arr[j] <= arr[i])
				p[i]++;
			else
				p[i] = 0;
		}
	}

	return p;
}