#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char * str;// = " 213 / 2345";// = (char *)malloc(sizeof(char)*1024);
	int i = 0;
	int test = 0;
	int total = 0;

	//printf("> ");
	//scanf("%s", str);

	 printf("> ");
	 fgets(str, sizeof(str)*1024, stdin);

	for(i=0; str[i] != '\0'; i++)
		printf("%c ", str[i]);

	for(i=0; str[i] != '\0'; i++)
	{
		if(!isdigit(str[i]) && str[i] != ' ')
		{
			if(total)
			{	
				printf("chiffre rentrée = %i\n", total);
			}

			printf("Symbole interprété : %c\n", str[i]);
			total = 0;
		}

		else if(isdigit(str[i]))
		{
			total = (total * 10) + (str[i] - 48);
			printf("%i ", total);
		}
	}

	return 0;
}
