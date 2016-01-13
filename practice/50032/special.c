#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

void cformat(const char const *buf, int n, int A[]) {
	// n variable separate by spaces
    int c = 0, toks = 0;
    char *ptr = strtok(buf, " \t\n\r");;
    while (ptr) {
        assert(sscanf(ptr, "%d", &A[toks]) == 1);
		toks++, ptr = strtok(NULL, " \t\n\r");
        assert(toks <= n);
    }
    assert(toks == n);
}
int main(int argc, char *argv[]) {
    assert(argc >= 4);
    FILE *fin0 = fopen(argv[1], "r"),  // testdata in
        *fin1 = fopen(argv[2], "r"),   // testdata out
        *fin2 = fopen(argv[3], "r");   // 
#define MAXN 128
	int N, M, K;
    char buf[1024];
    char g[32][32];
    while (fscanf(fin0, "%d %d %d", &N, &M, &K) == 3) {
    	fscanf(fin1, "%s", &buf);
    	int solvable = !strcmp(buf, "Y");
    	if (!solvable) {
    		fgets(buf, 1024, fin2);
    		assert(sscanf(buf, "%s", g[0]) == 1);
    		assert(!strcmp("N", g[0]));
		} else {
			for (int i = 0; i < N; i++) {	
				fgets(buf, 1024, fin2);
				assert(sscanf(buf, "%s", g[i]) == 1);
				assert(strlen(g[i]) == N);
			}
			int C[MAXN] = {}, R[MAXN] = {}, D1[MAXN*2] = {}, D2[MAXN*2] = {};
			int cnt = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (g[i][j] == 'o') {
						cnt++;
						C[i]++, R[j]++;
						D1[i+j]++, D2[i-j + MAXN]++;
						assert(C[i] <= K && R[j] <= K && D1[i+j] <= K && D2[i-j + MAXN] <= K);
					}
				}
			}
			assert(cnt == M);
		}
	}
    return 0;
}
