#include <stdio.h>
#include <stdlib.h>

int main() {
    int dollar[] = {1, 5, 10, 50, 100, 500, 1000};
    int n;
    while (scanf("%d", &n) == 1) {
        for (int i = 6; i >= 0; i--) {
            printf("%d%c", n/dollar[i], " \n"[i == 0]);
            n %= dollar[i];
        }
    }
    return 0;
}
/*
Sample Input

1234

Sample Output
1 0 2 0 3 0 4
*/
