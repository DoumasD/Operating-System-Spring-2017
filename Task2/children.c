// Demetrios Doumas 2/24/17 Task 2 part1
// Two Child process creation
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>

int main()
{

// Parent process
printf("I am the parent. My pid: %d\n", getpid());
int child_One=fork();  // creates child one
int status1, status2,pid_childOne,pid_childTwo;


	if(child_One==0)
	{
	printf("I am child one, my pid is: %d\n",getpid());
	printf("My parent is: %d\n",getppid());
	}
	else
	{
	printf("In parent mode. My pid is: %d\n", getpid());
	
	int child_Two=fork();  //creates child two
	

		if(child_Two==0)
		{
		printf("I am child Two, my pid is: %d\n",getpid());
		printf("My parent is: %d\n",getppid());
		}
		else{
		pid_childOne=waitpid(child_One,&status1,0);   // waits for child one and child two to end
		pid_childTwo=waitpid(child_Two,&status2,0);}
	}



return 0;
}
