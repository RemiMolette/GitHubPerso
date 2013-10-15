/*****************************************************************
*		Fichier :  	tradpile.c
*		Format :	Source C 
*		Version  : 	07/10/13
*		Programmeurs :	Tremblain	
*		Contenu :      	Algorithme de traduction infixée vers postfixé
*		
******************************************************************/


#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pileprim.h"
#include "eltprim.h"
#include "lstprim.h"


/* Fonction de comparaison pour faciliter le traitement futur */

bool Nombre(ELEMENT elt)
{
	return(isdigit(*elt)? VRAI:FAUX);
}

bool Operateur(ELEMENT elt)
{
	if(strcmp(elt, "/") || strcmp(elt, "*") || strcmp(elt, "-") || strcmp(elt, "+"))
		return(VRAI);

	else
		return(FAUX);
}

bool Ouvrante(ELEMENT elt)
{
	return(strcmp(elt, "(")? VRAI:FAUX);
}

bool Fermante(ELEMENT elt)
{
	return(strcmp(elt, ")")? VRAI:FAUX);
}

bool Prioritaire(ELEMENT elt1, ELEMENT elt2)
{
	if(strcmp(elt1, elt2))
		return(VRAI);

	else if(strcmp(elt1, "*") || strcmp(elt1, "/"))
	{
		if(strcmp(elt2, "+") || strcmp(elt2, "-"))
			return(VRAI);
	}

	else
		return(FAUX);
}

ELEMENT Appliquer(ELEMENT x, ELEMENT xg, ELEMENT xd)
{
	/*switch(x)
    {

    }/*/
}

LISTE Str2Lst(char * str)
{
	LISTE l = ListeCreer();
	POSITION p = ListeSentinelle(l);
     int i;
     int total = 0;
     char buffer[256] = "";
     char *tmp;

     for(i=0; str[i] != '\0'; i++)
     {
     	if(!isdigit(str[i]) && str[i] != ' ')
     	{
     		if(total)
     		{
     			sprintf(buffer, "%d", total);
     			tmp = (char*)malloc(sizeof(char)*(strlen(buffer)+1));
     			strcpy(tmp, buffer);	
     			ListeInserer(tmp , p, l);
     			buffer[0] = '\0';
     			p = ListeSentinelle(l);
     			total = 0;
            }
     		ListeInserer(&str[i], p, l);
     		p = ListeSentinelle(l);
     	}
     	else if(isdigit(str[i]))
     	{
     		total = (total*10) + (str[i] - 48);		//Merci NXC -- -48 pour le passage de char vers int (table ASCII)
     	}
         
    }

     return(l);
}

/* On prend une pile de 20 de profondeur de base */
LISTE Inf2Post(LISTE l)
{
	LISTE lp = ListeCreer();
	PILE p = PileCreer(20);

	POSITION debut = ListePremier(l);
	POSITION fin = ListeSentinelle(l);
	POSITION courant = ListePremier(l);	//Element mobile

	ELEMENT elt = ListeAcceder(courant, l); 

	for(; debut != fin; courant = courant->suivant)
	{
		if(Ouvrante(elt))
		{
			if(!PileEmpiler(elt, p))
				printf("Plus de place\n");
		}
		
		else if(Nombre(elt))
			ListeInserer(elt, courant, lp);			//ListeInserer(elt, ListeSentinelle(lp), lp);
			
		else if(Operateur(elt))
		{	
			while(!PileVide(p) && !Prioritaire(PileSommet(p), elt))
			{
				if(!ListeInserer(PileDepiler(p), courant, lp))
					printf("Plus de place\n");
			}
			if(!PileEmpiler(elt, p))
				printf("Plus de place\n");	
		}

		else if(Fermante(elt))
		{
			while(!Ouvrante(PileSommet(p)))
			{
				ListeInserer(PileDepiler(p), courant, lp);
			}	
			
			PileDepiler(p); 			//Depiler la parenthèse ouvrante	
		}
	}

	while(!PileVide(p))
	{
		ListeInserer(PileDepiler(p), courant, lp);
		courant = courant->suivant;
	}

	PileDetruire(p);
	return(lp);
}

/* Transforme l'expression postfixé pour obtenir le résultat */
ELEMENT EvalPost(LISTE l)
{
	ELEMENT x, xd, xg;
	PILE p = PileCreer(20);	//Par choix;
	POSITION pos = ListePremier(l);
	POSITION fin = ListeSentinelle(l);

	for(; pos != fin; pos = ListeSuivant(pos, l))
	{
		ElementAffecter(&x, ListeAcceder(pos, l));

		if(Nombre(x))
			PileEmpiler(x, p);

		else
		{
			ElementAffecter(&xd, PileDepiler(p));
			ElementAffecter(&xg, PileDepiler(p));
			PileEmpiler((Appliquer(x, xg, xd)), p);
		}
	}
	
	ElementAffecter(&xd, PileDepiler(p));
	PileDetruire(p);

	return(xd);
}
