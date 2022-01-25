/*!
* \file connect4.c
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date 30/11/2021
* \brief File containing necessary functions for connect4 (tp6)
*/

/*! Importation of librairies and headers*/
#include "connect4.h"
#include "utils.h"

/*!
* \fn void initBoard(int ttint_board[BOARD_SIZE][BOARD_SIZE])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  30/11/2021
* \brief Initializes board game
* \param ttint_board // board
*/
void initBoard(int ttint_board[BOARD_SIZE][BOARD_SIZE])
{
    // for all cases initialize to -1
    for (int i = 0; i < BOARD_SIZE; i++) // columns
    {
        for (int j = 0; j < BOARD_SIZE; j++) // lines
        {
            ttint_board[i][j] = -1;
        }
    }
}

/*!
* \fn void displayBoard(int ttint_board[BOARD_SIZE][BOARD_SIZE])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  30/11/2021
* \brief Display board game
* \param ttint_board // board
*/
void displayBoard(int ttint_board[BOARD_SIZE][BOARD_SIZE])
{
    printf(" ");
    for (int i = 0; i < BOARD_SIZE; i++) // line 1
    {
        printf(" %d  ",i+1);
    }
    printf("\n╔");
    for (int i = 0; i < BOARD_SIZE; i++) // line 2
    {
        printf("═══");
        if (i < BOARD_SIZE - 1)
        {
            printf("╦");
        }
    }
    printf("╗\n");
    printf("║");
    for (int i = 0; i < BOARD_SIZE; i++) // lines
    { 
        for (int j = 0; j < BOARD_SIZE; j++) // columns
        {
            switch (ttint_board[i][j])
            {
            case -1:
                printf("   ║");
                break;
            
            case 1:
                printf(" \e[31m●\e[0m ║");
                break;
            
            case 2:
                printf(" \e[33m●\e[0m ║");
                break;

            default:
                exit(ERROR_MESSAGE("Incorrect value on board."));
                break;
            }
        }
        if (i < BOARD_SIZE - 1)
        {
            printf("\n╠");
            for (int i = 0; i < BOARD_SIZE; i++)
            {
                printf("═══");
                if (i < BOARD_SIZE - 1)
                {
                    printf("╬");
                }
            }
            printf("╣\n║");
        }
    }
    
    printf("\n╚");
    for (int i = 0; i < BOARD_SIZE; i++) // last line
    {
        printf("═══");
        if (i < BOARD_SIZE - 1)
        {
            printf("╩");
        }
    }
    printf("╝\n");
}

/*!
* \fn void play(int int_difficulty)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  01/12/2021
* \brief Game connect 4
* \param int_difficulty // difficulty of the game
*/
void play(int int_difficulty)
{
    int int_game = 1; // While 1 continue game
    int int_player = 0; // player who is playing
    int int_win = -1; // variable whih say if someone win or not
    int ttint_board[BOARD_SIZE][BOARD_SIZE]; // declare board
    int int_turnPossibilityP1; // how many time players 1 can rotate game board
    int int_turnPossibilityP2; // how many time players 2 can rotate game board

    if (int_difficulty == 1)
    {
        printf("How many rotations do you wants per player ? ");
        int_turnPossibilityP1 = inputInteger();
        int_turnPossibilityP2 = int_turnPossibilityP1;
    }
    // initialize board
    initBoard(ttint_board); 
    // start game
    while (int_game)
    {
        // clear terminal
        system("clear");
        // display board
        displayBoard(ttint_board);
        printf("Player %d's turn.\n", int_player+1);
        // player play
        placePieces(ttint_board, int_player);
        // continue or stop playing
        int_win = isWin(ttint_board);
        if (int_win != -1)
        {
            // stop playing
            int_game = 0;
        }
        // rotation (bonus)
        if (((int_difficulty == 1 && ((int_player == 0 && int_turnPossibilityP1 > 0) || (int_player == 1 && int_turnPossibilityP2 > 0))) || int_difficulty == 2) && int_game)
        {
            system("clear");
            displayBoard(ttint_board);
            printf("Player %d's turn.\n", int_player+1);
            askRotate(ttint_board, int_difficulty);
            int_win = isWin(ttint_board);
            if (int_win != -1)
            {
                // stop playing
                int_game = 0;
            }
        }
        if (int_game)
        {   
            // continue playing : other player
            int_player = (int_player + 1) % 2;
        }
    }
    system("clear");
    switch (int_win)
    {
    //draw
    case 0:
        displayBoard(ttint_board);
        printf("Draw, no-one wins!");
        break;

    // player win
    default:
        displayBoard(ttint_board);
        printf("Player %d win !!!\n", int_player+1);
        break;
    }
}

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
int checkColumns(int ttint_board[BOARD_SIZE][BOARD_SIZE], int int_player)
{
    int count; // number of consecutive pieces

    for (int i = 0; i < BOARD_SIZE; i++) // lines
    {
        count = 0;
        for (int j = 0; j < BOARD_SIZE; j++) // columns
        {
            if (ttint_board[j][i] == int_player)
            {
                // add one consecutive piece
                count++;
            }
            else
            {
                // not the same piece
                count = 0;
            }
            if (count == 4)
            {
                // connect 4 !
                return 1;
            }
        }
    }
    // not connect 4 !
    return (0);
}

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
int checkLines(int ttint_board[BOARD_SIZE][BOARD_SIZE], int int_player)
{
    int count; // number of consecutive pieces

    for (int i = 0; i < BOARD_SIZE; i++) // lines
    {
        count = 0;
        for (int j = 0; j < BOARD_SIZE; j++) // columns
        {
            if (ttint_board[i][j] == int_player)
            {
                // add one consecutive piece
                count++;
            }
            else
            {
                // not the same piece
                count = 0;
            }
            if (count == 4)
            {
                // connect 4 !
                return 1;
            }
        }
    }
    // not connect 4 !
    return (0);
}

