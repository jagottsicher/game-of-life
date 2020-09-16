#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "myFunctions.h"


/*
int main()
{
    int userInputa = getNumberFromUser();
// goto upper left corner
    printf("\33[%d;%dH", 1, 1);
//    printEvenOrOdd(userInputa);
    srand(time(NULL));
    int random_number;

for (int i = 0; i < userInputa; ++i)
    {
        random_number = returnRandom(0,1);
        printf("%d\n", random_number);
    }
*/



// Breite und Höhe des Arrays definieren

//#define WIDTH = 30;
//#define HEIGHT = 30;
int width = 30;
int height = 30;
int array1[30][30];
int array2[30][30];
int i;
int j;
int living_cells_around = 0;

int main()
{
// beide Arrays mit 0 füllen.
for (i = 1; i < width; i++)
    {
        for (j = 1; j < height; j++)
        {
            array1[i][j] = 0;
            array2[i][j] = 0;
        }
    }

/*

// Array1 in zwei geschachtelten for Schleifen mit zufällig mit 0 und 1 füllen
for (i = 1; i < width; i++)
    {
        for (j = 1; j < height; j++)
        {
            array1[i][j] = returnRandom(0,1);
        }
    }

// main loop

while (1)
{
//    Ausgeabefunktion it array1 aufrufen: auf 1/1 setzen und ausgabe durch zwei for schleifen. 0 gibt ein leerzeichen aus, 1 gibt eine *
// auf Nullpunkt setzen
printf("\33[%d;%dH", 1, 1);

// printout one becomes *, zero becomes space. Linebreak after each line.
for (i = 1; i < width; i++)
    {
        for (j = 1; j < height; j++)
        {
        If (array1[i][j] == 1) 
            {
            printf("*");
            }
            else
            {
            printf(" ");
            }
        }
        printf("\n");    
    }

//    array2 in zwei geschachtelten schleifen entlangehen und nach regel befüllen
for (i = 1; i < width; i++)
    {
        for (j = 1; j < height; j++)
        {
        // anzahl lebender nachbarn auf 0
        living_cells_around = 0;

        // rundum lebende nachbarn zählen, ränder werden ignoriert
        if !(i-1 < 0 || j-1 < 0 || i+1 > width || j+1 > height)
        {
        if (array1[i-1][j-1]) == 1 
            living_cells_around++;
        if (array1[i][j-1]) == 1 
            living_cells_around++;
        if (array1[i+1][j-1]) == 1 
            living_cells_around++;
        if (array1[i-1][j]) == 1 
            living_cells_around++;
        if (array1[i+1][j]) == 1 
            living_cells_around++;
        if (array1[i-1][j+1]) == 1 
            living_cells_around++;
        if (array1[i][j+1]) == 1 
            living_cells_around++;
        if (array1[i+1][j+1]) == 1 
            living_cells_around++;
        } 

        // wenn zelle in array1 an xy lebendig dann
        // wenn anzahl lebender nachbarn < 2 dann zelle xy in array2 auf 0
        // wenn anzahl lebender nachbarn = 2 oder anzahl lebender Zellen = 3 dann zelle xy in array2 auf 1
        // wenn anzahl lebender nachbarn > 3 dann zelle xy in array2 auf 0
        // else
        // if anzahl lebender nachbarn = 3 dann zelle xy in array2 auf 1
        }
    }

//    Ausgeabefunktion mit array2 aufrufen: auf 1/1 setzen und ausgabe durch zwei for schleifen. 0 gibt ein leerzeichen aus, 1 gibt eine *

//    array1 in zwei geschachtelten schleifen entlangehen und nach regel befüllen

}
*/


/*
    Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
    Any live cell with more than three live neighbours dies, as if by overcrowding.
    Any live cell with two or three live neighbours lives on to the next generation.
    Any dead cell with exactly three live neighbours becomes a live cell.




*/

return 0;
}
