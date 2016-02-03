#include "stdafx.h"

void lastdigit()
{
	char c='\0',b ='\0';
	while ((c = getchar()) != EOF)
	{
		if (c >= '0' && c <= '9')
			b = c;
	}
	printf("%c", b);
}


void lowercount()
{
	char c = '\0';
	int count = 0;
	while ((c = getchar()) != EOF)
	{
		if (c >= 'a' && c <= 'z')
			++count;
	}
	printf("%d", count);
}


void charcounterblack()
{
	char c;
	scanf("%c", &c);
	int n;
	scanf("%d", &n);
	if ('\n' == c || -1 == n)
	{
		printf("insufficient input\n");
	}
	else
	{
		int i = 0;
		char d;
		while (i < n)
		{
			scanf("%c", &d);
			if (d == c)
				++i;
		}
		printf("done\n");
	}
}