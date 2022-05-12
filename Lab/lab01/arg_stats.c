// Lab 01 : Statistical Analysis of Command Line Arguments
// Made by Kevin Edbert Sutandi (z5352065)
// Date 19 January 2022

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	// innitializing variables that are going to be printed 
	int min = atoi(argv[1]);
	int max = atoi(argv[1]);
	int sum = 0;
	int multi = 1;

	int counter = 1;
	while (counter < argc) {
		// For finding minimal
		if (atoi(argv[counter]) < min) {
			min = atoi(argv[counter]);
		}
		// For finding maximal
		if (atoi(argv[counter]) > max) {
			max = atoi(argv[counter]);
		}
		// For finding sum
		sum = sum + atoi(argv[counter]);
		// For finding product
		multi = multi * atoi(argv[counter]);

		counter++;
	}
	// Find mean after while loop is finished
	int mean = sum / (argc - 1);

	printf("MIN:  %d\n", min);
	printf("MAX:  %d\n", max);
	printf("SUM:  %d\n", sum);
	printf("PROD: %d\n", multi);
	printf("MEAN: %d\n", mean);

	return 0;
}
 