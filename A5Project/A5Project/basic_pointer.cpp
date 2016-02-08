#include "stdafx.h"


// down_value(x, y) changes the larger value to be the same as the smaller value 
// and returns the address of the value that was mutated 
// If the values are the same, the function should make no change and return NULL.
// requires: x y are pointers to int
// effects: changes the field values of x or y
int *down_value(int *x, int *y)
{
	if ((*x) > (*y))
	{
		*x = *y;
		return x;
	}
	else if ((*y) > (*x))
	{
		*y = *x;
		return y;
	}
	else
		return NULL;
}

//int main(void){
//	int x = 2, y = 3;
//
//	int *pf = down_value(&x, &y);
//
//	printf("value of x = %d\n", x);
//	printf("value of y = %d\n", y);
//	printf("value of what function points at &x = %p\n", &x);
//	printf("value of what function points at &y = %p\n", &y);
//	printf("value of what function points at *pf = %p\n", pf);
//
//	getchar();
//	return 0;
//
//}
