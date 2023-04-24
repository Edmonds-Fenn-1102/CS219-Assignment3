//
//Author: Fenn Edmonds
//Purpose: To implement multiple reg functions using c++ code
//Date: 2/22/2023
//

//These are the libraries needed to implement this code
#include <iostream>
#include <string>
#include <fstream>
#include <math.h> 

using namespace std;

//Prototype for the readfile function
int readFile(string);
uint32_t findRegOne(string);
uint32_t findRegTwo(string);
void inputReg(string, uint32_t);

int nFlags(uint32_t);
int zFlags(uint32_t);

uint32_t reg1 = 0, reg2 = 0, reg3 = 0, reg4 = 0, reg5 = 0, reg6 = 0, reg7 = 0, reg0 = 0;

int main(int argc, char* argv[]) //argc/argv are included when running this program, which is the executable name and the text file
{


    string opToDo;
    string regOne, regTwo, regThree;
    uint32_t firstNum, secondNum, newNum;
    int nFlag = 0;
    int zFlag = 0;
    //This checks if executable and file were both input correctly, and if they aren't, ends the program
    if (argc != 2){
      
        cout << "File was not found" << endl;

        return 0;
    }

    else{

    //This is a variable holding the textfile
    string numberList = "test.txt";

    //Use the ifstream library to make a variable
    ifstream inputFile;

    //These variables hold the input from the textfile, being the operation and numbers respectivly

    //This opens the file for reading
    inputFile.open(numberList);

    //Check if the inputfile is able to be open for reading, and end the program if it cannot
    if(!inputFile)
    {
        cout << "File was not found" << endl;
        return -1;
    }
    
    //Use the insertion operator as well as the hex converter to store the lines of the textfile into variables
    //It should go as long as the input file has content to read
    //while(inputFile >> opToDo >> regOne >> hex >> secondNum || inputFile >> opToDo >> regOne >> regTwo >> regThree || inputFile >> opToDo >> regOne >> regTwo >> hex >> firstNum || inputFile >> opToDo >> regOne >> regTwo)
    while(!inputFile.eof())
    {
        inputFile >> opToDo;
        
            //Check if the operation preformed is addition
            if(opToDo == "MOV" || opToDo == "mov")
            {
                inputFile >> regOne >> hex >> secondNum;

                if(regOne == "r0," || regOne == "R0,")
                {
                    reg0 = secondNum;
                }
                else if(regOne == "r1," || regOne == "R1,")
                {
                    reg1 = secondNum;
                }
                else if(regOne == "r2," || regOne == "R2,")
                {
                    reg2 = secondNum;
                }
                else if(regOne == "r3," || regOne == "R3,")
                {
                    reg3 = secondNum;
                }
                else if(regOne == "r4," || regOne == "R4,")
                {
                    reg4 = secondNum;
                }
                else if(regOne == "r5," || regOne == "R5,")
                {
                    reg5 = secondNum;
                }
                else if(regOne == "r6," || regOne == "R6,")
                {
                    reg6 = secondNum;
                }
                else if(regOne == "r7," || regOne == "R7,")
                {
                    reg7 = secondNum;
                }

                //Output all variables using cout, and make sure to convert all numbers to hex
                cout << opToDo << " " << hex << regOne << ", 0x" << hex << secondNum << endl;
                cout << "R0: 0x" << hex << reg0 << " R1: 0x" << hex << reg1 << " R2: 0x" << hex << reg2 << " R3: 0x" << hex << reg3 << endl;
                cout << "R4: 0x" << hex << reg4 << " R5: 0x" << hex << reg5 << " R6: 0x" << hex << reg6 << " R7: 0x" << hex << reg7 << endl;
                cout << "N: " << nFlag << " Z: " << zFlag << endl;
            }
        }
        //Check if the operation preformed is addition
        if(opToDo == "ADD" || opToDo == "ADDS")
        {

            inputFile >> regOne >> regTwo >> regThree;
            
            //Add the two hex numbers together
            newNum = firstNum + secondNum;

            //set flags if they can be set
            if(opToDo == "ADDS")
            {
                nFlag = nFlags(newNum);
                zFlag = zFlags(newNum);
            }

            //Output all variables using cout, and make sure to convert all numbers to hex
            cout << opToDo << " 0x" << hex << firstNum << " 0x" << hex << secondNum << ": <0x" << newNum << ">" << endl;

            
        }

        //check for sub operation
        if(opToDo == "SUB" || opToDo == "SUBS")
        {
            //subtract varaiables
            newNum = firstNum - secondNum;

            if(opToDo == "SUBS")
            {
                nFlag = nFlags(newNum);
                zFlag = zFlags(newNum);
            }

            cout << opToDo << " 0x" << hex << firstNum << " 0x" << hex << secondNum << ": <0x" << newNum << ">" << endl;

        }

        //check for AND operation
        if(opToDo == "AND" || opToDo == "ANDS")
        {
            //do a bitwise AND operation
            newNum = firstNum & secondNum;

            if(opToDo == "ANDS")
            {
                nFlag = nFlags(newNum);
                zFlag = zFlags(newNum);
            }

            cout << opToDo << " 0x" << hex << firstNum << " 0x" << hex << secondNum << ": <0x" << newNum << ">" << endl;
        }

        //Check for OR operation
        if(opToDo == "ORR" || opToDo == "ORRS")
        {
            //do a bitwise OR operation
            newNum = firstNum | secondNum;

            if(opToDo == "ORRS")
            {
                nFlag = nFlags(newNum);
                zFlag = zFlags(newNum);
            }

            cout << opToDo << " 0x" << hex << firstNum << " 0x" << hex << secondNum << ": <0x" << newNum << ">" << endl;
        }

        //Check for NOT operation
        if(opToDo == "NOT" || opToDo == "NOTS")
        {
            //preform bitwise NOT operation
            newNum = ~firstNum;

            if(opToDo == "NOTS")
            {
                nFlag = nFlags(newNum);
                zFlag = zFlags(newNum);
            }

            cout << opToDo << " 0x" << hex << firstNum << hex << ": <0x" << newNum << ">" << endl;
        }

        //Check for XOR operation
        if(opToDo == "XOR" || opToDo == "XORS")
        {
            //do bitwise XOR operation
            newNum = firstNum ^ secondNum;

            if(opToDo == "XORS")
            {
                nFlag = nFlags(newNum);
                zFlag = zFlags(newNum);
            }

            cout << opToDo << " 0x" << hex << firstNum << " 0x" << hex << secondNum << ": <0x" << newNum << ">" << endl;
        }

        //check for ASR operation
        if(opToDo == "ASR" || opToDo == "ASRS")
        {
            //convert to signed
            int32_t newestNum = firstNum;

            //shift to the right
            newNum = newestNum / pow(2, secondNum);

            if(opToDo == "ASRS")
            {
                nFlag = nFlags(newNum);
                zFlag = zFlags(newNum);
            }

            if(newNum != 0)
            {
                cout << opToDo << " 0x" << hex << firstNum << " " << hex << secondNum << ": <0x" << (newNum) << ">" << endl;
            }
            else
            {
                cout << opToDo << " 0x" << hex << firstNum << " " << hex << secondNum << ": <0x" << (newNum-1) << ">" << endl;
            }

        }

        //Check for LSR operation
        if(opToDo == "LSR" || opToDo == "LSRS")
        {
            //preform LSR op
            newNum = firstNum / pow(2, secondNum);

            if(opToDo == "LSRS")
            {
                nFlag = nFlags(newNum);
                zFlag = zFlags(newNum);
            }

            cout << opToDo << " 0x" << hex << firstNum << " " << hex << secondNum << ": <0x" << newNum << ">" << endl;
        }

        //check for LSL operation
        if(opToDo == "LSL" || opToDo == "LSLS")
        {
            //preform LSL op
            newNum = firstNum * pow(2, secondNum);

            if(opToDo == "LSLS")
            {
                nFlag = nFlags(newNum);
                zFlag = zFlags(newNum);
            }

            cout << opToDo << " 0x" << hex << firstNum << " " << hex << secondNum << ": <0x" << newNum << ">" << endl;
        }

    }

    return 0;
}


