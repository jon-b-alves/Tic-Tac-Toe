#include <stdio.h>

enum Mark { EMPTY = 0, O = 1, X = 2 };

enum Mark board[3][3] = {
    {EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY}
};

/* TODO 
 * print_board()
 * validate_board()
*/

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
            printf("cell already marked\n");
            continue;
        }

        if (turn == 0) {
            board[row][col] = O;
        }
        else {
            board[row][col] = X;
        }

        turn = 1 - turn;
    }

    return 0;
}
