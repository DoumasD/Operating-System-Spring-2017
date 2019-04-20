// Demetrios Doumas Task3 3/3/17
// Part1
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>


int main(int argc, char *argv[])
{

int child_One=fork();


if(child_One==0)
{
printf("The Child is succefully created and its pid is: %d\n ", getpid());
//printf("The date and time is: \n");
execl("/bin/date", argv[0],NULL);
}
else
{
printf("Parent behavior.\n");

}




return 0;
}
