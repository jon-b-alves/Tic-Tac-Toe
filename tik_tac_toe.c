#include <stdio.h>
#include <stdlib.h>
#define PLAYER1_TURN 0

enum Mark { EMPTY = 0, O = 1, X = 2 };

enum Mark board[3][3] = {
    {EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY}
};

/* TODO 
 * validate_board()
*/

void print_board() {
    for (int row = 0; row <= 2; row++) {
        putchar('|');
        for (int col = 0; col <= 2; col++) {
            //printf("%d|", board[row][col]);
            if (board[row][col] == EMPTY) {
                printf(" |");
            }
            else if (board[row][col] == O) {
                printf("O|");
            }
            else {
                printf("X|");
            }
        }
        putchar('\n');
    }
    putchar('\n');
}


void validate_board() {
    if (
        // validating rows for player1
        board[0][0] == O && board[0][1] == O && board[0][2] == O ||
        board[1][0] == O && board[1][1] == O && board[1][2] == O ||
        board[2][0] == O && board[2][1] == O && board[2][2] == O ||

        // validating columns for player1
        board[0][0] == O && board[1][0] == O && board[2][0] == O ||
        board[0][1] == O && board[1][1] == O && board[2][1] == O ||
        board[0][2] == O && board[1][2] == O && board[2][2] == O ||

        // validating diagonals for player1
        board[0][0] == O && board[1][1] == O && board[2][2] == O ||
        board[0][2] == O && board[1][1] == O && board[2][0] == O
    ) {
        printf("[player1 wins]\n");
        exit(0);
    }

    if (
        // validating rows for player2
        board[0][0] == X && board[0][1] == X && board[0][2] == X ||
        board[1][0] == X && board[1][1] == X && board[1][2] == X ||
        board[2][0] == X && board[2][1] == X && board[2][2] == X ||

        // validating columns for player2
        board[0][0] == X && board[1][0] == X && board[2][0] == X ||
        board[0][1] == X && board[1][1] == X && board[2][1] == X ||
        board[0][2] == X && board[1][2] == X && board[2][2] == X ||

        // validating diagonals for player2
        board[0][0] == X && board[1][1] == X && board[2][2] == X ||
        board[0][2] == X && board[1][1] == X && board[2][0] == X
    ) {
        printf("[player2 wins]\n");
        exit(0);
    }

    if (
        // validating if game ended in a draw
        board[0][0] != EMPTY && board[0][1] != EMPTY && board[0][2] != EMPTY &&
        board[1][0] != EMPTY && board[1][1] != EMPTY && board[1][2] != EMPTY &&
        board[2][0] != EMPTY && board[2][1] != EMPTY && board[2][2] != EMPTY
    ) {
        printf("[draw]\n");
        exit(0);
    }
}

int main() {
    printf("\nplayer1 goes first and will use O's\nplayer2 will go second and will use X's\nenter the position where you will like to mark on the board using 1-9\n\n|1|2|3|\n|4|5|6|\n|7|8|9|\n\n");

    int turn = 0; // player1 plays on turn 0 with O's, player2 players on turn 1 with X's
    int ch;

    while ((ch = getchar()) != EOF) {
        
        if (ch == '\n') continue;
        
        int row = -1;
        int col = -1;

        switch (ch) {
            case '1': row = 0; col = 0; break;
            case '2': row = 0; col = 1; break;
            case '3': row = 0; col = 2; break;
            case '4': row = 1; col = 0; break;
            case '5': row = 1; col = 1; break;
            case '6': row = 1; col = 2; break;
            case '7': row = 2; col = 0; break;
            case '8': row = 2; col = 1; break;
            case '9': row = 2; col = 2; break;
            default: printf("invalid input\n"); continue;
        }

        if (board[row][col] != EMPTY) {
            printf("[cell already marked]\n\n");
            continue;
        }

        if (turn == PLAYER1_TURN) {
            board[row][col] = O;
        }

        else {
            board[row][col] = X;
        }
        
        print_board();
        validate_board();

        turn = 1 - turn;
    }

    return 0;
}
