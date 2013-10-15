/************  FICHIER  Testpile.C  **************/
/* programme de test, cours N °2, sur les piles
 */

#include "pileprim.h"
#include "lstprim.h"
#include "tradpile.h"

#include <sys/times.h> 	//Pour un rendu plus propre 
#include <stdio.h>
#include <string.h>

/* fonction pour l'utilisation de fgets */
void purger(void)
{
	int c;

	while((c = getchar()) != '\n' && c != EOF){}
}

void clean(char * chaine)
{
	char *p = strchr(chaine, '\n');

	if(p)
		*p = '\0';

	else
		purger();
}

int main()
{
	
	//*
	//system("clear");
	char * chaine;
	LISTE l = ListeCreer();

	printf("> ");
	fgets(chaine, sizeof(chaine)*1024, stdin);
	clean(chaine);
	
//	printf("%s ", chaine);
	l = Str2Lst(chaine);
//	l = Inf2Post(l);
	ListeAfficher(l);

	//printf("= %i\n", EvalPost(l));
	//*/
	return 0;
	
}

