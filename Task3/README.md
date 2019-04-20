# Demetrios Doumas Spring 2017
# Project Name: Operating System Lab Assignment 3

# Description:

This assignment involves processes executing program files by using system calls. Please read “PMSysCalls_2” for more information on process management system calls.

Part 1, a child process is used to get the time and date.
Part 2, a child process is used to execute a command that allows the user to see all the files in a directory.
Part 3, a parent process is created, where it creates two child processes. 
The first child creates two texts files and the latter write information to both files.


Tasks:

Part 1 

Write a program where a child is created to execute command that tells you the date and time in
Unix.
Use execl(...).
Note, you need to specify the full path of the file name that gives you date and time information.
Announce the successful forking of child process by displaying its PID.

Part 2 

Write a program where a child is created to execute a command that shows all files (including hidden
files) in a directory with information such as permissions, owner, size, and when last modified.
Use execvp(...).
For the command to list directory contents with various options, refer the handout on Unix file
system sent to you in the first class.
Announce the successful forking of child process by displaying its PID.

Part 3

[Step 1] Prcs_P1.c: Create two files namely, destination1.txt and destination2.txt with read, write,
and execute permissions.

[Step 2] Prcs_P2.c: Copy the contents of source.txt1 into destination1.txt and destination2.txt as
per the following procedure.
1. Read the next 100 characters from source.txt, and among characters read, replace each character
’1’ with character ’A’ and all characters are then written in destination1.txt

2. Then the next 50 characters are read from source.txt, and among characters read, replace each
character ’2’ with character ’B’ and all characters are then written in destination2.txt.

3. The previous steps are repeated until the end of file source.txt. The last read may not have
100 or 50 characters.

Once you’re done with successful creation of executables for the above two steps do the following.

Write a C program and call it Parent_Prcs.c. Execute the files as per the following procedure using
execv system call. Use sleep system calls to introduce delays.
[Step 3] Fork a child process, say Child 1 and execute Prcs_P1. This will create two destination
files according to Step 1.

[Step 4] After Child 1 finishes its execution, fork another child process, say Child 2 and execute
Prcs_P2 that accomplishes the procedure described in Step 2.


# Instruction:

1.) Open Linux.
2.) Download all the files.
3.) Compile and link each part.  gcc name-of-c-file -o name-of-exe
4.) Run the executable. 
