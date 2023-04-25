# CS219-Assignment3
This is the second assignment for CS 219

# How to Execute
In order to run this program, one must open a terminal and both input the name of this program (AssignmentTwoFinal) after a ./, then put a space, and lastly add the name of the text file it is reading from (Programming-Project-2). If both of these are not input correctly, the program will not run.

It should look like this: ./AssignmentThreeFinal Programming-Project-3.txt

# MAKE SURE TO USE THE TEXT FILE PROVIDED IT'S SLIGHTLY CHANGED FROM THE ORIGINAL (I checked with the professor to make sure this was okay)

If the code isn't running, use the command 'make clean' and then 'make' to reset the program.

# Purpose
In this program, we are preforming various operations, and detecting if they have change to the Z and N flags, and for some the C and V flags.

# Explanation
To start this program I include the necessary libraries at the top of my program needed to convert from decimal to hex, do exponents, as well as storing strings.

The main of the program is then intitalized with an argument passed in (which is the text file we will be reading from), the program checks that the appropriate amount of arguments have been passed in, and if there isn't the correct amount, it ends the program and tells the user that they need to include the correct text file.

After this we call the function named 'readFile' to read the inserted file. ReadFile is an int function with the only parameter being the textfile being passed in. Using the ifstream library, we declare that the file that is about to be used, then, declare the variables that will be storing the values retrieved from the file, which is the string operation that will be performed, the two int hex values being recieved, and an int for the total value. 

After this, the file is opened and it is declared that the file is going to be specifically read from, not edited in any way. If the file cannot be found, the function reports the error to the user using cout, and then ends there. However, if the file CAN be found, a while loop is declared where using the insertion operators, as long as their is material to store, first the operation is stored, and after using the hex keyword to detect numbers with '0x' in front of them, they store the first and second numbers in their respective variables.

An 'if' statment looks to find the operation being used, it does the operation, then the program then couts the operation variable, uses the hex keyword to change the decimal back to hex, outputs the next two numbers in hex while adding the '0x' back in front of them, and lastly output the final total in hex, also with a '0x' but also '<>' brackets. 

# Possible operations

ADD/ADDS: This operation takes the two registers from the text file, finds the hex, converts to decimal, and adds them together, if the operation is ADDS, the program will check for the result being zero, negative, having overflow, or a carry and change flags based off that. It then deposits the final number into the third register.

SUB/SUBS: This operation takes the two registers from the text file, finds the hex, converts to decimal, and subtracts them from each other, if the operation is SUBS, the program will check for the result being zero, negative, having overflow, or a carry and change flags based off that. It then deposits the final number into the third register.

AND/ANDS: This operation takes the two numbers from the text file, converts to decimal, and AND's them (using standard library) with eachother, if the operation is ANDS, the program will check for the result being zero or negative and change flags based off that. It then deposits the final number into the third register.

ORR/ORRS: This operation takes the two registers from the text file, finds the hex, converts to decimal, and OR's them (using standard library) with eachother, if the operation is ORSS, the program will check for the result being zero or negative and change flags based off that. It then deposits the final number into the third register.

LSR/LSRS: This operation takes the two registers from the text file, finds the hex, converts to decimal, and divides the first number by 2 to the power of the second number them with eachother, if the operation is LSRS, the program will check for the unsigned result being zero, negative, or have a carry and change flags based off that. It then deposits the final number into the third register.

LSL/LSLS: This operation takes the two registers from the text file, finds the hex, converts to decimal, and multiplies the first number by 2 to the power of the second number them with eachother, if the operation is LSLS, the program will check for the unsigned result being zero, negative, or have a carry and change flags based off that. It then deposits the final number into the third register.

XOR/XORS: This operation takes the two registers from the text file, finds the hex, converts to decimal, and XORS's them (using standard library), if the operation is XORS, the program will check for the result being zero or negative and change flags based off that. It then deposits the final number into the third register.

MOV: This operation takes the one register and a hex number from the text file, finds the reg, and moves that number into the register found.

TST: This operation takes into two registers from the text file, finds the hex, converts to decimal, and ANDS them together, changing the n and z flags but not saving the final value in any register.

CMP: This operation takes into two registers from the text file, finds the hex, converts to decimal, and SUBS them together, changing the n, z, c, and v flags but not saving the final value in any register.

After calculating all of that, the function checks for changing flags (first looking to see if the operation being done has an S at the end of it) using an if statement in which the program looks for if the final number is equal to zero or if its negative. If it does detect that, it will set the Z or N flags to 1, and if it detects nothing, then it will set the flags to 0. After this the function ends the program returns to reading the file. For the C and V flags, they are done in each individual operation case.

# Results and Overflow

The results of this program should be a displayed operation, two hex numbers, three registers, two registers and a hex number or a single register and a hex number. and the contents of each register, also displayed in hex. The correct output should be the correct opertaions for all functions, and the totals should be a hex number followed by either another hex or decimal, then the ouput, and lastly the flags on the line below.