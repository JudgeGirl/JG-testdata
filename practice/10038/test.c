#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAXNODE 100000
#define MAXCOL 4096
#define MAXN 5005
int main() {
    int n, A[MAXN], B[MAXN];
    while (scanf("%d", &n) == 1 && n) {
                for (int i = 1; i <= n; i++) {
                    scanf("%d %d", &A[i], &B[i]);
                }
                int sat[MAXN] = {}, ret = 0, re = n;
                while (re > 0) {
                        int R[10000] = {};
                        for (int i = 1; i <= n; i++) {
                                if (sat[i])     continue;
                                if (A[i] == B[i])       R[A[i]]++;
                                else                            R[A[i]]++, R[B[i]]++;
                        }
                        
                        int mx = 0, toy = -1;
                        for (int i = 0; i <= 10000; i++) {
                                if (R[i] > mx)
                                        mx = R[i], toy = i;
                        }
                        for (int i = 1; i <= n; i++) {
                                if (sat[i])     continue;
                                if (A[i] == toy || B[i] == toy) {
                                        sat[i] = 1;
                                        re--;
                                }
                        }
                        ret++;  
                }
                printf("%d\n", ret);
    }
    return 0;
}
