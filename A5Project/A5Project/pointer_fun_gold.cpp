#include "stdafx.h"

// sum_and_range(n, sum, smallest, largest) read n natural numbers
// store the sum of all n numbers, or 0 if n is 0.
// stores the smallest/largest of all numbers, or 0 if n is 0.
// returns false (0) to indicate success, true (1) otherwise.
// requires: n is int and sum, smallest, largest are pointers to int
// effects: changes the field values of *sum, *smallest, *largest
bool sum_and_range(int n, int *sum, int *smallest, int *largest)
{
	int i = 0;
	bool result = 0;
	while (i<n)
	{
		int input;
		scanf("%d", &input); // use readnat() in seashell
		if (input == -1)
		{
			result = 1;
			break;
		}
		(*sum) += input;
		if ((*smallest) > input)
			*smallest = input;
		if ((*largest) < input)
			*largest = input;
		++i;
	}
	return result;
}


//int _tmain(int argc, _TCHAR* argv[])
//{
//	int n = 5, sum = 0, smallest = 2147483647, largest = 0;
//
//	int rt = sum_and_range(n, &sum, &smallest, &largest);
//
//	printf("value of sum = %d\n", sum);
//	printf("value of smallest = %d\n", smallest);
//	printf("value of largest = %d\n", largest);
//	printf("value of sum_and_range = %d\n", rt);
//
//	getchar();
//	getchar();
//	return 0;
//}


// sum_numbers(*sum) reads natural numbers until a failure occurs. 
// mutates *sum with the sum of all the numbers that were successfully read
// requires: sum is pointers to int
// effects: changes the field values of *sum
int sum_numbers(int *sum)
{
	int input, i = 0;
	while (true)
	{
		scanf("%d", &input);  // use readnat() in seashell
		getchar();
		if (input == -1)
		{
			break;
		}
		else
		{
			(*sum) += input;
		}
		++i;
	}
	return i;
}


//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	int sum = 0;
//
//	int rt = sum_numbers(&sum);
//
//	printf("value of sum = %d\n", sum);
//	printf("value of sum_numbers = %d\n", rt);
//
//	getchar();
//	getchar();
//	return 0;
//}