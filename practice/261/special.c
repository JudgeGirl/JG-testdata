#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        char buf[1024];
        char in[3][1024], out[5][1024];
        for (int i = 0; i < 3; i++) {
                fgets(buf, 1024, fin0);
                sscanf(buf, "%s", in[i]);
        }
        {
                assert(fgets(buf, 1024, fin2));
                check_format(buf, 5);
                sscanf(buf, "%s %s %s %s %s", out[0], out[1], out[2], out[3], out[4]);
                assert(strlen(in[0]) == strlen(out[0]));
                assert(strlen(in[1]) == strlen(out[2]));
                assert(strlen(in[2]) == strlen(out[4]));
                assert(!strcmp(out[1], "x"));
                assert(!strcmp(out[3], "="));
                int a, b, c;
                sscanf(out[0], "%d", &a);
                sscanf(out[2], "%d", &b);
                sscanf(out[4], "%d", &c);
                assert(a * b == c);
                int R[128] = {}, VAL[128] = {};
                for (int i = 0; i < 3; i++) {
                        for (int j = 0; in[i][j]; j++) {
                                if (isalpha(in[i][j])) {
                                        if (R[in[i][j]] == 0) {
                                                R[in[i][j]] = 1;
                                                VAL[in[i][j]] = out[i*2][j];
                                        } else {
                                                assert(VAL[in[i][j]] == out[i*2][j]);
                                        }
                                } else {
                                        assert(in[i][j] == out[i*2][j]);
                                }
                        }
                }
        }
        return 0;
}
