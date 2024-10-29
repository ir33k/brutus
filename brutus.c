#include "brutus.h"

#define ASCII_RANGE	('z' - 'a' + 1)

static int
mod(int a, int b)
{
	return (a % b + b) % b;
}

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
		return mod((c + shift - 'a'), ASCII_RANGE) + 'a';
	}
	if (c >= 'A' && c <= 'Z') {
		return mod((c + shift - 'A'), ASCII_RANGE) + 'A';
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
brutus_char(char *cipher, int shift, char c)
{
	int i;
	i = str_index_of(cipher, c);
	if (i == -1) {
		return c;
	}
	i = mod((i + shift), str_length(cipher));
	return cipher[i];
}

char *
brutus_custom(char *cipher, int shift, char *str)
{
	static char buf[BRUTUS_BUFSIZ];
	int i;
	buf[0] = 0;
	for (i=0; str[i]; i++) {
		buf[i] = brutus_char(cipher, shift, str[i]);
	}
	buf[i] = 0;
	return buf;
}
