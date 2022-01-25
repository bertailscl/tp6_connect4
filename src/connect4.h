/*!
* \file puissance4.h
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date 30/11/2021
* \brief file containing headers for connect4.c functions
*/

#if !defined(PUISSANCE4_H)
#define PUISSANCE4_H
#define BOARD_SIZE 7

/*! Importation of librairies and headers*/
#include <stdio.h>
#include <stdlib.h>

/*!
* \fn void initBoard(int ttint_board[BOARD_SIZE][BOARD_SIZE])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  30/11/2021
* \brief Initializes board game
* \param ttint_board // board
*/
void initBoard(int ttint_board[BOARD_SIZE][BOARD_SIZE]);

/*!
* \fn void displayBoard(int ttint_board[BOARD_SIZE][BOARD_SIZE])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  30/11/2021
* \brief Display board game
* \param ttint_board // board
*/
void displayBoard(int ttint_board[BOARD_SIZE][BOARD_SIZE]);

/*!
* \fn void play()
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  01/12/2021
* \brief Game connect 4
*/
void play();

/*!
* \fn int checkColumns(int ttint_board[BOARD_SIZE][BOARD_SIZE], int int_player)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  01/12/2021
* \brief Check if player win on one or more column
* \param ttint_board // game board
* \param int_player // player who is check
* \return 1 if win on a column, 0 else
*/
int checkColumns(int ttint_board[BOARD_SIZE][BOARD_SIZE], int int_player);

/*!
* \fn int checkLines(int ttint_board[BOARD_SIZE][BOARD_SIZE], int int_player)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  01/12/2021
* \brief Check if player win on one or more line
* \param ttint_board // game board
* \param int_player // player who is check
* \return 1 if win on a line, 0 else
*/
int checkLines(int ttint_board[BOARD_SIZE][BOARD_SIZE], int int_player);

/*!
* \fn int checkDiagonals(int ttint_board[BOARD_SIZE][BOARD_SIZE], int int_player)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  01/12/2021
* \brief Check if player win on one or more diagonals from top left to down right
* \param ttint_board // game board
* \param int_player // player who is check
* \return 1 if win on a diagonal, 0 else
*/
int checkRightDiagonals(int ttint_board[BOARD_SIZE][BOARD_SIZE], int int_player);

/*!
* \fn int checkDiagonals(int ttint_board[BOARD_SIZE][BOARD_SIZE], int int_player)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  01/12/2021
* \brief Check if player win on one or more diagonals from top right to down left
* \param ttint_board // game board
* \param int_player // player who is check
* \return 1 if win on a diagonal, 0 else
*/
int checkLeftDiagonals(int ttint_board[BOARD_SIZE][BOARD_SIZE], int int_player);

/*!
* \fn int isWin(int ttint_board[BOARD_SIZE][BOARD_SIZE])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  01/12/2021
* \brief Determine if one player win or not
* \param ttint_board // game board
* \return -1 if no-one win, 0 if draw, 1 if player 1 win, 2 if player 2 win
*/
int isWin(int ttint_board[BOARD_SIZE][BOARD_SIZE]);

/*!
* \fn void placePieces(int ttint_board[BOARD_SIZE][BOARD_SIZE], int int_player)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  01/12/2021
* \brief 
* \remarks None
* \param ttint_board 
* \param int_player 
*/
void placePieces(int ttint_board[BOARD_SIZE][BOARD_SIZE], int int_player);

/*!
* \fn int boardFull(int ttint_board[BOARD_SIZE][BOARD_SIZE])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  02/12/2021
* \brief Check if game board is full
* \param ttint_board // game board
* \return 1 if board is full, 0 else
*/
int boardFull(int ttint_board[BOARD_SIZE][BOARD_SIZE]);

/*!
* \fn void turnBoard(int ttint_board[BOARD_SIZE][BOARD_SIZE], int int_sense)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  03/12/2021
* \brief Turn game board in clockwise or counterclockwise, depending on user input
* \param ttint_board // game board
* \param int_sense // sense to turn
*/
void turnBoard(int ttint_board[BOARD_SIZE][BOARD_SIZE], int int_sense);

/*!
* \fn void turnRight(int ttint_board[BOARD_SIZE][BOARD_SIZE])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  03/12/2021
* \brief Turn game board in clockwise and apply gravity
* \param ttint_board // game board
*/
void turnRight(int ttint_board[BOARD_SIZE][BOARD_SIZE]);

/*!
* \fn void turnLeft(int ttint_board[BOARD_SIZE][BOARD_SIZE])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  03/12/2021
* \brief Turn game board in counterClockwise and apply gravity
* \param ttint_board // game board
*/
void turnLeft(int ttint_board[BOARD_SIZE][BOARD_SIZE]);

/*!
* \fn void gravity(int ttint_board[BOARD_SIZE][BOARD_SIZE])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  03/12/2021
* \brief Apply gravity on game board
* \param ttint_board // game board
*/
void gravity(int ttint_board[BOARD_SIZE][BOARD_SIZE]);

/*!
* \fn void copy2DIntStaticArray(int toCopyArray[BOARD_SIZE][BOARD_SIZE], int copyArray[BOARD_SIZE][BOARD_SIZE])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  03/12/2021
* \brief Copy toCopyArray to copyArray
* \param toCopyArray // array 2D static to copy
* \param copyArray // copy of toCopyArray
*/
void copy2DIntStaticArray(int toCopyArray[BOARD_SIZE][BOARD_SIZE], int copyArray[BOARD_SIZE][BOARD_SIZE]);

/*!
* \fn void askRotate(int ttint_board[BOARD_SIZE][BOARD_SIZE], int int_difficulty)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  03/12/2021
* \brief // ask player if he want to rotate the grid
* \param ttint_board // game board
* \param int_difficulty // difficulty of the game
*/
void askRotate(int ttint_board[BOARD_SIZE][BOARD_SIZE], int int_difficulty);

#endif // PUISSANCE4_H