/*!
* \fn int checkRightDiagonals(int ttint_board[BOARD_SIZE][BOARD_SIZE], int int_player)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  01/12/2021
* \brief Check if player win on one or more diagonals from top left to down right
* \param ttint_board // game board
* \param int_player // player who is check
* \return 1 if win on a diagonal, 0 else
*/
int checkRightDiagonals(int ttint_board[BOARD_SIZE][BOARD_SIZE], int int_player)
{
    int count; // number of consecutive pieces
    int j; // loop iteration

    // middle diagonal and all underneath
    for (int k = 0; k < BOARD_SIZE - 3; k++)
    {
        j = 0;
        count = 0;
        for (int i = k; i < BOARD_SIZE; i++) // lines
        {
            if (ttint_board[i][j] == int_player)
            {
                // add one consecutive piece
                count++;
            }
            else
            {
                // not the same piece
                count = 0;
            }
            if (count == 4)
            {
                // connect 4 !
                return 1;
            }
            j++;
        }
    }
    // diagonals above middle diagonal
    for (int k = 1; k < BOARD_SIZE - 3; k++)
    {
        j = 0;
        count = 0;
        for (int i = k; i < BOARD_SIZE; i++) // columns
        {
            if (ttint_board[j][i] == int_player)
            {
                // add one consecutive piece
                count++;
            }
            else
            {
                // not the same piece
                count = 0;
            }
            if (count == 4)
            {
                // connect 4 !
                return 1;
            }
            j++;
        }
    }
    // not connect 4 !
    return (0);
}

/*!
* \fn int checkLeftDiagonals(int ttint_board[BOARD_SIZE][BOARD_SIZE], int int_player)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  01/12/2021
* \brief Check if player win on one or more diagonals from top right to down left
* \param ttint_board // game board
* \param int_player // player who is check
* \return 1 if win on a diagonal, 0 else
*/
int checkLeftDiagonals(int ttint_board[BOARD_SIZE][BOARD_SIZE], int int_player)
{
    int count; // number of consecutive pieces
    int j; // loop iteration

    // middle diagonal and all underneath
    for (int k = 0; k < BOARD_SIZE - 3; k++)
    {
        j = BOARD_SIZE;
        count = 0;
        for (int i = k; i > BOARD_SIZE; i++) // column
        {
            if (ttint_board[j][i] == int_player)
            {
                // add one consecutive piece
                count++;
            }
            else
            {
                // not the same piece
                count = 0;
            }
            if (count == 4)
            {
                // connect 4 !
                return 1;
            }
            j--;
        }
    }
    // diagonals above middle diagonal
    for (int k = BOARD_SIZE - 1; k > 2; k--)
    {
        j = 0;
        count = 0;
        for (int i = k; i > -1; i--) // column
        {
            if (ttint_board[i][j] == int_player)
            {
                // add one consecutive piece
                count++;
            }
            else
            {
                // not the same piece
                count = 0;
            }
            if (count == 4)
            {
                // connect 4 !
                return 1;
            }
            j++;
        }
    }
    // not connect 4 !
    return (0);
}

