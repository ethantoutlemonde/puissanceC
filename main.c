#include <stdio.h>
#include <stdlib.h>

char** init_board(int rows, int columns);
void print_board(char** board, int rows, int columns);
char** place_token(char** board, int rows, int columns, char player);


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

char** place_token(char** board, int rows, int columns, char player){
    int flag = 0;
    int token;
    do{
        printf("%c select where you want to place your token: ", player);
        scanf("%d",&token);
        printf("\n");
        if(token < 1 || token > columns){
            flag = 1;
            printf("token out of grid\n");
            fflush(stdin);
            break;
        }
        for(int i = rows-1; i >= 0; i--) {
            if(board[i][token-1] == 0 ){
                board[i][token-1] = player;
                break;
            }
            if(board[0][token-1] != 0 ){
                printf("token out of grid\n");
                fflush(stdin);
                flag = 1;
                break;
            }
        }

    }while(flag != 0);
    return board;


}

int main( )
{
    int rows = 6;
    int columns = 7;

    char** board = init_board(rows, columns);
    while(1){
        print_board(board, rows, columns);
        board = place_token(board, rows, columns, 'x');
        print_board(board, rows, columns);
        board = place_token(board, rows, columns, 'Y');
    }


    return 666;
}

