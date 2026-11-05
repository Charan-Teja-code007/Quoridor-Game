#include<stdio.h>
#include "wall.h"
extern char board[9][9];
extern  int h[8][9];
extern int v[9][8];

extern int pr,pc;
extern int qr,qc;

extern int wallsP,wallsQ;
int placeWall(char move)
{
    int r[4], c[4];
    int i, j;
    int minr = 9, maxr = -1;
    int minc = 9, maxc = -1;
    int seen[2][2] = {0};

    printf("\nEnter four corner coordinates.\n");

    for(i = 0; i < 4; i++)
    {
        printf("Corner %d (row,column): ", i + 1);

        if(scanf("%d,%d", &r[i], &c[i]) != 2)
            return 0;

        if(r[i] < 0 || r[i] > 8 || c[i] < 0 || c[i] > 8)
            return 0;

        if(r[i] < minr) minr = r[i];
        if(r[i] > maxr) maxr = r[i];
        if(c[i] < minc) minc = c[i];
        if(c[i] > maxc) maxc = c[i];
    }

    if(maxr - minr != 1 || maxc - minc != 1)
        return 0;

    for(i = 0; i < 4; i++)
        seen[r[i] - minr][c[i] - minc]++;

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            if(seen[i][j] != 1)
                return 0;
        }
    }

    if(move == 'H')
    {
        if(h[minr][minc] || h[minr][minc + 1])
            return 0;

        if(v[minr][minc] && v[minr + 1][minc])
            return 0;

        h[minr][minc] = 1;
        h[minr][minc + 1] = 1;
    }
    else
    {
        if(v[minr][minc] || v[minr + 1][minc])
            return 0;

        if(h[minr][minc] && h[minr][minc + 1])
            return 0;

        v[minr][minc] = 1;
        v[minr + 1][minc] = 1;
    }

    return 1;
}