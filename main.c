#include <stdio.h>
#include "brutus.h"

int
main(int argc, char **argv)
{
	char buf[4096];
	while (fgets(buf, sizeof(buf), stdin)) {
		fputs(brutus_rot13(buf), stdout);
	}
	return 0;
}
