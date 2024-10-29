#include "brutus.h"

#define ASCII_RANGE	('z' - 'a' + 1)

static int
str_index_of(char *str, char c)
{
	int i;
	for (i=0; str[i]; i++) {
		if (str[i] == c) {
			return i;
		}
	}
	return -1;
}

static unsigned
str_length(char *str)
{
	unsigned i;
	for (i=0; str[i]; i++);
	return i;
}

char
brutus_ascii_char(int shift, char c)
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
brutus_ascii(int shift, char *str)
{
	static char buf[BRUTUS_BUFSIZ];
	int i;
	buf[0] = 0;
	for (i=0; str[i]; i++) {
		buf[i] = brutus_ascii_char(shift, str[i]);
	}
	buf[i] = 0;
	return buf;
}

char *
brutus_rot13(char *str)
{
	return brutus_ascii(13, str);
}

char
brutus_char(char *alphabet, int shift, char c)
{
	int i;
	i = str_index_of(alphabet, c);
	if (i == -1) {
		return c;
	}
	i = (i + shift) % str_length(alphabet);
	return alphabet[i];
}

char *
brutus_custom(char *alphabet, int shift, char *str)
{
	static char buf[BRUTUS_BUFSIZ];
	int i;
	buf[0] = 0;
	for (i=0; str[i]; i++) {
		buf[i] = brutus_char(alphabet, shift, str[i]);
	}
	buf[i] = 0;
	return buf;
}
