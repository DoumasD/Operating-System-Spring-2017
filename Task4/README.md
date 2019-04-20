# Demetrios Doumas Spring 2017
# Project Name: Operating System Lab Assignment 4
# Description:

The assignment is part two in the "SysCall_Summary" pdf. It is called Average Grade calculator. Data is given in a matrix 10 by 4. There are ten students and four chapters. The data shows the grade that each student received for each chapter. The software that I wrote follows figure (b) in the pdf. The main code is the director or the parent process. The director has two workers called managers. The managers themselves have two workers that each calculate the avg of a chapter. The first manager has the workers do calculations on the first two columns and the latter manager allows its workers to calculate the average in the last two chapters.

# Instruction:

1.) Open Linux.
2.) Download all the files.
3.) Compile and link each part.  gcc name-of-c-file -o name-of-exe
4.) Run the executable.