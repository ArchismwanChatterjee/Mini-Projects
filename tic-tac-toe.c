#include <stdio.h>
#include <stdlib.h>

char board[3][3];
char mark;

void initializeBoard()
{
    for (int i = 0; i < 3; i = i + 1)
    {
        for (int j = 0; j < 3; j = j + 1)
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard()
{
    printf(" %c|%c|%c\n", board[0][0], board[0][1], board[0][2]);
    printf(" -+-+-\n");
    printf(" %c|%c|%c\n", board[1][0], board[1][1], board[1][2]);
    printf(" -+-+-\n");
    printf(" %c|%c|%c\n", board[2][0], board[2][1], board[2][2]);
}

int checkLine(char c1, char c2, char c3)
{
    return (c1 != ' ' && c1 == c2 && c2 == c3);
}

int checkWinner()
{
    // check rows
    for (int i = 0; i < 3; i = i + 1)
    {
        if (checkLine(board[i][0], board[i][1], board[i][2]))
        {
            return 1;
        }
    }
    // check columns
    for (int i = 0; i < 3; i = i + 1)
    {
        if (checkLine(board[0][i], board[1][i], board[2][i]))
        {
            return 1;
        }
    }
    // check diagonals
    if (checkLine(board[0][0], board[1][1], board[2][2]) || checkLine(board[0][2], board[1][1], board[2][0]))
    {
        return 1;
    }
    return 0;
}

int isBoardFull()
{
    for (int i = 0; i < 3; i = i + 1)
    {
        for (int j = 0; j < 3; j = j + 1)
        {
            if (board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int player = 1, rows, cols;
    initializeBoard();
    int n=1;
    while (1)
    {
        printBoard();

        printf("Player %d, enter row(1-3) :", player);
        scanf("%d", &rows);
        printf("Player %d, enter column(1-3) :", player);
        scanf("%d", &cols);
        if (rows < 1 || rows > 3 || cols < 1 || cols > 3)
        {
            printf("Invalid move. Try again.\n");
            continue;
        }
        if (board[rows - 1][cols - 1] != ' ')
        {
            printf("That spot id already taken . Try again.\n");
            continue;
        }
        if (player == 1)
        {
            mark = 'X';
            board[rows - 1][cols - 1] = mark;
            player = 2;
        }
        else
        {
            mark = 'O';
            board[rows - 1][cols - 1] = mark;
            player = 1;
        }
        if (checkWinner())
        {
            break;
        }
        if (isBoardFull())
        {
            printf("It's a tie !\n");
            return 0;
        }
    }
    printBoard();
    if (mark == 'X')
    {
        player = 1;
        printf("Player %d(%c) wins !!!\n", player, mark);
    }
    if (mark == 'O')
    {
        player = 2;
        printf("Player %d(%c) wins !!!\n", player, mark);
    }

    return 0;
}
