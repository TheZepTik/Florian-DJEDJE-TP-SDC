/*
 Produit par Florian DJEDJE
 GL2 IFRI
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	printf("Fils 2; PID : %ld \n", (long)getpid());
	
	return 0;
}


