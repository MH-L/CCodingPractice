#include <stdlib.h>
int main() {
	int a = 9;
	int b = 19;
	int c = 29;
	int d = 37;
	int e = 40;
	int f = 22;
	int g = 17;
	int h = 78;
	int i = 98;
	int j = 100;
	int k = 12;
	int l = 13;
	int m = 15;
	int n = 26;
	int q = 90;
	int* arr = (int*) malloc(15*sizeof(int));
	*arr = a;
	*(arr+1) = k;
	*(arr+2) = l;
	*(arr+3) = m;
	*(arr+4) = g;
	*(arr+5) = b;
	*(arr+6) = f;
	*(arr+7) = n;
	*(arr+8) = c;
	*(arr+9) = d;
	*(arr+10) = e;
	*(arr+11) = h;
	*(arr+12) = q;
	*(arr+13) = i;
	*(arr+14) = j;
	printf("%i", isSorted(arr, 15));
	printf("\n%i\n", binarySearch(arr, 15, 102));
	reverse(arr, 15);
	printf("%i\n", isSorted(arr, 15));
}

int isSorted(int* arr, int size) {
	int order = 0;
	for (int i = 0; i < size - 1; i++) {
		if (order == 0) {
			if (*(arr + i) > *(arr + i + 1))
				order = -1;
			else if (*(arr + i) < *(arr + i + 1))
				order = 1;
		} else if (order == -1) {
			if (*(arr + i) < *(arr + i + 1))
				return 0;
		} else if (*(arr + i) > *(arr + i + 1)) {
			printf("The order is: %i\n", order);
			return 0;
		}
	}
	return 1;
}

int binarySearch(int* arr, int size, int toFind) {
	return binarySearchHelper(arr, 0, size - 1, toFind);
}

int binarySearchHelper(int* arr, int start, int end, int toFind) {
	if (start == end)
		if (*(arr + start) == toFind)
			return start;
		else
			return -1;
	int mid = (start + end) / 2;
	int midNum = *(arr + mid);
	if (midNum == toFind)
		return mid;
	else if (midNum > toFind)
		if (mid == start)
			return -1;
		else
			return binarySearchHelper(arr, start, mid - 1, toFind);
	else
		return binarySearchHelper(arr, mid + 1, end, toFind);
}

void reverse(int* arr, int size) {
	int low = 0, high = size - 1;
	while (low < high) {
		int temp = *(arr + low);
		*(arr + low) = *(arr + high);
		*(arr + high) = temp;
		low ++;
		high --;
	}
}

void inPlaceQuickSort(int* arr, int size) {
	
}
