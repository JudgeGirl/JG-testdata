#include <stdio.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));
    int r = 99, c = 99;
    printf("%d %d\n", r, c);
    for (int i=0 ; i<r ; i++) {
        for (int j=0 ; j<c ; j++) {
            if(j) printf(" ");
            printf("%d", rand()%500+1);
        }
        printf("\n");
    }
    return 0;
}