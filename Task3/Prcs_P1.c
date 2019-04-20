// Demetrios Doumas 3/9/17
// Part 3  --Part1
// Create Destination1.txt file and Destination2.txt file 2 with Read/write permissions
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
int fd,fd2;
fd = open("destination1.txt", O_RDWR|O_CREAT,S_IRWXU); // open or create the destination1 file
fd2 = open("destination2.txt", O_RDWR|O_CREAT,S_IRWXU); // open or create the destination2 file



if(fd == -1) //error opening  Destination1 file
{
printf("sorry, I couldn't open Destination 1 file\n");
perror("open"); 
}
else
{
printf("Destination 1 File is able to Open \n");
}


if(fd2 == -1) //error opening Destination 2 file
{
printf("sorry, I couldn't open Destination 2 file\n");
perror("open"); 
}
else
{
printf("Destinaion 2 File is able to Open \n");
}


return 0;
}
