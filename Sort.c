#include<stdio.h>
int main() {
	int* arr = (int*) malloc(6*sizeof(int));
	arr[0] = 13;
	arr[1] = 9;
	arr[2] = 18;
	arr[3] = 15;
	arr[4] = 10;
	arr[5] = 12;
	printf("%d,%d,%d,%d,%d,%d\n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
	inPlaceQuickSort(arr, 6);
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

void inPlaceSelectionSort(int* arr, int size) {
	int ctr = 0;
	int maxIndex = ctr;
	while (ctr < size) {
		for (int i = ctr; i < size; i++) {
			if (arr[i] > arr[maxIndex]) {
				maxIndex = i;
			}
		}
		int temp = arr[ctr];
		arr[ctr] = arr[maxIndex];
		arr[maxIndex] = temp;
		ctr++;
		maxIndex = ctr;
	}
}

void inPlaceQuickSort(int* arr, int size) {
	if (size <= 1)
		return;
	int pivot = *arr;
	int forwardCounter = 1;
	int backwardCounter = size - 1;
	while (forwardCounter < backwardCounter) {
		if (arr[forwardCounter] <= pivot) {
			int temp = arr[forwardCounter];
			arr[forwardCounter] = pivot;
			arr[forwardCounter - 1] = temp;
			forwardCounter ++;
		} else {
			int temp = arr[backwardCounter];
			arr[backwardCounter] = arr[forwardCounter];
			arr[forwardCounter] = temp;
			backwardCounter --;
		}
	}
	inPlaceQuickSort(arr, forwardCounter - 1);
	inPlaceQuickSort(arr + backwardCounter, size - forwardCounter);
}
