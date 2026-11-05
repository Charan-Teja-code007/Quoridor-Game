#include<stdio.h>
#include "tej.h"
extern char board[9][9];
extern  int h[8][9];
extern int v[9][8];

extern int pr,pc;
extern int qr,qc;

extern int wallsP,wallsQ;

int printGrid()
{
    int i, j;

    printf("\n             QUORIDOR BOARD\n\n");
    printf("      ");

    for(j = 0; j < 9; j++)
        printf(" %d  ", j);

    printf("\n");

    for(i = 0; i < 9; i++)
    {
        printf("%d     ", i);

        for(j = 0; j < 9; j++)
        {
            if(i == pr && j == pc)
                printf(" P ");
            else if(i == qr && j == qc)
                printf(" Q ");
            else
                printf(" . ");

            if(j < 8)
            {
                if(v[i][j] == 1)
                    printf("|");
                else
                    printf(" ");
            }
        }

        printf("\n      ");

        if(i < 8)
        {
            for(j = 0; j < 9; j++)
            {
                if(h[i][j] == 1)
                    printf("---");
                else
                    printf("   ");

                if(j < 8)
                    printf(" ");
            }
            printf("\n");
        }
    }

    printf("\nPlayer 1 (P): (%d,%d)  Walls: %d\n", pr, pc, wallsP);
    printf("Player 2 (Q): (%d,%d)  Walls: %d\n", qr, qc, wallsQ);

    return 0;
}