/* Brutus v1.0 - lib for Caesar cipher [1].

[1] https://en.wikipedia.org/wiki/Caesar_cipher

Functions that take STR as argument will that string in place
according to optional CIPHER moving characters SHIFT number of times
to right if number is positive or to left if negative.  Using the same
SHIFT value on encoded string but with different sigh will naturally
decode STR message.  Functions that take single character C will
return encoded/decoded character according to the same rules.
*/

#ifndef BRUTUS_H
#define BRUTUS_H

char brutus_ascii_char(int shift, char c);
void brutus_ascii(int shift, char *str);
void brutus_rot13(char *str);
char brutus_char(char *cipher, int shift, char c);
void brutus_custom(char *cipher, int shift, char *str);

#endif /* BRUTUS_H */
