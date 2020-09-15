#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "myFunctions.h"



int main()
{
    int userInputa = getNumberFromUser();
//    printEvenOrOdd(userInputa);
    srand(time(NULL));
    int random_number;

for (int i = 0; i < userInputa; ++i)
    {
        random_number = returnRandom(0,1);
        printf("%d\n", random_number);
    }

return 0;
}
