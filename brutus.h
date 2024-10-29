#ifndef BRUTUS_H
#define BRUTUS_H

#define BRUTUS_BUFSIZ	4096	/* Size of internal buffers */

char brutus_ascii_char(int shift, char c);
char *brutus_ascii(int shift, char *str);
char *brutus_rot13(char *str);

#endif /* BRUTUS_H */
