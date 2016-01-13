#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

int used[512][512];
void line_format(char buf[], int N, int A[]) {
	char *p = strtok(buf, " \n\r\t");
	int n = 0;
	while (p != NULL) {
		assert(n < N);
		assert(sscanf(p, "%d", &A[n]) == 1);
		n++;
		p = strtok(NULL, " \n\r\t");
	}
	assert(n == N);
}
int main(int argc, char *argv[]) {
    assert(argc >= 4);
    FILE *fin0 = fopen(argv[1], "r"),  // testdata in
        *fin1 = fopen(argv[2], "r"),   // testdata out
        *fin2 = fopen(argv[3], "r");   // 
#define MAXN 128
	int N, M, sx, sy;
    char buf[65536];
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    while (fscanf(fin0, "%d %d %d %d", &N, &M, &sx, &sy) == 4) {
    	memset(used, 0, sizeof(used));
    	int T = N*M+1;
    	int x, y, xy[2], px, py;
    	
    	fgets(buf, 65536, fin2);
    	line_format(buf, 2, xy);
    	px = xy[0], py = xy[1];
    	assert(px == sx && py == sy);
    	
    	for (int i = 1; i < T; i++) {
    		fgets(buf, 65536, fin2);
    		line_format(buf, 2, xy);
    		x = xy[0], y = xy[1];
    		assert(x < N && x >= 0);
    		assert(y < M && y >= 0);
    		if (i != T-1)
    			assert(used[x][y] == 0);
    		used[x][y] = 1;
    		
    		int adj = 0;
    		for (int j = 0; j < 4; j++) {
    			if (px + dx[j] == x && py + dy[j] == y)
    				adj = 1;
			}
			assert(adj == 1);
			px = x, py = y;
		}
	}
    return 0;
}
