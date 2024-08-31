#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimumLimit = 0; // Declare variables for the maximum and mininum numbers of the table
int maximumLimit = 0;
int leftNumber = 0;
int rightNumber = 0;
int tablesNumber = 0;
int maximumTablesNumber = 0;
int rightNumberReset = 0;
int userFaults = 0;

void generatorMenu(); // Declaring functions
void tableGenerator();

int main() // Multiplication table generator

{ 

generatorMenu();    

}

void generatorMenu() {

    printf("\n\nThis is a multiplication table generator!\n\n"); // Receive input from the user
    printf("Please, type the number you want to begin with your table: \n\n");
    scanf("%i", &minimumLimit);
    printf("\nNow, the number that you want to end with: \n\n");
    scanf("%i", &maximumLimit);

    leftNumber = minimumLimit; // Initializes the 'leftNumber' variable so that the tables start with the smallest number
    maximumTablesNumber = abs((maximumLimit - minimumLimit)); // Specifies how many tables are expected to be generated

    if (maximumLimit < minimumLimit && userFaults == 1) 
    {
        printf("\nFuck you!\n\n");
        exit(0);
    }

    if (maximumLimit < minimumLimit) 
    {

        printf("\nYou are not supposed to write the first number bigger than the second >:(\n\n");
        printf("Let's try again: \n\n\n");
        userFaults++;
        generatorMenu();
        exit(0);

    } else 
    {

        tableGenerator();

    }

}

void tableGenerator() 

{

    while (maximumLimit > minimumLimit) // Creates tables in loop
    
    {
        
        printf("\n%i x %i = %i\n", leftNumber, rightNumber, leftNumber * rightNumber);

        rightNumber++;
        rightNumberReset++;

    if (rightNumber > maximumLimit) // Ends a table when the right number reaches its maximum value
    
        { 
        
        leftNumber++;
        tablesNumber++;
        rightNumber = rightNumber - rightNumberReset;
        rightNumberReset = rightNumber;

        printf("\n\n-------------------------------------------------------\n\n");

        } 

    if (tablesNumber > maximumTablesNumber) // Ends the program if the number of tables printed are equal to the number of tables expected
    
    { 

        exit(0);

    }

    }

}

/*
It remains to be seen whether the program can handle all 4 cases:
1. Minimum positive and maximum positive
2. Minimum positive and maximum negative
3. Minimum negative and maximum positive
4. Minimum negative and maximum negative
*/  
