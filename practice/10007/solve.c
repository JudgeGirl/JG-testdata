#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
    int n, x;
    while (scanf("%d", &n) == 1) {
        int seg = 0, prev;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            assert(x == 0 || x == 1);
            if (i == 0 || x != prev)
                seg++;
            prev = x;
        }
        printf("%d\n", seg);
    }
    return 0;
}
/*
Sample Input
7
0 1 1 0 0 0 1

Sample Output
4
*/
