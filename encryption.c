#include<stdlib.h>
#include<stdio.h>

#define BASE 256

long encrypt(long candidate, int cycle);
long encrypt2(int candidate, int cycle);

int main() {
	printf("%d", encrypt2(2223, 188));
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

long encrypt2(int candidate, int cycle) {
	long primes[16] = {7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
	long mystery = 997;
	long combined = candidate * mystery;
	int output = 0;
	for (int i = 0; i < 8; i++) {
		output = output << 8;
		output += (combined % primes[i]) * primes[i + 8] * BASE;
	}
	
	for (int j = 0; j < cycle; j++) {
		int newOut = 0;
		for (int i = 0; i < 8; i++) {
			newOut = newOut << 8;
			newOut += (output % primes[i]) * primes[i + 8] * BASE;
		}
		output += newOut;
	}
	return output;
}
