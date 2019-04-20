# Demetrios Doumas Spring 2017
# Project Name: Operating System Lab Assignment 1

# Description:

This assignment involves system calls with regards to file management. System calls used in this assignment are open, create, read, write,Iseek, and close. To see the description of each tasks for this assignment please look at "FMSysCalls" pdf.


Tasks:

0. (a) Extend code snippet 1 to check for read and write access permissions of a given file
(b) Write a C program where open system call creates a new file (say, destination.txt) and then
opens it. (Hint: use the bitwise OR flag)

1. UNIX cat command has three functions with regard to text files: displaying them, combining copies
of them and creating new ones.

Write a C program to implement a command called displaycontent that takes a (text) file name as
argument and display its contents. Report an appropriate message if the file does not exist or can’t
be opened (i.e. the file doesn’t have read permission). You are to use open(), read(), write() and
close() system calls.

NOTE: Name your executable file as displaycontent and execute your program as ./displaycontent
file_name

For part one please recompile and link to again to your own executable name. 

2. The cp command copies the source file specified by the SourceFile parameter to the destination file
specified by the DestinationFile parameter.
Write a C program that mimics the cp command using open() system call to open source.txt file
in read-only mode and copy the contents of it to destination.txt using read() and write() system
calls.

3. Repeat part 2 (by writing a new C program) as per the following procedure:
(a) Read the next 100 characters from source.txt, and among characters read, replace each character
’1’ with character ’A’ and all characters are then written in destination.txt  Note: My file is named dest.txt
(b) Write characters "XYZ" into file destination.txt
(c) Repeat the previous steps until the end of file source.txt. The last read step may not have 100
characters.


# Instruction:

1.) Open Linux, or any other plateform that you may use to run c programs.
2.) Download all the files.
3.) Compile and link each part.  gcc name-of-c-file -o name-of-exe
4.) Run the executable. 







