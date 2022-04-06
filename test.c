#include <stdio.h>

int		make_line(int BUFFER_SIZE, int cnt, int start, int nl, int size)
{
	size_t	ret;

	ret = 0;
	if (cnt >= 2)
		ret += (cnt - 1) * BUFFER_SIZE;
	ret -= start + 1;
	if (nl != -1)
		ret += nl + 1;
	else
		ret += size + 1;
	//if ((cnt == 1 && (size - 1 == start)) ||
	//	(BUFFER_SIZE == 1 && cnt == 2 && start == 0 && size == 0))
	//	ret -= 1;
	return (ret);
}
int	testcase;
int total;
// only test make_line func, make right whole size of line
void	test(int BUFFER_SIZE, int cnt, int start, int nl, int size, int expect)
{
	int	ret;

	ret = make_line(BUFFER_SIZE, cnt, start, nl, size);
	if  (ret != expect)
	{
		printf("FAIL at testcase: %d\tBUF: %d,\tcnt: %d,\tstart: %d,\tnl: %d,\tsize: %d\n",
				testcase, BUFFER_SIZE, cnt, start, nl, size);
		printf("\t\t\tret: %d,\texpect: %d,\tsub: %d\n", ret, expect, expect - ret);
		total++;
	}
	//#include <malloc/malloc.h>
	//malloc_size(a);
}

