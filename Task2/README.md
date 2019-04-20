# Demetrios Doumas Spring 2017
# Project Name: Operating System Lab Assignment 2

# Description:

This assignment involves process management by using certain types of system calls such as fork(), getpid(), getppid(), and waitpid(). Please read the background information in the assignment pdf called "PMSysCalls_1." The main program is called a parent process and if fork() is called it creates another process called child. The child inherits resources from the parent. Each process has its own id and memory address.

Tasks:

Part 1 Write a program children.c, and let the parent process produce two child processes. One prints
out "I am child one, my pid is: " PID, and the other prints out "I am child two, my pid is: " PID.
Guarantee that the parent terminates after the children terminate (Note, you need to wait for two
child processes here). Use the getpid() function to retrieve the PID.

Part 2 Consider the parent process as P. The program consists of fork() system call statements placed at
different points in the code to create new processes Q and R. The program also shows three variables:
a, b, and pid - with the print out of these variables occurring from various processes. Show the values
of pid, a, and b printed by the processes P, Q, and R.

//parent P
int a=10, b=25, fq=0, fr=0
fq=fork() // fork a child - call it Process Q
if(fq==0) // Child successfully forked
 a=a+b
 print values of a, b, and process_id
 fr=fork() // fork another child - call it Process R
 if(fr!=0)
 b=b+20
 print values of a, b, and process_id
 else
 a=(a*b)+30
 print values of a, b, and process_id
else
b=a+b-5;
print values of a, b, and process_id

Files partOne and partTwo are executable files that I created.

# Instruction:

1.) Open Linux, or any other plateform that you may use to run c programs.
2.) Download all the files.
3.) Compile and link each part.  gcc name-of-c-file -o name-of-exe
4.) Run the executable. 
