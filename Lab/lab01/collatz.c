// Lab 01 : (Dis)Proving the Collatz Conjecture
// Made by Kevin Edbert Sutandi (z5352065)
// Date 20 January 2022

#include <stdio.h>
#include <stdlib.h>

// Recursive Function (necessary)
void collatz(int firstnum) {
	printf("%d\n", firstnum);
	if (firstnum == 1) {
		return;
	} else if (firstnum % 2 == 0) {
		firstnum = firstnum / 2;
		collatz(firstnum);
	} else if (firstnum % 2 != 0) {
		firstnum = (3 * firstnum) + 1;
		collatz(firstnum);
	}
}

int main(int argc, char **argv)
{
	int firstnum = atoi(argv[1]); 
	collatz(firstnum);
	return EXIT_SUCCESS;
}
