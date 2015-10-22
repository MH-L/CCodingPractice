#include<stdlib.h>
#include<stdio.h>

long encrypt(long candidate, int cycle);

int main() {
	printf("%d", encrypt(6657868557, 10));
}

long encrypt(long candidate, int cycle) {
	long primes[16] = {7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
	long mystery = 997;
	long combined = candidate * mystery;
	int output = 0;
	for (int i = 0; i < 8; i++) {
		output += (combined % primes[i]) * primes[i + 8];
	}
	
	for (int j = 0; j < cycle; j++) {
		for (int i = 0; i < 8; i++) {
			output += (output % primes[i]) * primes[i + 8];
		}
	}
	return output;
} 
