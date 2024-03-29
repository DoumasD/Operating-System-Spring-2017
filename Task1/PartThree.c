//Demetrios Doumas 2/16/17
// Part 3
// The cp command copies the source file specified by the SourceFile parameter to the destination file parameter
// Mimic it
// Attach XYZ at the end of every 100 characters. Replace 1 with A from the source.txt to the detination file called dest.txt
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

int fd, fd2, t,size,x;

if(3 != argc) 
{
printf("\n Missing Three Parameters \n");
return 1;
}


fd2 = open(argv[2], O_WRONLY|O_CREAT,S_IRWXU); // open or create the destination file
fd = open(argv[1],O_RDONLY,S_IRWXU); // open the source file that you want to copy from

	if(fd == -1) //error opening file
		{
		printf("sorry, I couldn't open source file\n");
		perror("open"); 
		}
	else
		{
		printf("Source File is able to Open \n");
		}

	if(fd2 == -1) //error opening file
		{
		printf("sorry, I couldn't open destination file\n");
		perror("open"); 
		}
	else
		{
		printf("Destination File is able to Open or Create \n");
		}


////////////////////////////////////////////////////////////////////////////////////////////////
///////////////  Read the source file

FILE *fp =fopen(argv[1], "r"); // open the source file
fseek(fp ,0,SEEK_END); //finds the end of the source file
size = ftell(fp); // gives the file size of the source file
rewind(fp); // Reposition the file handler fp to the beginng of the file
fclose(fp); // closes the handler fp


char* buffer2 = "XYZ";        //A second buffer to hold hold the string XYZ


if (x==-1)  //Check to see if there is an error reading 
perror("read");

//////////////////////////////////////////////////////////////////////////////////////////////////
/////////////// Write to the destination file


int num_of_Loops = size/100;
int remainder = size%100;

printf("\nFile size: %d\n", size);
printf("Total # Loops: %d\n",num_of_Loops);
printf("Remainder: %d\n",remainder);


char buf[100];
int read_text, ws;


for (int i=0 ; i < num_of_Loops ; i++) // read 100 Chars each iteration 
	{
		read_text = read(fd, buf, 100);
		for (int j=0 ; j < 100 ; j++)
		{
			if (buf[j] == '1') buf[j]='A';
		}
		ws =  write (fd2,buf,100);
	    ws =  write (fd2,buffer2,3);
	}



//Reading less than 100 characters at the end of the file
char Buf[remainder]; 
read(fd, Buf, remainder);	

for (int u=0 ; u < remainder ; u++) 
	{
		if (Buf[u] == '1') Buf[u]='A';  //Convert 1 to A
		if (u == remainder-1)           // If reached the end start to write to the destination file.
		{
			write (fd2,Buf,remainder); // The less than 100 chars that were manipluated
			write (fd2,buffer2,3);
		}

	}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////// Close files

close(fd);
close(fd2);

return 0;
}
