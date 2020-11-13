#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main(void) {

	int N;
	int a, b;
	int *arr = NULL;

	scanf("%d", &N);
	arr = (int *)malloc(sizeof(int)* N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	scanf("%d %d", &a, &b);
	swap(arr + a, arr + b);

	for (int i = 0; i < N; i++)
		printf(" %d", arr[i]);

	free(arr);


	return 0;
}

void swap(int *a, int *b) {

	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

}