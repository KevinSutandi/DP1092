// Lab 01 : Calculating the Fibonacci Sequence The (Not So) Fast Way
// Made by Kevin Edbert Sutandi (z5352065)
// Date 20 January 2022
#include <stdio.h>
#include <stdlib.h>

#define SERIES_MAX 46

int fibonacci(int already_computed[], int input) {
    // If value of input goes below 0 or above max, return zero
    if (input <= 0 || input >= SERIES_MAX + 1) {
        return 0;
    }
    // If value already exists return from array 
    else if (already_computed[input] != 0) {
        return already_computed[input];
    } else {
        // Finding the value of the fibonnaci of input
        int fibo = fibonacci(already_computed, input - 1) + 
        fibonacci(already_computed, input - 2);
        // Placing the value to the array
        already_computed[input] = fibo;
        return fibo;
    }
}

int main(void) {
    // Memoization ( N in array = stores value of Fn)
    int already_computed[SERIES_MAX + 1] = { 0, 1 };
    int input;

    //loop scanf until EOF
    while (scanf("%d", &input) != EOF) {
        int value = fibonacci(already_computed, input);
        printf("%d\n", value); 
    }
    return EXIT_SUCCESS;
}
