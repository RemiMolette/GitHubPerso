/*****************************************************************
*		Fichier :  	ELTCHAR.C
*		Format :	Source C 
*		Version  : 	14/10/13
*		Programmeurs :	TREMBLAIN
*		Contenu :      	Définition des primitives pour une réalisatioon
*				par des entiers du TDA ELEMENT.
*		
******************************************************************/



/* définition des primitives du type concret ELEMENT entier */

#include "eltprim.h"
#include <stdio.h>

void ElementLire(ELEMENT c)	{
	scanf("%s", c);
}

void ElementAfficher(ELEMENT elt)	{
	printf("%s ", elt);
}

ELEMENT ElementAffecter(ELEMENT * e1, ELEMENT e2)   {
	return (*e1 = e2);
}

bool ElementIdentique(ELEMENT e1, ELEMENT e2)  {
	/* retourne vrai si les deux arguments sont identiques */
	return (strcmp(e1, e2)) ;
}

/* INUTILE Mais cohérent pour le stockage indirect */
ELEMENT ElementCreer()	{
	return ELEMENT_VIDE;
}

void ElementDetruire(ELEMENT x) 	{
}

