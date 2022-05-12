// Lab 01: Removing Vowels From STDIN
// Made by : Kevin Edbert Sutandi (z5352065)
// Date : 19 January 2022

#include <stdio.h>
#include <string.h>

int main(void) {
	// init char for character input
	char ch;
	const char *vowels = "aeiouAEIOU";
	
	// Loop to print out non vowel chars
	while (scanf("%c", &ch) != EOF) {
		// Check if character contains a vowel and 
		// if char does not contain print the char out
		if (strchr(vowels, ch) == 0) {
			printf("%c", ch);
		}
	}
} 