#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int* prefixAverages1(int *arr, int n);
int* prefixAverages2(int *arr, int n);

int main(void) {

	int *arr = NULL;
	int *p, *q;
	int X;
	
	scanf("%d", &X);

	arr = (int *)malloc(sizeof(int) * X);

	for (int i = 0; i < X; i++)
		scanf("%d", &arr[i]);

	p = prefixAverages1(arr, X);
	q = prefixAverages2(arr, X);

	for (int i = 0; i < X; i++)
		printf("%d ", p[i]);

	printf("\n");

	for (int i = 0; i < X; i++)
		printf("%d ", q[i]);

	free(arr);
	free(p);

	return 0;
}

int* prefixAverages1(int *arr, int n) {

	int sum = 0;
	int *A = (int *)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j <= i; j++) {
			sum += arr[j];
		}
		A[i] = sum / (i + 1);
	}
	return A;
}

int* prefixAverages2(int *arr, int n) {

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		arr[i] = sum / (i + 1);
	}

	return arr;
}