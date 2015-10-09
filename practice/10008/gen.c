#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    for (int i=1;i<=50;i++) {
        printf("%d\n", rand()%10000+11);
    }
    return 0;
}