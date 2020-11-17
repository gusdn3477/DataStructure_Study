#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int* prefixAverages1(int *arr, int n);
int* prefixAverages2(int *arr, int n);

int main(void) {

	time_t start, mid, end;
	int *arr = NULL;
	int *p, *q;
	int X;
	
	srand(time(NULL));

	scanf("%d", &X);

	arr = (int *)malloc(sizeof(int) * X);

	for (int i = 0; i < X; i++)
		arr[i] = rand() % 10000 + 1;

	start = clock();
	p = prefixAverages1(arr, X);
	mid = clock();
	q = prefixAverages2(arr, X);
	end = clock();

	printf("%fms\n%fms", (double)(mid-start), (double)(end-mid));
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