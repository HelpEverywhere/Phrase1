#include "stdafx.h"
int abs(int n){
	if (n >= 0)
		return n;
	return -n;
}

void closest()
{
	int n;
	//n = readnat();
	scanf("%d", &n);
	if (0 == n)
	{
		printf("%d", n);
	}
	else
	{
		while (true)
		{
			int m, x = -1, i = 0;
			//m = readnat();
			scanf("%d", &m);
			if (0 == m)
			{
				break;
			}
			else
			{
				while (i < m)
				{
					int p;
					//p = readnat();
					scanf("%d", &p);
					if (-1 == x || abs(p - n) < abs(x - n))
						x = p;
					++i;
				}
				printf("%d\n",x);
			}
		}
	}

}