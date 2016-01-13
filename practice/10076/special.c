#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

void seesaw_format(char buf[], int N, int B[]) {
	char *p = strtok(buf, " \n\t\r");
	int n = 0;
	while (p != NULL) {
		assert(n < N);
		if (n == N/2) {
			assert(strcmp("_^_", p) == 0);
		} else {
			sscanf(p, "%d", &B[n]);
		}
		n++;
		p = strtok(NULL, " \n\t\r");
	}
}
int cmp(const void *a, const void *b) {
	int x = *(int *) a;
	int y = *(int *) b;
	if (x < y)	return -1;
	if (x > y)	return 1;
	return 0;
}
void set_contain(int A[], int an, int C[], int cn) {
	int i = 0, j = 0;
	while (i < an && j < cn) {
		if (A[i] == C[j]) {
			i++, j++;
		} else if (A[i] < C[j]) {
			i++;
		} else {
			assert(0);
		}
	}
	assert(j == cn);
}
void balance(int B[], int N) {
	int lw = 0, rw = 0;
	for (int i = N/2-1, x = 1; i >= 0; i--, x++)
		lw += B[i] * x;
	for (int i = N/2+1, x = 1; i < N; i++, x++)
		rw += B[i] * x;
	assert(lw == rw);
}
void nosolution(char buf[]) {
	char *p = strtok(buf, " \n\t\r");
	int n = 0;
	while (p != NULL) {
		assert(n < 1);
		assert(strcmp("N", p) == 0);
		n++;
		p = strtok(NULL, " \n\t\r");
	}
	assert(n == 1);
}
int main(int argc, char *argv[]) {
    assert(argc >= 4);
    FILE *fin0 = fopen(argv[1], "r"),  // testdata in
        *fin1 = fopen(argv[2], "r"),   // testdata out
        *fin2 = fopen(argv[3], "r");   // 
#define MAXN 128
	int N;
    char buf[65536];
    char g[32][32];
    while (fscanf(fin0, "%d", &N) == 1) {
    	int A[1024], B[1024], C[1024];
    	for (int i = 0; i < N; i++)
    		fscanf(fin0, "%d", &A[i]);
    	fscanf(fin1, "%s", buf);
    	int solvable = !strcmp("Y", buf);
    	if (solvable) {
	    	fgets(buf, 65536, fin2);
	    	seesaw_format(buf, N, B);
	    	int m = 0;
	    	for (int i = 0; i < N/2; i++)
	    		C[m++] = B[i];
	    	for (int i = N/2+1; i < N; i++)
	    		C[m++] = B[i];
	    	qsort(A, N, sizeof(int), cmp);
	    	qsort(C, N-1, sizeof(int), cmp);
	    	set_contain(A, N, C, N-1);
	    	balance(B, N);
    	} else {
    		fgets(buf, 65536, fin2);
    		nosolution(buf);
		}
	}
    return 0;
}
