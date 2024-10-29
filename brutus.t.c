#include "brutus.h"
#include "walter.h"

TEST("ascii")
{
	OK(brutus_ascii(0, 'a') == 'a');
	OK(brutus_ascii(1, 'a') == 'b');
	OK(brutus_ascii(2, 'a') == 'c');
	OK(brutus_ascii(1, 'z') == 'a');
	OK(brutus_ascii(2, 'z') == 'b');

	OK(brutus_ascii(0, 'A') == 'A');
	OK(brutus_ascii(1, 'A') == 'B');
	OK(brutus_ascii(2, 'A') == 'C');
	OK(brutus_ascii(1, 'Z') == 'A');
	OK(brutus_ascii(2, 'Z') == 'B');

	OK(brutus_ascii(1, ' ') == ' ');
	OK(brutus_ascii(2, '-') == '-');
	OK(brutus_ascii(1, '1') == '1');
	OK(brutus_ascii(2, '2') == '2');
}

TEST("rot13")
{
	SEQ(brutus_rot13("Why did the chicken cross the road?"), "Jul qvq gur puvpxra pebff gur ebnq?");
	SEQ(brutus_rot13("Gb trg gb gur bgure fvqr!"), "To get to the other side!");
}
