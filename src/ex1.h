/*!
* \file ex1.h
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date 30/11/2021
* \brief File containing headers for ex1.c functions
*/

#if !defined(EX1_H)
#define EX1_H
#define ARRAY_SIZE 10
#define STR_LEN 99

/*! Import des librairies et Headers*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*!
* \fn void inversionTint1D(int* tint_array[ARRAY_SIZE])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  30/11/2021
* \brief Invert one dimension array
* \param tint_array
*/
void inversionTint1D(int tint_array[ARRAY_SIZE]);

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
void sumIntArray1D(int tint_array1[ARRAY_SIZE], int tint_array2[ARRAY_SIZE], int tint_sumArray[ARRAY_SIZE]);

/*!
* \fn int isTransverse(int tint_array[ARRAY_SIZE])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  30/11/2021
* \brief Search if an array is transverse
* \param tint_array // array
* \return 0 if array is not transverse, 1 if array is transverse
*/
int isTransverse(int tint_array[ARRAY_SIZE]);

/*!
* \fn int isPalindrome(char tchar_array[STR_LEN])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  30/11/2021
* \brief Find if a word or a sentence is a palindrome
* \param tchar_array // Word or sentence
* \return // 0 if is not a palindrome, 1 if is a palindrome
*/
int isPalindrome(char tchar_array[STR_LEN]);

/*!
* \fn void inputArray(int tint_array[ARRAY_SIZE])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  06/12/2021
* \brief Ask for input in 1D array
* \param tint_array // array to initialize
*/
void inputArray(int tint_array[ARRAY_SIZE]);

/*!
* \fn void printArray1D(int tint_array[ARRAY_SIZE])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  06/12/2021
* \brief Display value of an integer 1D array
* \param tint_array // array
*/
void printArray1D(int tint_array[ARRAY_SIZE]);

#endif // EX1_H