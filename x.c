
#include <stdio.h>
#include "tej.h"
#include "move.h"
#include "wall.h"
char board[9][9];
int h[8][9] = {0};
int v[9][8] = {0};

int pr = 0, pc = 4;
int qr = 8, qc = 4;

int wallsP = 9, wallsQ = 9;

int main()
{
    char move;
    int turn = 1;

    while(1)
    {
        printGrid();

        if(turn == 1)
            printf("\nPlayer 1's turn (P)\n");
        else
            printf("\nPlayer 2's turn (Q)\n");

        move = getMove();

        if(move == 'E')
            break;

        if(move == 'H' || move == 'V')
        {
            if(turn == 1 && wallsP > 0)
            {
                if(placeWall(move))
                {
                    wallsP--;
                    printf("Wall placed successfully!\n");
                }
                else
                    printf("Invalid wall placement!\n");
            }
            else if(turn == 2 && wallsQ > 0)
            {
                if(placeWall(move))
                {
                    wallsQ--;
                    printf("Wall placed successfully!\n");
                }
                else
                    printf("Invalid wall placement!\n");
            }
            else
                printf("No walls remaining!\n");
        }

        else if(turn == 1)
        {
            if(move == 'W' && pr > 0 && h[pr - 1][pc] == 0 && !(pr - 1 == qr && pc == qc))
                pr--;
            else if(move == 'S' && pr < 8 && h[pr][pc] == 0 && !(pr + 1 == qr && pc == qc))
                pr++;
            else if(move == 'A' && pc > 0 && v[pr][pc - 1] == 0 && !(pr == qr && pc - 1 == qc))
                pc--;
            else if(move == 'D' && pc < 8 && v[pr][pc] == 0 && !(pr == qr && pc + 1 == qc))
                pc++;
            else
                printf("Invalid move!\n");
        }

        else
        {
            if(move == 'I' && qr > 0 && h[qr - 1][qc] == 0 && !(qr - 1 == pr && qc == pc))
                qr--;
            else if(move == 'K' && qr < 8 && h[qr][qc] == 0 && !(qr + 1 == pr && qc == pc))
                qr++;
            else if(move == 'J' && qc > 0 && v[qr][qc - 1] == 0 && !(qr == pr && qc - 1 == pc))
                qc--;
            else if(move == 'L' && qc < 8 && v[qr][qc] == 0 && !(qr == pr && qc + 1 == pc))
                qc++;
            else
                printf("Invalid move!\n");
        }

        if(pr == 8)
        {
            printGrid();
            printf("\nPLAYER 1 WINS!\n");
            break;
        }

        if(qr == 0)
        {
            printGrid();
            printf("\nPLAYER 2 WINS!\n");
            break;
        }

        if(turn == 1)
            turn = 2;
        else
            turn = 1;
    }

    printf("\nGame ended.\n");

    return 0;
}
