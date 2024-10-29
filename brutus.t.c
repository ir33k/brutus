#include "brutus.h"
#include "walter.h"

TEST("ascii_char")
{
	OK(brutus_ascii_char(0, 'a') == 'a');
	OK(brutus_ascii_char(1, 'a') == 'b');
	OK(brutus_ascii_char(2, 'a') == 'c');
	OK(brutus_ascii_char(1, 'z') == 'a');
	OK(brutus_ascii_char(2, 'z') == 'b');

	OK(brutus_ascii_char(0, 'A') == 'A');
	OK(brutus_ascii_char(1, 'A') == 'B');
	OK(brutus_ascii_char(2, 'A') == 'C');
	OK(brutus_ascii_char(1, 'Z') == 'A');
	OK(brutus_ascii_char(2, 'Z') == 'B');

	OK(brutus_ascii_char(1, ' ') == ' ');
	OK(brutus_ascii_char(2, '-') == '-');
	OK(brutus_ascii_char(1, '1') == '1');
	OK(brutus_ascii_char(2, '2') == '2');
}

TEST("ascii")
{
	/* Encode */
	SEQ(brutus_ascii(13, "Why did the chicken cross the road?"), "Jul qvq gur puvpxra pebff gur ebnq?");
	SEQ(brutus_ascii(1, "Why did the chicken cross the road?"), "Xiz eje uif dijdlfo dsptt uif spbe?");

	/* Decode */
	SEQ(brutus_ascii(-13, "Jul qvq gur puvpxra pebff gur ebnq?"), "Why did the chicken cross the road?");
	SEQ(brutus_ascii(-1, "Xiz eje uif dijdlfo dsptt uif spbe?"), "Why did the chicken cross the road?");
}

TEST("rot13")
{
	SEQ(brutus_rot13("Why did the chicken cross the road?"), "Jul qvq gur puvpxra pebff gur ebnq?");
	SEQ(brutus_rot13("Gb trg gb gur bgure fvqr!"), "To get to the other side!");
	SEQ(brutus_rot13("0123456789 -_=+!?<>{}[];'"), "0123456789 -_=+!?<>{}[];'");
}

TEST("char")
{
	OK(brutus_char("abc", 1, 'a') == 'b');
	OK(brutus_char("abc", 1, 'b') == 'c');
	OK(brutus_char("abc", 1, 'c') == 'a');
}

TEST("custom")
{
	/* Encode */
	SEQ(brutus_custom("abc", 1, "abcdefgh"), "bcadefgh");
	SEQ(brutus_custom("abc", 2, "abcdefgh"), "cabdefgh");

	/* Decode */
	SEQ(brutus_custom("abc", -1, "bcadefgh"), "abcdefgh");
	SEQ(brutus_custom("abc", -2, "cabdefgh"), "abcdefgh");
}
