#include "stdafx.h"

// read_two(n1, n2) read in two natural numbers and 
// stores the first number in *n1 and the second in *n2. 
// The return value must indicate how many numbers were successfully read(0, 1 or 2).
// requires: n1 n2 are pointers to int
// effects: changes the field values of n1 or n2
int read_two(int *n1, int *n2)
{
	int i =1; // use readnat() in seasheel
	if (i != -1)
	{
		*n1 = i;
		int j = 2; // use readnat() in seasheel
		if (j != -1)
		{
			*n2 = j;
			return 2;
		}
		return 1;
	}
	return 0;
}

//int _tmain(int argc, _TCHAR* argv[])
//{
//	int x = 2, y = 3;
//
//	int rt = read_two(&x, &y);
//
//	printf("value of x = %d\n", x);
//	printf("value of y = %d\n", y);
//	printf("value of read_two = %d\n", rt);
//
//
//	getchar();
//	return 0;
//}