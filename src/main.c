#include <stdio.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

#include "myFunctions.h"


// Breite und Höhe des Arrays definieren
//#define WIDTH = 30;
//#define HEIGHT = 30;
int width = 200;
int height = 50;
int array1[200][50];
int array2[200][50];
// int array3[200][50];
int i;
int j;
int living_cells_around = 0;
int go_on = 1;
int generation_counter = 0;
// int not_same = 1;


int main()
{

// drei Arrays mit 0 füllen.
for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            array1[j][i] = 0;
            array2[j][i] = 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
            // array3[j][i] = 0;
        }
    }


// Array1 in zwei geschachtelten for Schleifen mit zufällig mit 0 und 1 füllen
srand(time(NULL)); 
for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            array1[j][i] = returnRandom(0,1);
        }
    }

// main loop
while (go_on)
{

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
usleep (100000); 

//    array2 in zwei geschachtelten schleifen entlangehen und nach regel befüllen
for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
        // anzahl lebender nachbarn auf 0
        living_cells_around = 0;

        // rundum lebende nachbarn zählen, ränder werden ignoriert
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

//            printf("%d ",living_cells_around); 

            if (array1[j][i] == 1)
            {
                if (living_cells_around < 2)
                    array2[j][i] = 0;
                if (living_cells_around > 3)
                    array2[j][i] = 0;
                if ((living_cells_around == 2) || (living_cells_around == 3))
                    array2[j][i] = 1;
            } 
            else
            {
                array2[j][i] = 0;
            }
            
            if (array1[j][i] == 0)
            {
                if (living_cells_around == 3)
                    array2[j][i] = 1;
            }
            
            // copy each element of array1 in array3  
            // array3[j][i] = array1[j][i];
        }
    }

generation_counter++;
printf("Generation #%d\n", generation_counter);

// Ausgeabefunktion it array2 aufrufen: auf 1/1 setzen und ausgabe durch zwei for schleifen. 0 gibt ein leerzeichen aus, 1 gibt eine *
// auf Nullpunkt setzen
printf("\33[%d;%dH", 1, 1);

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

usleep (100000); 


//    array1 in zwei geschachtelten schleifen entlangehen und nach regel befüllen
for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
        // anzahl lebender nachbarn auf 0
        living_cells_around = 0;

        // rundum lebende nachbarn zählen, ränder werden ignoriert
            if (array2[j-1][i-1] == 1) 
                living_cells_around++;
            if (array2[j][i-1] == 1) 
                living_cells_around++;
            if (array2[j+1][i-1] == 1) 
                living_cells_around++;
            if (array2[j-1][i] == 1) 
                living_cells_around++;
            if (array2[j+1][i] == 1) 
                living_cells_around++;
            if (array2[j-1][i+1] == 1) 
                living_cells_around++;
            if (array2[j][i+1] == 1) 
                living_cells_around++;
            if (array2[j+1][i+1] == 1) 
                living_cells_around++;

            if (array2[j][i] == 1)
            {
                if (living_cells_around < 2)
                    array1[j][i] = 0;
                if (living_cells_around > 3)
                    array1[j][i] = 0;
                if ((living_cells_around == 2) || (living_cells_around == 3))
                    array1[j][i] = 1;
            } 
            else
            {
                array1[j][i] = 0;
            }
            
            if (array2[j][i] == 0)
            {
                if (living_cells_around == 3)
                    array1[j][i] = 1;
            }
            
            // check if xy identical with last round's copy of array 1 before changing matrix 1
            // not_same = 0;
            // if (array1[j][i] != array3[j][i])
            // not_same = 1;
        }
    }

// if (not_same = 1)
generation_counter++;
printf("Generation #%d\n", generation_counter);
// go_on = getNumberFromUser();

} //End while loop

return 0;

/*  
Dead code as a reminder of the rules
Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
Any live cell with more than three live neighbours dies, as if by overcrowding.
Any live cell with two or three live neighbours lives on to the next generation.
Any dead cell with exactly three live neighbours becomes a live cell.
*/

}
