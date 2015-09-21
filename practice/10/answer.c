#include <stdio.h>

int main(){
	int n, i;
	scanf("%d%d", &n, &i);
	
	int power = 1;
	for( int p = 0 ; p < i ; p++ ){
		power *= n;
	}

	printf("%d\n", power);

	return 0;
}
