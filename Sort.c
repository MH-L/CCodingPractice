#include<stdio.h>
int main() {
	int* arr = (int*) malloc(6*sizeof(int));
	arr[0] = 13;
	arr[1] = 9;
	arr[2] = 18;
	arr[3] = 15;
	arr[4] = 10;
	arr[5] = 12;
	inPlaceBubbleSort(arr, 6);
	printf("%d,%d,%d,%d,%d,%d", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
}

void inPlaceBubbleSort(int* arr, int size) {
	// Sort array in increasing order.
	int noProb = 1;
	int isSorted = 0;
	while (!isSorted) {
		for (int index = 0; index < size - 1; index++) {
			if (*(arr + index) > *(arr + index + 1)) {
				int temp = *(arr + index);
				*(arr + index) = *(arr + index + 1);
				*(arr + index + 1) = temp;
				noProb = 0;
			}
		}
		if (noProb)
			isSorted = 1;
		else
			noProb = 1;
	}
}
