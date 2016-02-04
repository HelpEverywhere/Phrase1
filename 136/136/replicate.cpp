#include "stdafx.h"

int isspace1(int c)
{
	if (' ' == c || '\t' == c || '\n' == c || '\v' == c || '\f' == c || '\r' == c)
		return 1;
	return 0;

}

void replicate()
{
	int input;

	while ((input = getchar()) != '0')
	{
		getchar();
		int i = input - '0', j =0;
		char c = getchar();
		getchar();
		if (isspace1(c))
			break;
		while (j < i)
		{
			printf("%c", c);
			++j;
		}
		printf("\n");
	}

}

