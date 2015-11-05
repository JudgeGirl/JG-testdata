#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

void check_format(const char const *buf, int n) {       // n variable separate by spaces
        int c = 0, toks = 0;
        for (int i = 0; buf[i]; i++)
                if (isspace(buf[i]))
                        c++;
        assert(c == n);
        char *ptr = buf;
        while ((ptr = strpbrk(ptr, " \t\n\r")) != NULL)
                toks++, ptr++;
        assert(toks == n);
}
int main(int argc, char *argv[]) {
        assert(argc >= 4);
        FILE *fin0 = fopen(argv[1], "r"),       // testdata in
                 *fin1 = fopen(argv[2], "r"),   // testdata out
                 *fin2 = fopen(argv[3], "r");   // 
        int N, M, P, x, y;
        int g[32][32] = {}, valid = 0;
        int color[32] = {};
        char buf[1024];
        fgets(buf, 1024, fin0);
        if (sscanf(buf, "%d %d %d", &N, &P, &M) != 3)
                return 1;
        for (int i = 0; i < M; i++) {
                fgets(buf, 1024, fin0);
                sscanf(buf, "%d %d", &x, &y);
                g[x][y] = g[y][x] = 1;
        }
        fgets(buf, 1024, fin1);
        valid = buf[0] - '0';
        {
                int i = 0, x;
                while (fgets(buf, 1024, fin2)) {
                        if (valid == 0) {
                                assert(strcmp("no solution.\n", buf) == 0);
                                assert(fgets(buf, 1024, fin2) == 0);
                                return 0;
                        }
                        check_format(buf, 1);
                        assert(sscanf(buf, "%d", &x) == 1);
                        assert(x >= 1 && x <= P);
                        assert(i >= 0 && i < N);
                        for (int j = 0; j < N; j++) {
                                if (g[i][j] && color[j])
                                        assert(color[j] != x);
                        }
                        color[i] = x, i++;
                }
        }
        if (valid)
                for (int i = 0; i < N; i++)
                        assert(color[i] > 0 && color[i] <= P);
        else
                assert(0);
        return 0;
}
