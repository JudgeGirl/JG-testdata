#include <stdio.h>

int main(){
	int n;
	int max = 0, min = 0;
	while( scanf("%d", &n) != EOF ){
		int bp;
		for( int i = 0 ; i < n ; i++ ){
			scanf("%d", &bp);
			if( bp > max ) max = bp;
			if( bp < min ) min = bp;
		}
	
	}
	
	printf("min: %d, max: %d\n", min, max);

	return 0;
}
