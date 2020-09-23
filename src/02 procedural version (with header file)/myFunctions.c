#include <stdio.h>
#include <stdlib.h>

#include "myFunctions.h"

// Definition
int getNumberFromUser()
{
    int number_from_user; 

    printf("Please enter an interger number!\n");
    scanf("%d", &number_from_user);

    return number_from_user; 
}

// Definition
int pressAnyKey()
{
    int input_key; 

    printf("press any key\n");
    scanf(" %c", &input_key);
    
    return atoi(input_key); 
}

// Definition
int returnRandom(int lower, int upper) 
{
    int num = (rand() % (upper - lower + 1)) + lower; 

    return num; 
}
