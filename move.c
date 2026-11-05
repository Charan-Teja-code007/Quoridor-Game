#include<stdio.h>
#include "move.h"
extern char board[9][9];
extern  int h[8][9];
extern int v[9][8];

extern int pr,pc;
extern int qr,qc;

extern int wallsP,wallsQ;
char getMove()
{
    char move;

    printf("\nEnter command (W/A/S/D, I/J/K/L, H, V, E): ");

    scanf(" %c",&move);

    if(move >= 'a' && move <= 'z')
        move = move - 32;

    return move;
}