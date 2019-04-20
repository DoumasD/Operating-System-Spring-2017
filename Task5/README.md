# Demetrios Doumas Spring 2017
# Project Name: Operating System Lab Assignment 5

# Description:

This assignment is about syncing muiltiple processes for the Dad-Son problem. The dad has to deposit money into his account, which is a variable called balance. He has two sons that withdraws money from the balance variable. I used text files between those process to keep track of how many times did each process access the three critical sections, and counting the number of times that two processes have to wait. The critical sections are the dad depositing money and the two sons withrawing money. Please read the "Dad-Son Problem" pdf and the "Task5_Summary" pdf files.

The semi.h file is given.
The bank.c file was given and I modified it.
The bank file is an executable file that I created. Please recompile the bank.c file and run it.

# Instruction:
1.) Open Linux.
2.) Download all the files.
3.) Compile and link each part.  gcc name-of-c-file -o name-of-exe
4.) Run the executable.