#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void die(const char *message)
{
	if (errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}
	
	exit(1);
}

int power(int base, int exponent)
{
	int result = 1;
	int i = 0;
	for (i = 0; i < exponent; i++) {
		result *= base;
	}
	return result;
}

int main(int argc, char *argv[])
{
	// make sure args are good.
	if (argc != 2) {
		die("USAGE: letter_permutation number_of_letters.");
	}
	
	int letter_count = atoi(argv[1]);
	// check to make sure is not zero.
	if (letter_count <= 0) {
		die("USAGE: letter_permutation number_of_letters.");
	}
	
	int a = 0;
	int b = 0;
	int alphabet_count = 26;
	char *letters = malloc(letter_count + 1);
	for (b = 0; b < power(alphabet_count, letter_count); b++) {
		for (a = 1; a <= letter_count; a++) {
			letters[letter_count - a] = (b % power(26, a)) / power(26, a - 1) + 97;
		}
		printf("%s\n", letters);
	}
}
