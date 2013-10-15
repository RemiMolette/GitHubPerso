#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;

	printf("> ");
	scanf("%i", &i);
	char c = (char)i;

	printf("# %c\n", c);
}
