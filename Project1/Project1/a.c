#pragma warning(disable:4996)
#include <stdio.h>

char c1 = 'b';

int main()
{
	switch (c1)
	{
	case 'a':
		printf("a\n");
		break;
	case 'b':
		printf("b\n");
		break;
	case 'c':
		printf("c\n");
		break;
	default:
		printf("default\n");
		break;
	}
}