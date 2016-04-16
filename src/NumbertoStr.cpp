/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/
#include <stdio.h>
int reverseNum(int n) {
	int rem, rev = 0;
	while (n) {
		rem = n % 10;
		rev = rev * 10 + rem;
		n /= 10;
	}
	return rev;
}
unsigned long int powInt(unsigned long int p, int r) {
	while (r--) p *= 10;
	return p;
}
void number_to_str(float number, char *str,int afterdecimal){
	float _f = number;
	if (number < 0)
		number *= -1;
	int r = reverseNum((int)number);
	unsigned long int d = reverseNum((unsigned long int)(number * powInt(1, afterdecimal)) % powInt(1, afterdecimal));
	char* s = str;
	if (_f < 0) *s++ = '-';
	while (r) {
		*s++ = (char)('0' + r % 10);
		r /= 10;
	}
	if (afterdecimal == 0 || d == 0) *s = '\0';
	*s++ = '.';
	while (d) {
		*s++ = (char)('0' + d % 10);
		d /= 10;
	}
	*s = '\0';
}