int	main(void)
{
////////     BUFF 8, cnt 1      ////////
////////        new line        ////////
////////      testcase = 0      ////////
	test(8, 1, -1, 0, 8, 1);
	//   B, c, st, n, s, e
	// |\n1234567|
	//  0 1234567
	test(8, 1, -1, 3, 8, 4);
	//   B, c, st, n, s, e
	// |123\n5678|
	//  0123 4567
	test(8, 1, -1, 7, 8, 8);
	//   B, c, st, n, s, e
	// |1234567\n|
	//  01234567
////////     BUFF 8, cnt 1      ////////
////////          EOF           ////////
////////      testcase = 1      ////////
	testcase++;
	test(8, 1, -1, -1, 0, 0);
	//   B, c, st,  n, s, e
	// |0       |
	//  01234567
	test(8, 1, -1, -1, 3, 4);
	//   B, c, st,  n, s, e
	// |1230    |
	//  01234567
	test(8, 1, -1, -1, 7, 8);
	//   B, c, st,  n, s, e
	// |12345670|
	//  01234567
////////     BUFF 8, cnt 1      ////////
////////     new line + EOF     ////////
////////      testcase = 2      ////////
	testcase++;
	test(8, 1, -1, 0, 1, 1);
	//   B, c, st, n, s, e
	// |\n0      |
	//  0 1234567
	test(8, 1, -1, 0, 3, 1);
	//   B, c, st, n, s, e
	// |\n120    |
	//  0 1234567
	test(8, 1, -1, 0, 7, 1);
	//   B, c, st, n, s, e
	// |\n1234560|
	//  0 1234567
	test(8, 1, -1, 2, 3, 3);
	//   B, c, st, n, s, e
	// |12\n0    |
	//  012 34567
	test(8, 1, -1, 2, 5, 3);
	//   B, c, st, n, s, e
	// |12\n340  |
	//  012 34567
	test(8, 1, -1, 2, 7, 3);
	//   B, c, st, n, s, e
	// |12\n34560|
	//  012 34567
	test(8, 1, -1, 6, 7, 7);
	//   B, c, st, n, s, e
	// |123456\n0|
	//  0123456 7
////////     BUFF 8, cnt 1      ////////
////////    start + new line    ////////
////////      testcase = 3      ////////
	testcase++;
	test(8, 1, 1, 2, 8, 1);
	//   B, c, st,n, s, e
	// |~~\n12345|
	//  012 34567
	test(8, 1, 1, 5, 8, 4);
	//   B, c, st,n, s, e
	// |~~123\n45|
	//  012345 67
	test(8, 1, 1, 7, 8, 6);
	//   B, c, st,n, s, e
	// |~~12345\n|
	//  01234567
////////     BUFF 8, cnt 1      ////////
////////      start + EOF       ////////
////////      testcase = 4      ////////
	testcase++;
	test(8, 1, 1, -1, 2, 0);
	//   B, c, st, n, s, e
	// |~~0     |
	//  01234567
	test(8, 1, 1, -1, 5, 4);
	//   B, c, st, n, s, e
	// |~~1230  |
	//  01234567
	test(8, 1, 1, 7, 7, 6);
	//   B, c, st,n, s, e
	// |~~123450|
	//  01234567
////////     BUFF 8, cnt 1      ////////
//////// start + new line + EOF ////////
////////      testcase = 5      ////////
	testcase++;
	test(8, 1, 1, 2, 3, 1);
	//   B, c, st,n, s, e
	// |~~\n0    |
	//  012 34567
	test(8, 1, 1, 2, 5, 1);
	//   B, c, st,n, s, e
	// |~~\n120  |
	//  012 34567
	test(8, 1, 1, 2, 7, 1);
	//   B, c, st,n, s, e
	// |~~\n12340|
	//  012 34567
	test(8, 1, 1, 4, 5, 3);
	//   B, c, st,n, s, e
	// |~~12\n0  |
	//  01234 567
	test(8, 1, 1, 4, 6, 3);
	//   B, c, st,n, s, e
	// |~~12\n30 |
	//  01234 567
	test(8, 1, 1, 4, 7, 3);
	//   B, c, st,n, s, e
	// |~~12\n340|
	//  01234 567
	test(8, 1, 1, 6, 7, 5);
	//   B, c, st,n, s, e
	// |~~1234\n0|
	//  0123456 7
////////     BUFF 8, cnt 2      ////////
////////        new line        ////////
////////      testcase = 6      ////////
	testcase++;
	test(8, 2, -1, 0, 8, 9);
	//   B, c, st, n, s, e
	// |12345678|->|\n1234567|
	//  01234567    0 1234567
	test(8, 2, -1, 3, 8, 12);
	//   B, c, st, n, s, e
	// |12345678|->|123\n5678|
	//  01234567    0123 4567
	test(8, 2, -1, 7, 8, 16);
	//   B, c, st, n, s, e
	// |12345678|->|1234567\n|
	//  01234567    01234567
////////     BUFF 8, cnt 2      ////////
////////          EOF           ////////
////////      testcase = 7      ////////
	testcase++;
	test(8, 2, -1, -1, 0, 9);
	//   B, c, st,  n, s, e
	// |12345678|->|0       |
	//  01234567    01234567
	test(8, 2, -1, -1, 3, 12);
	//   B, c, st,  n, s, e
	// |12345678|->|1230    |
	//  01234567    01234567
	test(8, 2, -1, -1, 7, 16);
	//   B, c, st,  n, s, e
	// |12345678|->|12345670|
	//  01234567    01234567
////////     BUFF 8, cnt 2      ////////
////////     new line + EOF     ////////
////////      testcase = 8      ////////
	testcase++;
	test(8, 2, -1, 0, 1, 9);
	//   B, c, st, n, s, e
	// |12345678|->|\n0      |
	//  01234567    0 1234567
	test(8, 2, -1, 0, 3, 9);
	//   B, c, st, n, s, e
	// |12345678|->|\n120    |
	//  01234567    0 1234567
	test(8, 2, -1, 0, 7, 9);
	//   B, c, st, n, s, e
	// |12345678|->|\n1234560|
	//  01234567    0 1234567
	test(8, 2, -1, 2, 3, 11);
	//   B, c, st, n, s, e
	// |12345678|->|12\n0    |
	//  01234567    012 34567
	test(8, 2, -1, 2, 5, 11);
	//   B, c, st, n, s, e
	// |12345678|->|12\n340  |
	//  01234567    012 34567
	test(8, 2, -1, 2, 7, 11);
	//   B, c, st, n, s, e
	// |12345678|->|12\n34560|
	//  01234567    012 34567
	test(8, 2, -1, 6, 7, 15);
	//   B, c, st, n, s, e
	// |12345678|->|123456\n0|
	//  01234567    0123456 7
////////     BUFF 8, cnt 2      ////////
////////    start + new line    ////////
////////      testcase = 9      ////////
	testcase++;
	test(8, 2, 1, 0, 8, 7);
	//   B, c, st,n, s, e
	// |~~123456|->|\n1234567|
	//  01234567    0 1234567
	test(8, 2, 1, 3, 8, 10);
	//   B, c, st,n, s, e
	// |~~123456|->|123\n5678|
	//  01234567    0123 4567
	test(8, 2, 1, 7, 8, 14);
	//   B, c, st,n, s, e
	// |~~123456|->|1234567\n|
	//  01234567    01234567
////////     BUFF 8, cnt 2      ////////
////////      start + EOF       ////////
////////      testcase = 10     ////////
	testcase++;
	test(8, 2, 1, -1, 0, 7);
	//   B, c, st,n, s, e
	// |~~123456|->|0       |
	//  01234567    01234567
	test(8, 2, 1, -1, 3, 10);
	//   B, c, st,n, s, e
	// |~~123456|->|1230    |
	//  01234567    01234567
	test(8, 2, 1, -1, 7, 14);
	//   B, c, st,n, s, e
	// |~~123456|->|12345670|
	//  01234567    01234567
////////     BUFF 8, cnt 2      ////////
//////// start + new line + EOF ////////
////////      testcase = 11     ////////
	testcase++;
	test(8, 2, 1, 0, 1, 7);
	//   B, c, st,n, s, e
	// |~~123456|->|\n0      |
	//  01234567    0 1234567
	test(8, 2, 1, 0, 3, 7);
	//   B, c, st,n, s, e
	// |~~123456|->|\n120    |
	//  01234567    0 1234567
	test(8, 2, 1, 0, 7, 7);
	//   B, c, st,n, s, e
	// |~~123456|->|\n1234560|
	//  01234567    0 1234567
	test(8, 2, 1, 2, 3, 9);
	//   B, c, st,n, s, e
	// |~~123456|->|12\n0    |
	//  01234567    012 34567
	test(8, 2, 1, 2, 5, 9);
	//   B, c, st,n, s, e
	// |~~123456|->|12\n340  |
	//  01234567    012 34567
	test(8, 2, 1, 2, 7, 9);
	//   B, c, st,n, s, e
	// |~~123456|->|12\n34560|
	//  01234567    012 34567
	test(8, 2, 1, 6, 7, 13);
	//   B, c, st,n, s, e
	// |~~123456|->|123456\n0|
	//  01234567    0123456 7
////////     BUFF 8, cnt 3      ////////
////////        new line        ////////
////////      testcase = 12     ////////
	testcase++;
	test(8, 3, -1, 0, 8, 17);
	//   B, c, st, n, s, e
	// |12345678|->|12345678|->|\n1234567|
	//  01234567    01234567    0 1234567
	test(8, 3, -1, 3, 8, 20);
	//   B, c, st, n, s, e
	// |12345678|->|12345678|->|123\n5678|
	//  01234567    01234567    0123 4567
	test(8, 3, -1, 7, 8, 24);
	//   B, c, st, n, s, e
	// |12345678|->|12345678|->|1234567\n|
	//  01234567    01234567    01234567
////////     BUFF 8, cnt 3      ////////
////////          EOF           ////////
////////      testcase = 13     ////////
	testcase++;
	test(8, 3, -1, -1, 0, 17);
	//   B, c, st,  n, s, e
	// |12345678|->|12345678|->|0       |
	//  01234567    01234567    01234567
	test(8, 3, -1, -1, 3, 20);
	//   B, c, st,  n, s, e
	// |12345678|->|12345678|->|1230    |
	//  01234567    01234567    01234567
	test(8, 3, -1, -1, 7, 24);
	//   B, c, st,  n, s, e
	// |12345678|->|12345678|->|12345670|
	//  01234567    01234567    01234567
////////     BUFF 8, cnt 3      ////////
////////      start + EOF       ////////
////////      testcase = 14     ////////
	testcase++;
	test(8, 3, -1, 0, 1, 17);
	//   B, c, st, n, s, e
	// |12345678|->|12345678|->|\n0      |
	//  01234567    01234567    0 1234567
	test(8, 3, -1, 0, 3, 17);
	//   B, c, st, n, s, e
	// |12345678|->|12345678|->|\n120    |
	//  01234567    01234567    0 1234567
	test(8, 3, -1, 0, 7, 17);
	//   B, c, st, n, s, e
	// |12345678|->|12345678|->|\n1234560|
	//  01234567   01234567     0 1234567
	test(8, 3, -1, 2, 3, 19);
	//   B, c, st, n, s, e
	// |12345678|->|12345678|->|12\n0    |
	//  01234567    01234567    012 34567
	test(8, 3, -1, 2, 5, 19);
	//   B, c, st, n, s, e
	// |12345678|->|12345678|->|12\n340  |
	//  01234567    01234567    012 34567
	test(8, 3, -1, 2, 7, 19);
	//   B, c, st, n, s, e
	// |12345678|->|12345678|->|12\n34560|
	//  01234567    01234567    012 34567
	test(8, 3, -1, 6, 7, 23);
	//   B, c, st, n, s, e
	// |12345678|->|12345678|->|123456\n0|
	//  01234567    01234567    0123456 7
////////     BUFF 8, cnt 3      ////////
////////    start + new line    ////////
////////      testcase = 15     ////////
	testcase++;
	test(8, 3, 1, 0, 8, 15);
	//   B, c, st,n, s, e
	// |~~123456|->|12345678|->|\n1234567|
	//  01234567    01234567    0 1234567
	test(8, 3, 1, 3, 8, 18);
	//   B, c, st,n, s, e
	// |~~123456|->|12345678|->|123\n5678|
	//  01234567    01234567    0123 4567
	test(8, 3, 1, 7, 8, 22);
	//   B, c, st,n, s, e
	// |~~123456|->|12345678|->|1234567\n|
	//  01234567    01234567    01234567
////////     BUFF 8, cnt 3      ////////
////////      start + EOF       ////////
////////      testcase = 16     ////////
	testcase++;
	test(8, 3, 1, -1, 0, 15);
	//   B, c, st,n, s, e
	// |~~123456|->|12345678|->|0       |
	//  01234567    01234567    01234567
	test(8, 3, 1, -1, 3, 18);
	//   B, c, st,n, s, e
	// |~~123456|->|12345678|->|1230    |
	//  01234567    01234567    01234567
	test(8, 3, 1, -1, 7, 22);
	//   B, c, st,n, s, e
	// |~~123456|->|12345678|->|12345670|
	//  01234567    01234567    01234567
////////     BUFF 8, cnt 3      ////////
//////// start + new line + EOF ////////
////////      testcase = 17     ////////
	testcase++;
	test(8, 3, 1, 0, 1, 15);
	//   B, c, st,n, s, e
	// |~~123456|->|12345678|->|\n0      |
	//  01234567    01234567    0 1234567
	test(8, 3, 1, 0, 3, 15);
	//   B, c, st,n, s, e
	// |~~123456|->|12345678|->|\n120    |
	//  01234567    01234567    0 1234567
	test(8, 3, 1, 0, 7, 15);
	//   B, c, st,n, s, e
	// |~~123456|->|12345678|->|\n1234560|
	//  01234567   01234567     0 1234567
	test(8, 3, 1, 2, 3, 17);
	//   B, c, st,n, s, e
	// |~~123456|->|12345678|->|12\n0    |
	//  01234567    01234567    012 34567
	test(8, 3, 1, 2, 5, 17);
	//   B, c, st,n, s, e
	// |~~123456|->|12345678|->|12\n340  |
	//  01234567    01234567    012 34567
	test(8, 3, 1, 2, 7, 17);
	//   B, c, st,n, s, e
	// |~~123456|->|12345678|->|12\n34560|
	//  01234567    01234567    012 34567
	test(8, 3, 1, 6, 7, 21);
	//   B, c, st,n, s, e
	// |~~123456|->|12345678|->|123456\n0|
	//  01234567    01234567    0123456 7
////////     BUFF 1, cnt 1      ////////
////////        new line        ////////
////////      testcase = 18     ////////
	testcase++;
	test(1, 1, -1, 0, 1, 1);
	//   B, c, st, n, s, e
	// |\n|
	//  0
////////     BUFF 1, cnt 1      ////////
////////          EOF           ////////
////////      testcase = 19     ////////
	testcase++;
	test(1, 1, -1, -1, 0, 0);
	//   B, c, st,  n, s, e
	// |0|
	//  0
////////     BUFF 1, cnt 2      ////////
////////        new line        ////////
////////      testcase = 20     ////////
	testcase++;
	test(1, 2, -1, 0, 1, 2);
	//   B, c, st, n, s, e
	// |1|->|\n|
	//  0    0
////////     BUFF 1, cnt 2      ////////
////////          EOF           ////////
////////      testcase = 21     ////////
	testcase++;
	test(1, 2, -1, -1, 0, 2);
	//   B, c, st,  n, s, e
	// |1|->|0|
	//  0    0
////////     BUFF 1, cnt 2      ////////
////////    start + new line    ////////
////////      testcase = 22     ////////
	testcase++;
	test(1, 2, 0, 0, 1, 1);
	//   B, c, st,n, s, e
	// |~|->|\n|
	//  0    0
////////     BUFF 1, cnt 2      ////////
////////      start + EOF       ////////
////////      testcase = 23     ////////
	testcase++;
	test(1, 2, 0, -1, 0, 0);
	//   B, c, st, n, s, e
	// |~|->|0|
	//  0    0
////////     BUFF 1, cnt 3      ////////
////////        new line        ////////
////////      testcase = 24     ////////
	testcase++;
	test(1, 3, -1, 0, 1, 3);
	//   B, c, st, n, s, e
	// |1|->|2|->|\n|
	//  0    0    0
////////     BUFF 1, cnt 3      ////////
////////          EOF           ////////
////////      testcase = 25     ////////
	testcase++;
	test(1, 3, -1, -1, 0, 3);
	//   B, c, st,  n, s, e
	// |1|->|2|->|0|
	//  0    0    0
////////     BUFF 1, cnt 3      ////////
////////    start + new line    ////////
////////      testcase = 26     ////////
	testcase++;
	test(1, 3, 0, 0, 1, 2);
	//   B, c, st,n, s, e
	// |~|->|1|->|\n|
	//  0    0    0
////////     BUFF 1, cnt 3      ////////
////////      start + EOF       ////////
////////      testcase = 27     ////////
	testcase++;
	test(1, 3, 0, -1, 0, 2);
	//   B, c, st, n, s, e
	// |~|->|1|->|0|
	//  0    0    0
////////     BUFF 2, cnt 1      ////////
////////        new line        ////////
////////      testcase = 28     ////////
	testcase++;
	test(2, 1, -1, 0, 2, 1);
	//   B, c, st, n, s, e
	// |\n1|
	//  0 1
	test(2, 1, -1, 1, 2, 2);
	//   B, c, st, n, s, e
	// |1\n|
	//  01
////////     BUFF 2, cnt 1      ////////
////////          EOF           ////////
////////      testcase = 29     ////////
	testcase++;
	test(2, 1, -1, -1, 0, 0);
	//   B, c, st,  n, s, e
	// |0 |
	//  01
	test(2, 1, -1, -1, 1, 2);
	//   B, c, st,  n, s, e
	// |10|
	//  01
////////     BUFF 2, cnt 1      ////////
////////     new line + EOF     ////////
////////      testcase = 30     ////////
	testcase++;
	test(2, 1, -1, 0, 1, 1);
	//   B, c, st, n, s, e
	// |\n0|
	//  0 1
////////     BUFF 2, cnt 1      ////////
////////    start + new line    ////////
////////      testcase = 31     ////////
	testcase++;
	test(2, 1, 0, 1, 2, 1);
	//   B, c, st,n, s, e
	// |~\n|
	//  01
////////     BUFF 2, cnt 1      ////////
////////      start + EOF       ////////
////////      testcase = 32     ////////
	testcase++;
	test(2, 1, 0, -1, 1, 0);
	//   B, c, st, n, s, e
	// |~0|
	//  01
////////     BUFF 2, cnt 2      ////////
////////        new line        ////////
////////      testcase = 33     ////////
	testcase++;
	test(2, 2, -1, 0, 2, 3);
	//   B, c, st, n, s, e
	// |12|->|\n3|
	//  01    0 1
	test(2, 2, -1, 1, 2, 4);
	//   B, c, st, n, s, e
	// |12|->|3\n|
	//  01    01
////////     BUFF 2, cnt 2      ////////
////////          EOF           ////////
////////      testcase = 34     ////////
	testcase++;
	test(2, 2, -1, -1, 0, 3);
	//   B, c, st,  n, s, e
	// |12|->|0 |
	//  01    01
	test(2, 2, -1, -1, 1, 4);
	//   B, c, st,  n, s, e
	// |12|->|30|
	//  01    01
////////     BUFF 2, cnt 2      ////////
////////     new line + EOF     ////////
////////      testcase = 35     ////////
	testcase++;
	test(2, 2, -1, 0, 1, 3);
	//   B, c, st, n, s, e
	// |12|->|\n0|
	//  01    0 1
////////     BUFF 2, cnt 2      ////////
////////    start + new line    ////////
////////      testcase = 36     ////////
	testcase++;
	test(2, 2, 0, 0, 2, 2);
	//   B, c, st,n, s, e
	// |~1|->|\n2|
	//  01    0 1
	test(2, 2, 0, 1, 2, 3);
	//   B, c, st,n, s, e
	// |~1|->|2\n|
	//  01    01
////////     BUFF 2, cnt 2      ////////
////////      start + EOF       ////////
////////      testcase = 37     ////////
	testcase++;
	test(2, 2, 0, -1, 0, 2);
	//   B, c, st, n, s, e
	// |~1|->|0 |
	//  01    01
	test(2, 2, 0, -1, 1, 3);
	//   B, c, st, n, s, e
	// |~1|->|20|
	//  01    01
////////     BUFF 2, cnt 2      ////////
//////// start + new line + EOF ////////
////////      testcase = 38     ////////
	testcase++;
	test(2, 2, 0, 0, 1, 2);
	//   B, c, st,n, s, e
	// |~1|->|\n0|
	//  01    0 1
////////     BUFF 2, cnt 3      ////////
////////        new line        ////////
////////      testcase = 39     ////////
	testcase++;
	test(2, 3, -1, 0, 2, 5);
	//   B, c, st, n, s, e
	// |12|->|34|->|\n5|
	//  01    01    0 1
	test(2, 3, -1, 1, 2, 6);
	//   B, c, st, n, s, e
	// |12|->|34|->|5\n|
	//  01    01    01
////////     BUFF 2, cnt 3      ////////
////////          EOF           ////////
////////      testcase = 40     ////////
	testcase++;
	test(2, 3, -1, -1, 0, 5);
	//   B, c, st,  n, s, e
	// |12|->|34|->|0 |
	//  01    01    0
	test(2, 3, -1, -1, 1, 6);
	//   B, c, st,  n, s, e
	// |12|->|34|->|50|
	//  01    01    01
////////     BUFF 2, cnt 3      ////////
////////     new line + EOF     ////////
////////      testcase = 41     ////////
	testcase++;
	test(2, 3, -1, 0, 1, 5);
	//   B, c, st, n, s, e
	// |12|->|34|->|\n0|
	//  01    01    0 1
////////     BUFF 2, cnt 3      ////////
////////    start + new line    ////////
////////      testcase = 42     ////////
	testcase++;
	test(2, 3, 0, 0, 2, 4);
	//   B, c, st,n, s, e
	// |~1|->|23|->|\n4|
	//  01    01    0 1
	test(2, 3, 0, 1, 2, 5);
	//   B, c, st,n, s, e
	// |~1|->|23|->|4\n|
	//  01    01    01
////////     BUFF 2, cnt 3      ////////
////////      start + EOF       ////////
////////      testcase = 43     ////////
	testcase++;
	test(2, 3, 0, -1, 0, 4);
	//   B, c, st, n, s, e
	// |~1|->|23|->|0 |
	//  01    01    01
	test(2, 3, 0, -1, 1, 5);
	//   B, c, st, n, s, e
	// |~1|->|23|->|40|
	//  01    01    01
////////     BUFF 2, cnt 3      ////////
//////// start + new line + EOF ////////
////////      testcase = 44     ////////
	testcase++;
	test(2, 3, 0, 0, 1, 4);
	//   B, c, st,n, s, e
	// |~1|->|23|->|\n0|
	//  01    01    0 1

	printf("total :%d\n", total);
	return (0);
}