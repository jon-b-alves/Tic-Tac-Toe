#include <stdio.h>

enum Mark {
    EMPTY = 0,
    O = 1,
    X = 2
};

enum Mark board[3][3] = {
    {EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY}
};

int main() {
    printf("%d\n", board[2][1]);
    return 0;
}
