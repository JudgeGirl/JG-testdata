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
        int n, m, x, y, type;
        char buf[1024];
        fgets(buf, 1024, fin0);
        if (sscanf(buf, "%d %d", &n, &m) != 2)
                return 1;
                
        int grid[128][128] = {}, acc = 0;
        const int dx[4][3] = {{-1, -1, 0}, {-1, 0, 0}, {0, 0, -1}, {-1, 0, -1}};
        const int dy[4][3] = {{-1, 0, -1}, {-1, -1, 0}, {0, -1, 0}, {0, 0, -1}};
        while (fgets(buf, 1024, fin2)) {
                check_format(buf, 3);
                assert(sscanf(buf, "%d %d %d", &type, &x, &y) == 3);
                assert(0 < x && x < n);
                assert(0 < y && y < n);
                assert(0 < type && type < 5);
                type--;
                int tx, ty;
                for (int i = 0; i < 3; i++) {
                        tx = x + dx[type][i];
                        ty = y + dy[type][i];
                        assert(0 <= tx && tx < n);
                        assert(0 <= ty && ty < n);
                        assert(tx <= n-m || ty <= n-m);
                        assert(grid[tx][ty] == 0);
                        grid[tx][ty] = 1;
                        acc++;
                }
        }
        assert(acc == n*n - m*m);
        return 0;
}
