/*!
* \file ex1.c
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date 30/11/2021
* \brief File containing necessary functions for ex1 (tp6)
*/

/*! Importation of librairies and headers*/
#include "ex1.h"
#include "utils.h"

/*!
* \fn void inversionTint1D(int tint_array[ARRAY_SIZE])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  30/11/2021
* \brief Invert one dimension array
* \param tint_array
*/
void inversionTint1D(int tint_array[ARRAY_SIZE])
{
    int int_tmp; // temporary for exchange values in array
    for (int i = 0; i < ARRAY_SIZE / 2; i++)
    {
        // exchange values in array
        int_tmp = tint_array[i];
        tint_array[i] = tint_array[ARRAY_SIZE - 1 - i];
        tint_array[ARRAY_SIZE - 1 - i] = int_tmp;
    }
}

/*!
* \fn void sumIntArray1D(int tint_array1[ARRAY_SIZE], int tint_array2[ARRAY_SIZE], int tint_sumArray[ARRAY_SIZE])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  30/11/2021
* \brief Complete sumTab with sum of array 1 and array 2
* \param tint_array1 // first array
* \param tint_array2 // second array
* \param tint_sumArray // sum of first array and second array
*/
void sumIntArray1D(int tint_array1[ARRAY_SIZE], int tint_array2[ARRAY_SIZE], int tint_sumArray[ARRAY_SIZE])
{
    // do sum 
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        tint_sumArray[i] = tint_array1[i] + tint_array2[i];
    }
}

/*!
* \fn int isTransverse(int tint_array[ARRAY_SIZE])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  30/11/2021
* \brief Search if an array is transverse
* \param tint_array // array
* \return 0 if array is not transverse, 1 if array is transverse
*/
int isTransverse(int tint_array[ARRAY_SIZE])
{
    int int_sum = 0; // sum of all values ​​in the array
    // do sum
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        int_sum += tint_array[i];
    }
    // 0 if array is not transverse, 1 if array is transverse
    return (tint_array[ARRAY_SIZE - 1] == int_sum);
}

/*!
* \fn int isPalindrome(char tchar_array[STR_LEN])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  30/11/2021
* \brief Find if a word or a sentence is a palindrome
* \param tchar_array // Word or sentence
* \return // 0 if is not a palindrome, 1 if is a palindrome
*/
int isPalindrome(char tchar_array[STR_LEN])
{
    int int_len = strlen(tchar_array); // size of the word or sentence
    int i = 0; // count
    int int_res = 1; // Stop variable for while

    while ( i < int_len/2 && int_res)
    {
        if (tchar_array[i] != tchar_array[int_len - 1 - i])
        {
            // not a palindrome
            return (0);
        }
        i++;
    }
    // palindrome
    return (1);
}

/*!
* \fn void inputArray(int tint_array[ARRAY_SIZE])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  06/12/2021
* \brief Ask for input in 1D array
* \param tint_array // array to initialize
*/
void inputArray(int tint_array[ARRAY_SIZE])
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("Input value %d : ", i + 1);
        tint_array[i] = inputInteger();
    }
}

/*!
* \fn void printArray1D(int tint_array[ARRAY_SIZE])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  06/12/2021
* \brief Display value of an integer 1D array
* \param tint_array // array
*/
void printArray1D(int tint_array[ARRAY_SIZE])
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("[%d]",tint_array[i]);
    }
    printf("\n");
}