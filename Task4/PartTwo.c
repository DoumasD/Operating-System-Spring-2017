//Demetrios Doumas 3/17/17
//Task4 Average 
//Part 2 Average grade Calculator
// Director opens the file and read content into array
// Two manager pass data to two workers each who in return calculate the average

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/wait.h>
#include <string.h>

int main(int argc, char* argv[])
{


char* filename="quiz_grades.txt";
int row=10;  // Number of Students
int columns=4;  //chapters
int status;

double grades[columns][row];
double average[columns];
double acc_grade;
double averages[4];


////////////////////////////////////////////////// Open file

//Check file exist
int retval= access(filename, F_OK);

if (retval != 0)
{
	if(errno == ENOENT)
	{
	printf("%s doesn't exist \n",filename);
	}
	else if (errno == EACCES)
	{
	printf("%s is not accessible \n", filename);
	return 1;
	}
}

//Check read permission
retval= access(filename, R_OK);

if (retval != 0)
{
printf("%s is not readable (access denied)\n", filename);
return 1;	
}


//Open file
FILE *fd=fopen(filename,"r");


/////////////////////////////////////////////////////load data two dimension array

int count_row=0;
int count_columns=0;


while(count_row <= row-1)
{
	while(count_columns <= (columns-1))
	{
	fscanf(fd,"%lf", &grades[count_columns][count_row]);
	count_columns++;
	}

count_columns=0;
count_row++;
}




///////////////////////////////////////////////// Two Managers with two workers each

int ManagerOne=fork();
if(ManagerOne==0)
{

int workerOne=fork();

	if(workerOne==0)
	{
		for(int R=0;R<row;R++)
		{
		acc_grade+=grades[0][R];
	
		}
	
	printf("Column One Avg Grade is: %lf\n", (acc_grade/(10.0)));
	wait(&status);
        exit(0); 
	}
	else if(workerOne == -1) printf("A worker One WAS NOT created successfully = -1");     
        else 
        {
            wait(&status);  
        }


int workerTwo=fork();

	if(workerTwo==0)
	{
	 acc_grade=0;
		for(int R=0;R<row;R++)
		{
		acc_grade+=grades[1][R];
	
		}
	
	printf("Column Two Avg Grade is: %lf\n", (acc_grade/(10.0)));
	wait(&status);
        exit(0);
	}	
	else if(workerTwo == -1) printf("A worker Two WAS NOT created successfully = -1");     
        else 
        {
            wait(&status);  
        }


}
else if (ManagerOne == -1) 
printf("First manager WAS NOT created successfully = -1");    
else 
wait(&status);









int ManagerTwo=fork();

if(ManagerTwo==0)
{

int workerThree=fork();
	
	if(workerThree==0)
	{
		acc_grade=0;
		for(int R=0;R<row;R++)
		{
		acc_grade+=grades[2][R];
	
		}
	
	printf("Column Three Avg Grade is: %lf\n", (acc_grade/(10.0)));
	wait(&status);
        exit(0);
	}	
	else if(workerThree == -1) printf("A worker Three WAS NOT created successfully = -1");     
        else 
        {
            wait(&status);  
        }



int workerFour=fork();

	if(workerFour==0)
	{
		acc_grade=0;
		for(int R=0;R<row;R++)
		{
		acc_grade+=grades[3][R];
	
		}
	
	printf("Column Four Avg Grade is: %lf\n", (acc_grade/(10.0)));
	wait(&status);
        exit(0);
	}
	else if(workerFour == -1) printf("A worker Four WAS NOT created successfully = -1");     
        else 
        {
            wait(&status);  
        }
}
else if (ManagerTwo == -1) 
printf("First manager WAS NOT created successfully = -1");    
else 
wait(&status);






///////////////////////////////// Close File
fclose(fd);
return 0;
}
