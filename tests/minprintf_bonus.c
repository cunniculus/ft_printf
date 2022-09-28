#include <stdio.h>

int main (void)
{
	int r;

	printf("|%20.10d!\n", 10);
	r = printf("|%10.10d!\n", 10);
	printf("%d", r);
	r = printf("|%10.5s!\n", "Hello");
	printf("%d", r);
}

