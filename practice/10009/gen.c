#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    for (int i=0;i<50;i++) {
        int _gcd = rand()%10+2;
        int a = (rand()%200+3) * _gcd;
        int b = (rand()%200+3) * _gcd;
        printf("%d %d\n", a, b);
    }
    for(int i=1;i<=500000000;i++);
    return 0;
}