#include <stdio.h>
#include <string.h>
 
void LireChaine(char chaine[], int size) {
    fgets(chaine, size, stdin);
    chaine[strlen(chaine) - 1] = '\0';
}
 
int main() {
 
    char temp[64];
 
    printf ("Veuillez entrer une phrase : ");
    LireChaine(temp, 64);
 
    printf ("Vous avez entré : %s\n", temp);
 
    return 0;
 
}
