/*****************************************************************
*		Fichier :  	ELTINT.H
*		Format :	Source C 
*		Version  : 	19/9/96
*		Programmeurs :	Delozanne/Jacoboni, Futtersack
*		Contenu :      	Déclaration de la structure de données adoptée
*				pour une réalisation du TDA ELEMENT.
*				
******************************************************************/

#ifndef _ELTCHAR_H                   /* pour l'inclusion conditionnelle */
#define  _ELTCHAR_H

/* Déclaration d'un type concret ELEMENT
- un élément est dans ce fichier de type int ; par convention l'élément vide est 32767;
 le stockage est direct*/

/* plus généralement pour un stockage direct un élément de type simple ou "pas trop gros"
par exemple : un nombre complexe, un point */

typedef char* ELEMENT;


#define ELEMENT_VIDE '\0'

#endif