// Lab 01 : Turn all uppercase to Lowercase
// Made by Kevin Edbert Sutandi (z5352065)
// Date 19/January/2022

#include <stdio.h>
#include <ctype.h>

int main(void) {
	char ch = getchar();
	while (ch != EOF) {
		putchar(tolower(ch));
		ch = getchar();
	}
	return 0;
}
