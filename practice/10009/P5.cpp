#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int gcd(int x, int y) {
	int t;
	while (x%y)
		t = x, x = y, y = t%y;
	return y;
}
int main() {
	int a, b;
	while (scanf("%d %d", &a, &b) == 2) {
		assert(a >= 0 && b > 0);
		int g = gcd(a, b);
		a /= g, b /= g;
		printf("%d / %d\n", a, b);
	}
	return 0;
}
/*
reduce fraction
80% data a, b <= 1000
20% data 1000000000 <= a, b <= 2000000000 

Sample Input

60 80 

Sample Output

3 / 4

*/
