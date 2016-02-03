#include "stdafx.h"

int max()
{
	int max = 0;
	int n = 0;
	while (true)
	{
		//n = readnat();
		scanf("%d", &n);
		if (-1 == n)
		{
			break;
		}
		else if (n>max)
		{
			max = n;
		}
	}
	return max;
}