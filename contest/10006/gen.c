#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int n = 100;
    for (int i=0;i<n;i++) {
        printf("%d\n", rand()%1000+10);
    }
    for(int i=1;i<=500000000;i++);
    return 0;
}