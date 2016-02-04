#include "stdafx.h"

int isspace(int c)
{
	if (' ' == c || '\t' == c || '\n' == c || '\v' == c || '\f' == c || '\r' == c)
		return 1;
	return 0;

}

int toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c + 'A' - 'a';
	}
	return c;

}


void telegram()
{
	int input, lastinput = -1;
	FILE *fPtr;
	fPtr = fopen("C:\\Users\\mmz\\Documents\\Visual Studio 2013\\Projects\\Phrase1\\136\\136\\Debug\\input.txt", "r");

	while ((input = fgetc(fPtr)) != EOF)
		//while ((input = getchar()) != EOF)
	{
		if (input >= 'a' && input <= 'z')
		{
			printf("%c", toupper(input));
		}
		if (input >= '0' && input <= '9' || isspace(input) || (input >= 'A' && input <= 'Z'))
		{
			printf("%c", input);
		}
		if (input == '%')
		{
			if (lastinput == -1 || isspace(lastinput))
				printf("PERCENT");
			else
				printf(" PERCENT");
		}
		if (input == '.')
		{
			if (lastinput == -1 || isspace(lastinput))
				printf("STOP");
			else
				printf(" STOP");
		}
		lastinput = input;
	}
	if (lastinput != '\n')
		printf("\n");
	printf("MESSAGE ENDS\n");
	fclose(fPtr);
}
