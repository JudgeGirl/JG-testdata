#include <stdio.h>
#include <stdlib.h>
#include "snake.h"

int main() {
#define VERT(x, y) ((x)*m+(y))
        int n, m, o, step, x;
        int dice[1024];
        scanf("%d %d", &n, &m);
        int **score = (int **) malloc((n*m+1)*sizeof(int*));
        int ***towhere = (int ***) malloc((n*m+1)*sizeof(int**));
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                        scanf("%d", &x);
                        score[VERT(i, j)] = (int *)malloc(sizeof(int));
                        *score[VERT(i, j)] = x;
                }
        }
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++)
                        towhere[VERT(i, j)] = NULL;
        }
        score[VERT(n, 0)] = NULL;
        towhere[VERT(n, 0)] = NULL;
        scanf("%d", &o);
        for (int i = 0; i < o; i++) {
                int sx, sy, ex, ey;
                scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
                towhere[VERT(sx, sy)] = &score[VERT(ex, ey)];
        }
        scanf("%d", &step);
        simulate(score, towhere, step);
#undef VERT
        return 0;
}
/*
3 4
0 1 2 3
4 5 6 7
8 9 10 11
2
0 1 1 2
2 2 0 2
10
*/
