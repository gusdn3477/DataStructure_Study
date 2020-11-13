#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ABC(int arr[], int k);

int main(void) {

	int arr[10] = { 0 };

	for (int i = 0; i < 10; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < 10; i++) {
		ABC(arr, i);
	}

	for (int i = 0; i < 10; i++) {
		printf(" %d", arr[i]);
	}
	
	return 0;
}

void ABC(int arr[], int k) {

	int temp;
	int index;
	int i;
	int max = arr[k];
	for (i = k; i < 10; i++) {
		if (arr[i] > max) {
			index = i;
			max = arr[i];
		}
	}

	if (max != arr[k]) {
		temp = arr[index];
		arr[index] = arr[k];
		arr[k] = temp;
	}

}