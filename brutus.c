#include <stddef.h>
#include "brutus.h"

#define ASCII_RANGE	26

char
brutus_ascii(int shift, char c)
{
	if (c >= 'a' && c <= 'z') {
		return (c + shift - 'a') % ASCII_RANGE + 'a';
	}
	if (c >= 'A' && c <= 'Z') {
		return (c + shift - 'A') % ASCII_RANGE + 'A';
	}
	return c;
}

char *
brutus_rot13(char *str)
{
	static char buf[4096];	/* TODO(irek): Convenien but dengerous. */
	size_t i;
	buf[0] = 0;
	for (i=0; str[i]; i++) {
		buf[i] = brutus_ascii(13, str[i]);
	}
	buf[i] = 0;
	return buf;
}
