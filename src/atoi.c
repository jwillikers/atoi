#include "atoi.h"
#include <ctype.h>
#include <stddef.h>

int my_atoi(char const * c) {
	if (c == NULL) {
		return 0;
	}

	if (*c == '\0') {
		return 0;
	}

	// Account for a leading positive or negative sign.
	int sign = 1;
	if (*c == '+' || *c == '-') {
		if (*c == '-') {
			sign = -1;
		}
		c++;
	}

	// Read in each successive characters until a non-digit character is reached.
	int value = 0;
	for (; isdigit(*c); ++c) {

		// Multiply the current value by ten to account for the next digit.
		value *= 10;

		// Cast the current char value to an integer and it to the one's place of value.
		value += (int) (*c - '0');
	}

	return value * sign;
}
