/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void SWAP(char* x, char* y) {
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}
char* REVERSE_STRING(char* str, int start_index, int word_length) {
	int i, j;
	for (i = start_index, j = 0; i < (start_index + word_length / 2); i++, j++)
		SWAP(str + i, str + start_index + word_length - j - 1);
	return str;
}
void str_words_in_rev(char *input, int len){
	int i = 0, start_index = 0, word_length = 0;
	while (i <= len) {
		if (input[i] == ' ' || input[i] == '\0') {
			input = REVERSE_STRING(input, start_index, word_length);
			word_length = -1;
			start_index = i + 1;
		}
		i++;
		word_length++;
	}
	REVERSE_STRING(input, 0, len);
}