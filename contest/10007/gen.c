#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int n = 100;
    printf("%d\n", n);
    for (int i=0;i<n;i++) {
        if(i) printf(" ");
        if(rand()%4==0) {
            printf("0");
        } else {
            printf("1");
        }
    }printf("\n");
    for(int i=1;i<=500000000;i++);
    return 0;
}