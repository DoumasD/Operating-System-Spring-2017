//Demetrios Doumas 2/16/17
// Part 2
// The cp command copies the source file specified by the SourceFile parameter to the destination file parameter
// Mimic it
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

//char* buffer = malloc(size);  //A buffer pointer use to point to the source file.
char* buffer2 = "XYZ";        //A second buffer to hold hold the string XYZ

//x=read(fd,buffer,size); // Reads the content of the source file to the buffer

if (x==-1)  //Check to see if there is an error reading 
perror("read");

//////////////////////////////////////////////////////////////////////////////////////////////////
/////////////// Write to the destination file

//char* Subbuffer[100];

/*
for(int i=0;i<size;)  // read up to the size of the source.txt file
{

read(fd,buffer,100); // read a hundred characters each iteration

	for(int j=0;j<=99;j++)
	{
	if(buffer[j]=='1')
		buffer[j]='A';
	
	}



write(fd2,buffer,100);
//	write(fd2,"XYZ",3);
i=i+100;
	
}
*/
int num_of_Loops = size/100;
int remainder = size%100;


printf("\nFile size: %d...\n", size);
printf("Total # Loops: %d\n",num_of_Loops);
printf("Remainder: %d\n",remainder);


char buf[100];
int text, w1,w2;
/

for (int i=0 ; i < num_of_Loops ; i++) // read 100 Chars each iteration 
	{
		text = read(fd, buf, 100);
		for (int j=0 ; j < 100 ; j++)
		{
			if (buf[j] == '1') buf[j]='A';
		}
		w1 =  write (fd2,buf,100);
	    w2 =  write (fd2,buffer2,3);
	}



/*
char* tempbuffer[4000];

for(int i=0;i<size;i=i+100)
{
	for(int j=i;j<=(i+99);j++)  //read 100 characters
	{
	if(buffer[j]=='1')
	buffer[j]='A';

	}

*/






















/*
	for(int h=(i=0);h<=size;h++)         //copy the values in buffer to temp
  	{
	tempbuffer[h]=buffer[h];
	}
*/
	//shift by four

	
	//assign the four values
	// save back to buffer



	//write(fd2,buffer,100);
	//write(fd2,"XYZ",size);//Append XYZ
	


        /*
	buffer[(i+99)]='X';
	buffer[(i+100)]='Y';
	buffer[(i+101)]='Z';
	buffer[(i+102)]=' ';
	*/
//}
//write(fd2,buffer,size);

























/*
int c=0;// counter

for(int i=0;i<=size;i++)
{

t=write(fd2,buffer,size);
	if(buffer[i]=='1')
	buffer[i]='A';
	c++;
	if(c==100)
	{
		write(fd2,buffer2,3);
		c=0;
	}

}



//t=write(fd2,buffer,size);

if(t==-1)
perror("write");
*/






//for(int i=0;i<=100;i++)
//{


//}











//////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////// Close file

close(fd);
close(fd2);

return 0;
}
