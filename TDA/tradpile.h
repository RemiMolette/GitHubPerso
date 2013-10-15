/*****************************************************************
*		Fichier :  	tradpile.h
*		Format :	Source C 
*		Version  : 	07/10/13
*		Programmeurs :	Tremblain	
*		Contenu :      	Primitive de l'Algorithme de traduction 
*						infixée vers postfixé
*		
******************************************************************/

#ifndef TRADPILE
#define TRADPILE


#include "eltprim.h"
#include "pileprim.h"
#include "lstprim.h"

/* Algorithme de comparaison */

/* Retourne 1 si l'élément est un chiffre, sinon 0 */
bool Nombre(ELEMENT);

/* retourne vrai si l'élément est un opérateur, 0 sinon */
bool Operateur(ELEMENT);

/* retourne vrai si l'élément est une parenthèse ouvrante, 0 sinon */
bool Ouvrante(ELEMENT);

/* retourne vrai si l'élément est une parenthèse fermante, 0 sinon */
bool Fermante(ELEMENT);

/* retourne vrai si l'élément 1 à une priorité supérieure ou égale à l'élément 2, 0 sinon */
bool Prioritaire(ELEMENT, ELEMENT);

/* Effectue l'opération adéquate */
ELEMENT Appliquer(ELEMENT, ELEMENT, ELEMENT);


/*
 * Algirithme de traitement 
 */
/* On traduit déjà une expression infixée en expression postfixée pour un traitement ultérieur */
LISTE Inf2Post(LISTE);

/* On calcul l'expression postifixée */
ELEMENT EvalPost(LISTE);

/* On passe la chaine de caractère dans une liste */
LISTE Str2Lst(char *);

#endif
