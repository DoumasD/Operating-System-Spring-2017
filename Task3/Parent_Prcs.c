// Demetrios Doumas 3/10/17
// Task3 Parent Process  part 3
// Create two child processes that execute Prcs_P1.c and Prcs_P2.c
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>


int main(int argc, char* argv[])
{


int Child_One=fork();

if (Child_One==0)
{

printf("The Child One is succefully created and its pid is: %d /n ", getpid());
execv("Prcs_P1",&argv[0]);
	

	
}




else
{
printf("Parent behavior /n");



	int Child_Two=fork();

	sleep(1); //sleep one second
	if (Child_Two==0)
	{
	printf("The Child Two is succefully created and its pid is: %d\n ", getpid());
	execv("Prcs_P2", &argv[0]);
	}
	else
	{
	printf("Parent of child 2 is Child 1 behavior  /n");
	}



}





return 0;
}