/*!
* \fn int isWin(int ttint_board[BOARD_SIZE][BOARD_SIZE])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  01/12/2021
* \brief Determine if one player win or not
* \param ttint_board // game board
* \return -1 if no-one win, 0 if draw, 1 if player 1 win, 2 if player 2 win
*/
int isWin(int ttint_board[BOARD_SIZE][BOARD_SIZE])
{
    int int_res1 = 0; // if 1 player 1 win else not yet win
    int int_res2 = 0; // if 1 player 2 win else not yet win

    if (checkColumns(ttint_board, 1) || checkLines(ttint_board, 1) || checkRightDiagonals(ttint_board, 1) || checkLeftDiagonals(ttint_board, 1))
    {
        // player 1 win
        int_res1 = 1;
    }
    if (checkColumns(ttint_board, 2) || checkLines(ttint_board, 2) || checkRightDiagonals(ttint_board, 2) || checkLeftDiagonals(ttint_board, 2))
    {
        // player 2 win
        int_res2 = 1;
    }
    if (int_res1 && int_res2)
    {
        return (0);
    }
    else if (int_res1)
    {
        // player 1 win
        return (1);
    }
    else if (int_res2)
    {
        // player 2 win
        return (2);
    }
    else if (boardFull(ttint_board))
    {
        return (0);
    }
    else
    {
        // not connect 4 !
        return (-1);
    }
}

/*!
* \fn void placePieces(int ttint_board[BOARD_SIZE][BOARD_SIZE], int int_player)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  01/12/2021
* \brief Place piece on a chosen column
* \param ttint_board // game board
* \param int_player // player who place the piece
*/
void placePieces(int ttint_board[BOARD_SIZE][BOARD_SIZE], int int_player)
{
    int int_placed = 0; // piece is in a good column
    int int_column; // column choose by player
    int i; // loop iterator
    printf("Choose a column : ");
    while (!int_placed) // while int_placed == 0
    {
        int_column = inputInteger(); // input integer
        // integer not in the width of the board
        while (int_column > BOARD_SIZE || int_column < 1)
        {
            printf("Chosen value is not a column on the board.\nPlease retry : ");
            int_column = inputInteger();
        }
        // look for where to put the pawn
        i = BOARD_SIZE - 1;
        while (i > -1 && int_placed == 0)
        {
            // empty case
            if (ttint_board[i][int_column - 1] == -1)
            {
                ttint_board[i][int_column - 1] = int_player + 1;
                int_placed = 1;
            }
            i--;
        }
        if (!int_placed)
        {
            printf("Chosen column is full, you are not able to put a piece here.\nPlease chose an other column : ");
        }
    }
}

/*!
* \fn int boardFull(int ttint_board[BOARD_SIZE][BOARD_SIZE])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  02/12/2021
* \brief Check if game board is full
* \param ttint_board // game board
* \return 1 if board is full, 0 else
*/
int boardFull(int ttint_board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++) // lines
    {
        for (int j = 0; j < BOARD_SIZE; j++) // columns
        {
            if (ttint_board[i][j] == -1)
            {
                return (0);
            }
        }
    }
    return (1);
}

/*!
* \fn void turnBoard(int ttint_board[BOARD_SIZE][BOARD_SIZE], int int_sense)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  03/12/2021
* \brief Turn game board in clockwise or counterclockwise, depending on user input
* \param ttint_board // game board
* \param int_sense // sense to turn
*/
void turnBoard(int ttint_board[BOARD_SIZE][BOARD_SIZE], int int_sense)
{
    switch (int_sense)
    {
    case 0:
        break;

    case 1:
        turnRight(ttint_board);
        break;
    
    case 2:
        turnLeft(ttint_board);
        break;
    
    default:
        exit(ERROR_MESSAGE("Error, impossible to turn the board.\n"));
        break;
    }
}

