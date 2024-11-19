/* prime sieve of Eratosthenes */
// TO DO 1: The program seems to work, but look carefully at the results -> There is a (typical) bug
// TO DO 2: Extend it such that the maximum number n to be calculated can be entered by the user
//          Use scanf("%d", &n)
// TO DO 3: What does this mean for the array? How should the program be adapted to work reliably? 

#include <stdio.h>

#define Max 999999

void PrimeNumbers(const int maximum) {
    if (maximum > Max) {
        printf("Number is higher than the allowed maximum");
        return;
    }

    char is_prime[Max];
    int i;

    /* Initialize Array */
    for (i = 0; i < maximum; i++) {
        is_prime[i] = 1;
    }

    for (i = 2; i < maximum; i++) {
        for (int j = 2 * i; j < maximum; j = j + i) {
            is_prime[j] = 0;
        }
    }

    printf("Prime numbers are: ");
    for (i = 2; i < maximum; i++) {
        if (is_prime[i] > 0) {
            printf("%d ", i);
        }
    }
}

int main() {
    int maximum;
    printf("Enter the maximum number: ");
    scanf("%d", &maximum);

    PrimeNumbers(maximum);
}
