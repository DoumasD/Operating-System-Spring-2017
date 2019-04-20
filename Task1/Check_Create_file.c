//Demetrios Doumas 2/16/17
// Part 0 B  Create an open file or read file
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

int main(int argc, char*argv[])
{


int fd;//file handler


fd=open("destination.txt",(O_RDWR|O_CREAT), S_IRWXU);// Read or create file that has write and read permissions.

if(fd==-1)  // error if file can't be open
	{
	printf("\n can't open or create the file\n");
	}
else     // the file opened sucessful
	{
	printf("Created/Open file");
	}

close(fd);

return 0;
}