/*!
* \fn void turnRight(int ttint_board[BOARD_SIZE][BOARD_SIZE])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  03/12/2021
* \brief Turn game board in clockwise and apply gravity
* \param ttint_board // game board
*/
void turnRight(int ttint_board[BOARD_SIZE][BOARD_SIZE])
{
    int ttint_turnBoard[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) // lines
    {
        for (int j = 0; j < BOARD_SIZE; j++) // columns
        {
            ttint_turnBoard[j][BOARD_SIZE - 1 - i] = ttint_board[i][j];
        }
    }
    copy2DIntStaticArray(ttint_turnBoard, ttint_board);
    gravity(ttint_board);
}

/*!
* \fn void turnLeft(int ttint_board[BOARD_SIZE][BOARD_SIZE])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  03/12/2021
* \brief Turn game board in counterClockwise and apply gravity
* \param ttint_board // game board
*/
void turnLeft(int ttint_board[BOARD_SIZE][BOARD_SIZE])
{
    int ttint_turnBoard[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) // lines
    {
        for (int j = 0; j < BOARD_SIZE; j++) // columns
        {
            ttint_turnBoard[BOARD_SIZE - 1 - j][i] = ttint_board[i][j];
        }
    }
    copy2DIntStaticArray(ttint_turnBoard, ttint_board);
    gravity(ttint_board);
}

/*!
* \fn void gravity(int ttint_board[BOARD_SIZE][BOARD_SIZE])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  03/12/2021
* \brief Apply gravity on game board
* \param ttint_board // game board
*/
void gravity(int ttint_board[BOARD_SIZE][BOARD_SIZE])
{
    int int_tmp; // tmp var for exchange
    int int_placed; // 0 == piece not placed, 1 = piece placed
    int k; // loop iteration

    for (int j = 0; j < BOARD_SIZE; j++) // columns
    {
        for (int i = BOARD_SIZE - 1; i > -1; i--) // lines
        {
            int_placed = 0;
            if (ttint_board[i][j] != -1)
            {
                int_tmp = ttint_board[i][j];
                // look for where to put the pawn
                k = BOARD_SIZE - 1;
                while (k > -1 && int_placed == 0)
                {
                    // empty case
                    if (ttint_board[k][j] == -1)
                    {
                        ttint_board[i][j] = -1;
                        ttint_board[k][j] = int_tmp;
                        int_placed = 1;
                    }
                    k--;
                }
            }
        }
    }
}

/*!
* \fn void copy2DIntStaticArray(int toCopyArray[BOARD_SIZE][BOARD_SIZE], int copyArray[BOARD_SIZE][BOARD_SIZE])
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  03/12/2021
* \brief Copy toCopyArray to copyArray
* \param toCopyArray // array 2D static to copy
* \param copyArray // copy of toCopyArray
*/
void copy2DIntStaticArray(int toCopyArray[BOARD_SIZE][BOARD_SIZE], int copyArray[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++) // lines
    {
        for (int j = 0; j < BOARD_SIZE; j++) // columns
        {
            // copy case
            copyArray[i][j] = toCopyArray[i][j];
        }
    }
}

/*!
* \fn void askRotate(int ttint_board[BOARD_SIZE][BOARD_SIZE], int int_difficulty)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  03/12/2021
* \brief // ask player if he want to rotate the grid
* \param ttint_board // game board
* \param int_difficulty // difficulty of the game
*/
void askRotate(int ttint_board[BOARD_SIZE][BOARD_SIZE], int int_difficulty)
{
    int int_rotate = 0; // 0 dont rotate, 1 = rotateLeft, 2 = rotateRight
    switch (int_difficulty)
    {
    case 1:
        printf("Input 1 if you want rotate the grid, 0 else : ");
        int_rotate = inputInteger(); 
        // integer = 0 || = 1
        while (int_rotate > 1 || int_rotate < 0)
        {
            printf("Chosen value is not 0 or 1.\nPlease retry : ");
            int_rotate = inputInteger();
        }
        break;

    case 2:
        printf("Input 1  if you want rotate the grid clockwise.\nInput 2 if you want rotate the grid counterclockwise.\nInput 0 if you won't rotate the grid. \n");
        int_rotate = inputInteger(); 
        // integer = 0 || = 1 || = 2
        while (int_rotate > 2 || int_rotate < 0)
        {
            printf("Chosen value is not 0, 1 or 2.\nPlease retry : ");
            int_rotate = inputInteger();
        }
        break;

    default:
        break;
    }
    if (int_rotate || (int_rotate == 2))
    {
        turnBoard(ttint_board, int_rotate);
    }
}