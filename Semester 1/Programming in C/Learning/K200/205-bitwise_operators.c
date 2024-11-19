/* bitwise_operators.c binary operations */
/* TO DO 1: Something is wrong with the output 
	   Hint: put the output first into an additional variable m, 
	   use bitwise operators and count the digits */
/* TO DO 2: A second number should be entered and 
	   both numbers should be combined with the various bitwise
	   operators before providing the output */
/* TO DO 3: Use signed integers and see how negative numbers 
           are presented in binary format */

#include <stdio.h>

void DecimalToBinary(int number) {
	unsigned int m = 0, size = number;
	while (number > 0) {
		const int binary = number & 1;
		// printf("%d", binary);

		m <<= 1;
		m |= binary;
		number >>= 1;
	}

	do {
		printf("%d", m & 1);
		m >>= 1;
		size >>= 1;
	} while (size > 0);
}

void AndOperation(const int first, const int second) {
	const int result = first & second;
	printf("%d", result);
}

int main() {
	unsigned int num;

	printf("Please enter an integer number:");
	scanf("%u", &num); // Input unsigned integer from console

	DecimalToBinary(num);

	unsigned int second;
	printf("\nPlease enter your second integer number:");
	scanf("%u", &second);

	DecimalToBinary(second);
	AndOperation(num, second);
}
