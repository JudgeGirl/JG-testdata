#include <stdio.h>
#include "count.h"
char buf[1<<20] = {};
int main() {
    int len, numChar, numWord, numTokens, numLine;
//    char str[]="\tThis is Sample-Input string.\nHope this helps!\n\n";
    fread(buf, 1, 1<<20, stdin);
    count(buf, &numChar, &numWord, &numTokens, &numLine);
    printf("%s: %d %d %d %d\n", buf, numChar, numWord, numTokens, numLine);
    return 0;
}
