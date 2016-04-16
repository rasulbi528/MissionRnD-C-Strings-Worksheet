/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
char* removeSpaces(char* str) {
	if (str == 0)
		return '\0';
	else if (*str == '\0')
		return "";
	else {
		char* s = str;
		while (*s++ != ' ') {
			if (*s == '\0')
				return str;
		};
		char* i = --s;
		char* j = i + 1;
		while (*i) {
			if (*j == ' ') {
				*j++;
				continue;
			}
			*i++ = *j++;
		}
		return str;
	}
}