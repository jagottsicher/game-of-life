#include <stdio.h>
#include <math.h>

#include "myFunctions.h"


// Breite und Höhe des Arrays definieren
//#define WIDTH = 30;
//#define HEIGHT = 30;
int width = 100;
int height = 30;
int array1[100][30];
int array2[100][30];
int i;
int j;
int living_cells_around = 0;

int main()
{

// beide Arrays mit 0 füllen.
for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            array1[j][i] = 0;
            array2[j][i] = 0;
        }
    }


// Array1 in zwei geschachtelten for Schleifen mit zufällig mit 0 und 1 füllen
for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            array1[j][i] = returnRandom(0,1);
        }
    }


// main loop
 //   while (1)
//    {

// Ausgeabefunktion it array1 aufrufen: auf 1/1 setzen und ausgabe durch zwei for schleifen. 0 gibt ein leerzeichen aus, 1 gibt eine *
// auf Nullpunkt setzen
printf("\33[%d;%dH", 1, 1);

// printout one becomes *, zero becomes space. Linebreak after each line.
for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
        if (array1[j][i] == 1) 
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
for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
        // anzahl lebender nachbarn auf 0
        living_cells_around = 0;

        // rundum lebende nachbarn zählen, ränder werden ignoriert
        if (!(i-1) < 0 || (j-1) < 0 || (i+1) > width || (j+1) > height);
            {
            if (array1[j-1][i-1] == 1) 
                living_cells_around++;
            if (array1[j][i-1] == 1) 
                living_cells_around++;
            if (array1[j+1][i-1] == 1) 
                living_cells_around++;
            if (array1[j-1][i] == 1) 
                living_cells_around++;
            if (array1[j+1][i] == 1) 
                living_cells_around++;
            if (array1[j-1][i+1] == 1) 
                living_cells_around++;
            if (array1[j][i+1] == 1) 
                living_cells_around++;
            if (array1[j+1][i+1] == 1) 
                living_cells_around++;

            if (array1[j][i] == 1 && living_cells_around < 2) 
                array2[j][i] = 0;
            if (array1[j][i] == 1 && (living_cells_around == 2 || living_cells_around == 3)) 
                array2[j][i] = 1;
            if (array1[j][i] == 1 && living_cells_around > 3) 
                array2[j][i] = 0;
            if (array1[j][i] == 0 && living_cells_around == 3) 
                array2[j][i] = 1;
            } 
        }
    }


// Ausgeabefunktion it array2 aufrufen: auf 1/1 setzen und ausgabe durch zwei for schleifen. 0 gibt ein leerzeichen aus, 1 gibt eine *
// auf Nullpunkt setzen
// printf("\33[%d;%dH", 1, 1);

// printout one becomes *, zero becomes space. Linebreak after each line.
for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
        if (array2[j][i] == 1) 
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



/*





*/

return 0;

/*  
Dead code as a reminder of the rules
Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
Any live cell with more than three live neighbours dies, as if by overcrowding.
Any live cell with two or three live neighbours lives on to the next generation.
Any dead cell with exactly three live neighbours becomes a live cell.
*/

}
