#include <stdlib.h>
#include <stdio.h>
#include "shuffle.h"
#define DEFAULT_SIZE 200
int main() {
	int* arr = (int*) malloc(DEFAULT_SIZE * sizeof(int));
	for (int i = 0; i < DEFAULT_SIZE; i++) {
		arr[i] = i;
	}
	shuffleArray(arr, DEFAULT_SIZE);
	for (int i = 0; i < DEFAULT_SIZE; i++) {
		printf("%d\n", arr[i]);
	}
}

void shuffleArray(int* arr, int size) {
	time_t t;
	srand((unsigned) time(&t));
	int shuffledCounter = 0;
	while (shuffledCounter < size) {
		int randBase = size - shuffledCounter;
		int index = rand() % randBase;
		int temp = arr[index];
		arr[index] = arr[shuffledCounter];
		arr[shuffledCounter] = temp;
		shuffledCounter ++;
	}	
}
