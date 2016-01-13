#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	while( scanf("%d", &n) != EOF){
	
	int *bopo = malloc(sizeof(int)*n);
	for( int i = 0 ; i < n ; i++ ){
		scanf("%d", &bopo[i]);
	}

	for( int i = 0 ; i < n ; i++ ){
		for( int j = i+1 ; j < n ; j++ ){
			if( bopo[i] == bopo[j] ){
				printf("fail!");
				return -1;
			}
		}
	}
	
	free(bopo);
	}
}
