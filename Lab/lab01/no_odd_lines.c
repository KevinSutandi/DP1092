// Lab 01 : Remove Uneven Lines of Input
// Made by Kevin Edbert Sutandi (z5352065)
// Date : 19 January 2022
#include <stdio.h>
#include <string.h>

int main(void) {
	//maximum of 1024 characters
	//+1 due to \n
	char ch[1025];
	while (fgets(ch, 1025, stdin) != NULL) {
		if (strlen(ch) % 2 != 1) {
			fputs(ch, stdout);
		}
	}
	return 0;
}
