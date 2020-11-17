#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int findMax(int *arr, int N);

int main(void) {

	int N,M;
	int arr[20] = { 0 };

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	M = findMax(arr, N);
	printf("%d", M);

	return 0;
}

int findMax(int *arr, int N) {

	if (N == 1)
		return *arr;

	if (arr[0] > arr[1])
		arr[1] = arr[0];

	return findMax(arr + 1, N-1);

}