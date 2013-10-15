#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/times.h>

int main(int nb_arg, char **tab_arg)
{
	char trad;

	printf("Programme de traduction char2int\n> ");
	scanf("%c", &trad);
	
	printf("Résultat : %i\n", trad);
}

