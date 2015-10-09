#include <stdio.h>
#include <stdlib.h>

int main() {
	int x, sum = 0;
	while (scanf("%d", &x) == 1)
		sum += x;
	printf("%d\n", sum);
	return 0;
}
/*
Sample Input 
2015
9
20

Sample Output
2044
*/
