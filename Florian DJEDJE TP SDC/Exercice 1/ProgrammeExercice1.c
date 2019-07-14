/*
 Produit par Florian DJEDJE
 GL2 IFRI
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t pid1, pid2, pid3;
	int status;

	printf("C'est moi le père\n");
	pid1 = fork();
	if(pid1<0)
	{
		printf("Le fils 1 n'a pas pu être créé\n");
		pid1 = wait(&status);
		exit(-1);
	}
	if(pid1==0)
	{
		execv("./fils1", NULL);
	}
	else
	{
		pid2 = fork();
		if(pid2<0)
		{
			printf("Le fils 2 n'a pas pu être créé\n");
			pid1 = wait(&status);
			pid2 = wait(&status);
			exit(-1);
		}
		if(pid2==0)
		{
			execv("./fils2", NULL);
		}
		else
		{
			pid3 = fork();
			if(pid3<0)
			{
				printf("Le fils 3 n'a pas pu être créé\n");
				pid1 = wait(&status);
				pid2 = wait(&status);
				pid3 = wait(&status);
				exit(-1);
			}
			if(pid3==0)
			{
				execv("./fils3", NULL);
			}
			else
			{
				pid1 = wait(&status);
				printf("Fils 1; PID : %d et de status : %d \n", pid1, status);
				
				pid2 = wait(&status);
				printf("Fils 2; PID : %d et de status : %d \n", pid2, status);
				pid3 = wait(&status);
				printf("Fils 3; PID :: %d et de status : %d \n", pid3, status);
			}
		}
	}
	return 0;
}
