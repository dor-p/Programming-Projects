#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//sorting a list using Bubble Sort

int main()
{
    int i, temp, sorted;
    int amount = 10; // amount of items in the list
    int listy[amount];

    for(i=0; i<amount; i++){
        listy[i] = ( rand()%25 )+1;
    }

    printf("original list\n"); // printing the original random list
    for(i=0; i<amount; i++){
        printf("%d \n",listy[i]);
    }
    while(1){      // Sorting using Bubble Sort

        sorted = 0;

        for(i=0; i<amount-1; i++)
        {

            if(listy[i]>listy[i+1])
            {
                temp = listy[i];
                listy[i] = listy[i+1];
                listy[i+1] = temp;
                sorted = 1;
            }
        }
            if(sorted == 0)
            {
                break;
            }

    }
        printf("Sorted list \n"); // Printing the sorted list
        for(i=0; i<amount; i++)
        {
            printf("%d \n", listy[i]);
        }

  return 0;
}
