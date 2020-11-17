#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int N,M;
	int save;
	int arr[100] = { 0 };
	int arr2[100] = { 0 };

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &arr2[i]);
	}

	save = arr[arr2[M - 1]]; 

	for (int i = M - 1; i >= 2; i--) {
		arr[arr2[i]] = arr[arr2[i - 1]];
	}

	arr[arr2[1]] = save; // save에 저장해 둔 값을 대입한다.

	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);


	return 0;
}