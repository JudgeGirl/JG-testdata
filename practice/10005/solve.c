#include <stdio.h> 
#include <string.h> // strlen(s)
#include <assert.h>
int main() {
    char s[1024];
    while (scanf("%s", s) == 1) {
        int n = (int) strlen(s);
        assert(n <= 1000);
        int f = 0, x = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];  
            /*
                input "CSIE", 
                s[0] = 'C', s[1] = 'S', ...
            */
            if (c >= '0' && c <= '9') {
                f = 1, x = x * 10 + c - '0';
            } else {
                if (f)  printf("%d\n", x);
                x = 0, f = 0;
            }               
        }
        if (f)
            printf("%d\n", x);
    }
    return 0;
}

/*
P0C002NTUCSIE2015Week2EXAMPROBLEM1

0
2
2015
2
1
*/
