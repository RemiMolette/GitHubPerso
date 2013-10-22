#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "topo.h"

void init_tabnivo(int * tab){
    
	int cpt;
	
	for(cpt = 0; cpt < NB_SOMMET; cpt++)
		tab[cpt] = 0;
}

int main ()
{
    //Graphe connexe avec un sommet sans predecesseur
    //présence de racine, file pas vide au début
    
    //Initialiser (Graphe, succ[], head[], nbPred[], head[], tab_nivo[], File
    int cpt, cpt2, niveau, courant, courant2, File_taille;
    
    //Initialisation en dur des tableaux de l'algorithme
    char ReprGraphe[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int head[NB_SOMMET]= {0, 1, 2, 4, 5, 5, 7, 9, 9};
    int succ[NB_SOMMET*(NB_SOMMET-1)] = {5, 4, 6, 7, 7, 1, 2, 1, 3};
    int nPred[NB_SOMMET] = {0, 2, 1, 1, 1, 1, 1, 2};
    
    int tab_nivo[NB_SOMMET];
    init_tabnivo(tab_nivo);
    
    int File[NB_SOMMET];
    int FileFin = -1;       //Indice de la fin de file
    
    niveau = 0;
    
    for(cpt = 0; nPred[courant] != 0; cpt++){}          //Parcours jusqu'au sommet de départ
    FileEntrer(File, &FileFin, cpt);
    
    //Trier (Graphe, succ[], head[], nPred[], tab_nivo[], File, taille_file
    
    while(!FileVide(FileFin))
    {
        niveau ++;
        File_taille = FileFin + 1;
        
        /* Traitement de tout les noeuds du niveau */
        for(cpt2=0; cpt2<File_taille; cpt2++)
        {
            courant = FileSortir(File, &FileFin);
            tab_nivo[courant] = niveau;
            
            /* parcours des successeurs */
            for(cpt=head[courant]; cpt<head[courant+1]; cpt++)
            {
                courant2 = succ[cpt];
                nPred[courant2] = nPred[courant2] - 1;
                
                if(nPred[courant2] == 0)
                    FileEntrer(File, &FileFin, courant2);
            }
        }
    }
    
    //Afficher
    for(cpt=0; cpt<NB_SOMMET-1; cpt++)
			printf("L'élément %c a le niveau : %i\n", ReprGraphe[cpt], tab_nivo[cpt]);
    
    return EXIT_SUCCESS;
}