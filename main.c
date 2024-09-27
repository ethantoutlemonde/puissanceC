#include <stdio.h>
#include <stdlib.h>

char** init_board(int rows, int columns);
void print_board(char** board, int rows, int columns);
char** place_token(char** board, int rows, int columns, char player);
char switch_player(char c);
int verif_columns(char **board, int rows, int columns);
int verif_rows(char **board, int rows, int columns);


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

char switch_player(char c) {
    return c == 'x' ? 'y' : 'x';
}

int verif_rows(char **board, int rows, int columns) {
    int puissance = 4;
    int verif = 0;

    for (int y = 0; y < columns; y++) {
        for (int x = 0; x < (rows - 2); x++) {
            verif = 0;
            for (int c = 1; c < puissance; c++) {
                if (board[x][y] == board[x + c][y] && board[x][y] != 0 && (x + c) < rows) {
                    verif++;
                }
                else
                    verif = 0;
                if (verif == puissance - 1)
                    return 1;
            }
        }
    }
    return 0;
}

int verif_columns(char **board, int rows, int columns) {
    int puissance = 4;
    int verif = 0;

    for (int x = 0; x < rows; x++) {
        for (int y = 0; (y + puissance-1) < columns; y++) {
            verif = 0;
            for (int c = 1; c < puissance || c < columns; c++) {
                if (board[x][y] == board[x][y + c] && board[x][y] != 0)
                    verif++;
                else
                    verif = 0;
                if (verif == puissance - 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int diagonal(char **board, int rows, int columns){
    int puissance = 4;
    int verif;

    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < columns; y++) {
            verif = 0;
            for (int c = 1; c < puissance; c++) {
                if (board[x][y] == board[x + c][y + c] && board[x][y] != 0)
                    verif++;
                else {
                    verif = 0;
                    break;
                }
                if (verif == puissance - 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int diagonalv(char **board, int rows, int columns){
    int puissance = 4;
    int verif;

    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < columns; y++) {
            verif = 0;
            for (int c = 1; c < puissance; c++) {
                if (board[x][y] == board[x + c][y - c] && board[x][y] != 0)
                    verif++;
                else {
                    verif = 0;
                    break;
                }
                if (verif == puissance - 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}


int verif_win(char **board, int rows, int columns) {
    int win = 0;


    win = verif_columns(board, rows, columns);
    if (win == 1)
        return 1;
    win = verif_rows(board, rows, columns);
    if (win == 1)
        return 1;
    win = diagonal(board, rows, columns);
    if (win == 1)
        return 1;
    win = diagonalv(board, rows, columns);
    if (win == 1)
        return 1;

    return 0;

}

int main( )
{
    int rows = 6;
    int columns = 7;
    char joueur = 'x';
    int isWin = 0;

    char** board = init_board(rows, columns);
    while(isWin == 0) {
        print_board(board, rows, columns);
        board = place_token(board, rows, columns, joueur);
        isWin = verif_win(board, rows, columns);
        if (isWin == 1) {
            print_board(board, rows, columns);
            printf("%c gagne !\n", joueur);
            break;
        }
        joueur = switch_player(joueur);
    }


    return 666;
}