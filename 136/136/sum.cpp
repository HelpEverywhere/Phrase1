#include "stdafx.h"

int sum()
{
	int sum = 0;
	int n = 0;
	while (true)
	{
		//n = readnat();
		scanf("%d", &n);
		if (-1 == n)
		{
			break;
		}
		sum += n;
	}
	return sum;
}