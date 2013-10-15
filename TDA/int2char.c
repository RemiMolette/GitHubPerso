// C File
// AUTHOR:   remitremblain
// FILE:     /Users/remitremblain/Desktop/TP2/int2char.c
// CREATED:  16:39:40 14/10/2013
// MODIFIED: 17:15:13 14/10/2013

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
 
int main(int nb_arg, char *tab_arg[])
{
	char buf[255];
	int i;
	printf("> ");
	scanf("%i", &i);
	sprintf(buf,"%d",i);	  	
	printf("= %s\n", buf);   
	return 0;
}

