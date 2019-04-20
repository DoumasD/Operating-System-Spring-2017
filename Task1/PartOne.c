//Demetrios Doumas 2/16/17
// Part 1
// Create your own displaycontent command
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

int main(int argc, char*argv[])
{

int fd,CC, size, returnval;
size_t x; //for handling read system call

printf("A \n");

if(2 != argc)
{
printf("\n Usage : \n");
return 1;
}



fd = open(argv[1],O_RDONLY); // open the second argument that contains the file name

if(fd == -1) //error opening file
{
printf("sorry, I couldn't open filename\n");
perror("open"); /* This will explain why */
}
else
{
printf("File is able to Open \n");
}


///////////////////////////////////////////////////////////////////
// Read content
FILE *fp =fopen(argv[1], "r");
fseek(fp ,0,SEEK_END);
size = ftell(fp);
rewind(fp);
fclose(fp);
char* buffer = malloc(size);

x=read(fd,buffer,size);

if (x==-1)
perror("read");


for(int i=0;i<=size;i++)
{
printf("%c",buffer[i]);

}


////////////////////////////////////////////////////////////////////


	CC=close(fd); // Close the file
	if( CC < 0)  // if error on closing file
	perror("close");


return 0;
}
