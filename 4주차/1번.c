#include <stdio.h>
#include <stdlib.h>

int* reverse(int arr[], int N);

int main(void) {

	int N;
	int arr[100] = { 0 };
	int *arr2 = NULL;
	int *p = NULL;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	arr2 = reverse(arr, N);
	for (p = arr2; p < arr2 + N; p++) {
		printf(" %d", *p);
	}

	return 0;
}

int* reverse(int arr[], int N) {

	int M;
	int a, b;
	int j = 0;
	int *pocket = NULL;
	int *temp = NULL;
	scanf("%d", &M);

	pocket = (int *)malloc(sizeof(int) * M * 2);
	if (pocket == NULL) {
		printf("동적 할당 실패!");
	}

	for (int i = 0; i < M * 2; i++) {
		scanf("%d", &pocket[i]);
	}

	for (int i = 0; i < M * 2; i += 2) {
		a = pocket[i];
		b = pocket[i + 1];
		temp = (int *)malloc(sizeof(int) * (b - a + 1));
		if (temp == NULL) {
			printf("동적 할당 실패!");
		}

		j = 0;
		for (int i = b; i >= a; i--) {
			temp[j++] = arr[i];
		}

		j = 0;
		for (int i = a; i <= b; i++) {
			arr[i] = temp[j++];
		}
		free(temp);
	}
	free(pocket);
	return arr;

}