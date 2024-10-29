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
	char msg[] = "Why did the chicken cross the road?";

	brutus_ascii(13, msg);	/* Encode */
	SEQ(msg, "Jul qvq gur puvpxra pebff gur ebnq?");
	brutus_ascii(-13, msg);	/* Decode */
	SEQ(msg, "Why did the chicken cross the road?");

	brutus_ascii(1, msg);	/* Encode */
	SEQ(msg, "Xiz eje uif dijdlfo dsptt uif spbe?");
	brutus_ascii(-1, msg);	/* Encode */
	SEQ(msg, "Why did the chicken cross the road?");
}

TEST("rot13")
{
	char msg[] = "Why did the chicken cross the road?";

	brutus_rot13(msg);
	SEQ(msg, "Jul qvq gur puvpxra pebff gur ebnq?");
	brutus_rot13(msg);
	SEQ(msg, "Why did the chicken cross the road?");
}

TEST("char")
{
	OK(brutus_char("abc", 1, 'a') == 'b');
	OK(brutus_char("abc", 1, 'b') == 'c');
	OK(brutus_char("abc", 1, 'c') == 'a');
}

TEST("custom")
{
	char msg[] = "abcdefgh";

	brutus_custom("abc", 1, msg);	/* Encode */
	SEQ(msg, "bcadefgh");
	brutus_custom("abc", -1, msg);	/* Decode */
	SEQ(msg, "abcdefgh");

	brutus_custom("abc", 2, msg);	/* Encode */
	SEQ(msg, "cabdefgh");
	brutus_custom("abc", -2, msg);	/* Decode */
	SEQ(msg, "abcdefgh");
}
