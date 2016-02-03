#include "stdafx.h"
void manysums()
{
	int n, m;
	//n = readnat();
	//m = readnat();
	scanf("%d", &n);
	scanf("%d", &m);
	int i = 0;
	while (i < n)
	{
		int sum = 0;
		int j = 0;
		while (j < m)
		{
			int p;
			//o = readnat();
			scanf("%d", &p);
			sum += p;
			++j;
		}
		printf("%d\n", sum);
		++i;
	}
}