//set the n flags (if result is negative, set to 1)
int nFlags(uint32_t num)
{
    //change to signed
    int32_t check = num;

    if(check < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


//set the zero flags (if result is 0, set to 1)
int zFlags(uint32_t num)
{
    if(num == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

uint32_t findRegOne(string regOne)
{
    if(regOne == "r0," || regOne == "R0,")
        {
            return reg0;
        }
        else if(regOne == "r1," || regOne == "R1,")
        {
            return reg1;
        }
        else if(regOne == "r2," || regOne == "R2,")
        {
            return reg2;
        }
        else if(regOne == "r3," || regOne == "R3,")
        {
            return reg3;
        }
        else if(regOne == "r4," || regOne == "R4,")
        {
            return reg4;
        }
        else if(regOne == "r5," || regOne == "R5,")
        {
            return reg5;
        }
        else if(regOne == "r6," || regOne == "R6,")
        {
            return reg6;
        }
        else if(regOne == "r7," || regOne == "R7,")
        {
            return reg7;
        }
}

uint32_t findRegTwo(string regOne)
{
    if(regOne == "r0," || regOne == "R0,")
        {
            return reg0;
        }
        else if(regOne == "r1," || regOne == "R1,")
        {
            return reg1;
        }
        else if(regOne == "r2," || regOne == "R2,")
        {
            return reg2;
        }
        else if(regOne == "r3," || regOne == "R3,")
        {
            return reg3;
        }
        else if(regOne == "r4," || regOne == "R4,")
        {
            return reg4;
        }
        else if(regOne == "r5," || regOne == "R5,")
        {
            return reg5;
        }
        else if(regOne == "r6," || regOne == "R6,")
        {
            return reg6;
        }
        else if(regOne == "r7," || regOne == "R7,")
        {
            return reg7;
        }
}

void inputReg(string regOne, uint32_t input)
{
    if(regOne == "r0," || regOne == "R0,")
        {
            reg0 = input;
        }
        else if(regOne == "r1," || regOne == "R1,")
        {
            reg1 = input;
        }
        else if(regOne == "r2," || regOne == "R2,")
        {
            reg2 = input;
        }
        else if(regOne == "r3," || regOne == "R3,")
        {
            reg3 = input;
        }
        else if(regOne == "r4," || regOne == "R4,")
        {
            reg4 = input;
        }
        else if(regOne == "r5," || regOne == "R5,")
        {
            reg5 = input;
        }
        else if(regOne == "r6," || regOne == "R6,")
        {
            reg6 = input;
        }
        else if(regOne == "r7," || regOne == "R7,")
        {
            reg7 = input;
        }
}