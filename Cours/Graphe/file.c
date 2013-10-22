//
//  file.c
//  

#include "file.h"

/*
 *  Création et modification de la liste par tableau
 */

/* Ajouter un élément dans la liste -- L'indice de fin augmente aussi */
void FileEntrer(int *file, int *fin, int elt)
{
    if(*fin<NB_SOMMET)
    {
		*fin = *fin + 1;
		file[*fin] = elt;
	}
}

/* Sorti d'un élément de la liste -- on ajuste la fin en conséquence */
int FileSortir(int *file, int *fin)
{
    int res=file[0];
	int i;
	
	if(*fin >= 1)
    {
		for(i=1; i<=*fin ; i++)
			file[i-1] = file[i];
	}
	
	*fin = *fin - 1;
	
	return res;
}

/* Test de file vide */
int FileVide(int fin)
{
	return (fin == -1);
}

/* Affichage classique de la liste */
void FileAfficher(int *file, int sommet)
{    
	int i;
	
	printf("\nFile : \n");
	
	for(i=0; i<=sommet; i++) 
		printf("%i\n", file[i]);
}
