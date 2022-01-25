/*!
* \file utils.c
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date 23/11/2021
* \brief File containing utilitaries functions
*/


/*! Importation of librairies and headers*/
#include "utils.h"

/*!
* \fn void clearBuffer()
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  17/11/2021
* \brief clear buffer
*/
void clearBuffer()
{
    int int_c; // select first caractere on buffer
    // clear buffer
    do
    {
        int_c = getchar();
    } while (int_c != EOF && int_c != '\n');
}

/*!
* \fn int inputInteger()
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  17/11/2021
* \brief secure integer entry
* \return Integer
*/
int inputInteger()
{
    int int_res; // input integer
    // ask again if entered is not an integer or float
    while (!scanf("%d", &int_res))
    {
        // clear the buffer if entered is not an integer or float
        clearBuffer();
        printf("Input error : input is not an integer.\nPlease retry : ");
    }
    // clear buffer if entered is a float
    clearBuffer();
    return (int_res);
}