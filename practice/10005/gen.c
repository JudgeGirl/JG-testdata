#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int T = 20;
    int N = 100;
    for (int i=0;i<T;i++) {
        for (int j=0;j<N;j++) {
            if (rand()%2==0) {
                printf("%c", 'a'+rand()%10);
            } else {
                printf("%d", rand()%1000000+1);
                printf("%c", 'a'+rand()%10);
            }
        }
        printf("\n");
    }
    for(int i=1;i<=500000000;i++);
    return 0;
}