#include <stdio.h>
#include <stdlib.h>

char** init_board(int rows, int columns);
void print_board(char** board, int rows, int columns);


char** init_board(int rows, int columns){
    char ** board;
    board = calloc(rows,sizeof(char*));
    for (int i = 0; i < columns; i++){
        board[i] = calloc(columns,sizeof(char));
    }
    return board;
};


void print_board(char** board, int rows, int columns){
    for(int i = 0; i < rows; i++){
        printf("|");
        for(int j = 0; j < columns; j++){
            printf(" %c ", board[i][j]);
            printf("|");
        }
        printf("\n");
    }
}

int main( )
{
    int rows = 6;
    int columns = 7;

    char** board = init_board(rows, columns);
    print_board(board, rows, columns);
    return 666;
}

