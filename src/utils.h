/*!
* \file utils.h
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date 23/11/2021
* \brief file containing headers for utils.c functions
*/


#ifndef UTILS_H
#define UTILS_H
#define ERROR_MESSAGE(message) fprintf(stderr, "%s\n",message)

/*! Importation of librairies and headers*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <string.h>

/*!
* \fn void clearBuffer()
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  17/11/2021
* \brief clear buffer
*/
void clearBuffer();

/*!
* \fn int inputInteger()
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  17/11/2021
* \brief secure integer entry
* \return Integer
*/
int inputInteger();

#endif // !UTILS_H