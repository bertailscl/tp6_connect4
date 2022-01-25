/*!
* \file main.c
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date 30/11/2021
* \brief Main file for tp6
*/


/*! Importation of librairies and headers*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "utils.h"
#include "ex1.h"
#include "connect4.h"

/*!
* \fn void menu()
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  17/11/2021
* \brief Program menu
*/
void menu()
{
    int int_nb; // integer
    int tint_array[ARRAY_SIZE];
    int tint_array2[ARRAY_SIZE];
    int tint_sumArray[ARRAY_SIZE];
    char tchar_string[STR_LEN];
    printf("################## MENU ##################\n");
    printf("#                                        #\n");
    printf("#   [1] : Invert array                   #\n");
    printf("#                                        #\n");
    printf("#   [2] : Sum arrays                     #\n");
    printf("#                                        #\n");
    printf("#   [3] : IsTransversible                #\n");
    printf("#                                        #\n");
    printf("#   [4] : IsPalindrome                   #\n");
    printf("#                                        #\n");
    printf("#   [5] : Connect 4 (easy)               #\n");
    printf("#                                        #\n");
    printf("#   [6] : Connect 4 (Medium)             #\n");
    printf("#                                        #\n");
    printf("#   [7] : Connect 4 (Hard)               #\n");
    printf("#                                        #\n");
    printf("#   [8] : Exit                           #\n");
    printf("#                                        #\n");
    printf("##########################################\n");
    printf("Select an option.\n");
    int_nb = inputInteger();

    switch (int_nb)
    {
        case 1:
            printf("\nYou chose to invert an array.\n");
            inputArray(tint_array);
            printf("Array :\n");
            printArray1D(tint_array);
            inversionTint1D(tint_array);
            printf("Inverted Array :\n");
            printArray1D(tint_array);
            break;
        
        case 2:
            printf("\nYou chose to sum two arrays.\n");
            printf("First array : \n");
            inputArray(tint_array);
            printf("Second array : \n");
            inputArray(tint_array2);
            sumIntArray1D(tint_array, tint_array2, tint_sumArray);
            printf("First array :\n");
            printArray1D(tint_array);
            printf("Second array :\n");
            printArray1D(tint_array2);
            printf("Sum array :\n");
            printArray1D(tint_sumArray);
            break;

        case 3:
            printf("\nYou chose to verify if an array is transversible.\n");
            inputArray(tint_array);
            if (isTransverse(tint_array))
            {
                printf("Array is transversible.\n");
            }else
            {
                printf("Array is not transversible.\n");
            }
            break;

        case 4:
            printf("You chose to verify if a string is a plindrome.\n");
            printf("Input a string : ");
            scanf("%s", tchar_string);
            if (isPalindrome(tchar_string))
            {
                printf("%s is a palindrome.\n", tchar_string);
            }else
            {
                printf("%s is not a palindrome.\n", tchar_string);
            }
            break;

        case 5:
            play(0);
            break;

        case 6:
            play(1);
            break;

        case 7:
            play(2);
            break;

        case 8:
            printf("\nYou chose to exit.\n");
            exit(EXIT_SUCCESS);
            break;

        default:
            printf("\nError, next time input a correct value.\n");
            exit(ERROR_MESSAGE("Input Error."));
            break;
    }
}

/*!
* \fn int main(int argc, char** argv)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date 30/11/2021
* \brief Main function of the program
* \param argc number of arguments given as inputs
* \param argv value of arguments given as inputs
* \return 0 if all went good
*/
int main(int argc, char** argv)
{
    srand(time(NULL));
    int argv1; // argv convert in integer
    int tint_array[ARRAY_SIZE];
    int tint_array2[ARRAY_SIZE];
    int tint_sumArray[ARRAY_SIZE];
    char tchar_string[STR_LEN];
    if (argc > 1)
    {
        sscanf(argv[1], "%d", &argv1);
        switch (argv1)
        {
            case 1:
                printf("\nYou chose to invert an array.\n");
                inputArray(tint_array);
                printf("Array :\n");
                printArray1D(tint_array);
                inversionTint1D(tint_array);
                printf("Inverted Array :\n");
                printArray1D(tint_array);
                break;
        
            case 2:
                printf("\nYou chose to sum two arrays.\n");
                inputArray(tint_array);
                inputArray(tint_array2);
                sumIntArray1D(tint_array, tint_array2, tint_sumArray);
                printf("First array :\n");
                printArray1D(tint_array);
                printf("Second array :\n");
                printArray1D(tint_array2);
                printf("Sum array :\n");
                printArray1D(tint_sumArray);
                break;

            case 3:
                printf("\nYou chose to verify if an array is transversible.\n");
                inputArray(tint_array);
                if (isTransverse(tint_array))
                {
                    printf("Array is transversible.\n");
                }else
                {
                    printf("Array is not transversible.\n");
                }
                break;

            case 4:
                printf("You chose to verify if a string is a plindrome");
                scanf("%s", tchar_string);
                if (isPalindrome(tchar_string))
                {
                    printf("%s is a palindrome.\n", tchar_string);
                }else
                {
                    printf("%s is not a palindrome.\n", tchar_string);
                }
                break;

            case 5:
                play(0);
                break;

            case 6:
                play(1);
                break;

            case 7:
                play(2);
                break;

            default:
                menu();
                break;
        }
    } else
    {
        menu();
    }
    return (EXIT_SUCCESS);
}