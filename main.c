#define VERSION "v1.0"
#define NAME	"Brutus"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <err.h>
#include "brutus.h"

static void
usage(void)
{
	printf("usage: "NAME" [options] <stdin\n"
	       "\n"
	       "options:\n"
	       "	-s num	Shift size, default is 13\n"
	       "	-v	Print program version.\n"
	       "	-h	Print this help message.\n"
	       "\n"
		"stdin:\n"
	       "	Text to encode comes from standard input.\n");
}

int
main(int argc, char **argv)
{
	int opt, shift=13;
	char buf[BRUTUS_BUFSIZ];
	while ((opt = getopt(argc, argv, "s:vh")) != -1) {
		switch (opt) {
		case 's':
			if (!(shift = atoi(optarg))) {
				errx(1, "Shift has to be a number bigger than 0");
			}
			break;
		case 'v':
			puts(VERSION);
			return 0;
		case 'h':
			usage();
			return 0;
		default:
			usage();
			return 1;
		}
	}
	while (fgets(buf, sizeof(buf), stdin)) {
		fputs(brutus_ascii(shift, buf), stdout);
	}
	return 0;
}
