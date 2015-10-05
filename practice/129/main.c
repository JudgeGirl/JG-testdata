#include<stdio.h>
#include<stdlib.h>
#include "prepare_array.h"

int main(){
	int segments;
	int *seglen;
	int **segval;
	int n = 0;
	int max_col = 0;

	int i, j;
	int dummy;

	dummy = scanf("%d", &segments);
	seglen = (int*)malloc(sizeof(int)*segments);
	segval = (int**)malloc(sizeof(int*)*segments);

	for(i=0; i<segments; i++){
		dummy = scanf("%d", &seglen[i]);
		n += seglen[i];
		if(max_col < seglen[i])
			max_col = seglen[i];
		segval[i] = (int*) malloc(sizeof(int)*(seglen[i]+3));
		for(j=0; j<seglen[i]; j++){
			dummy = scanf("%d", &segval[i][j]);
		}
	}
	int row;
	int *column;
	int buffer[10000] ; 
	int ** array;
	row = segments ;
	column = (int*) malloc(sizeof(int)*row );
	array = (int**) malloc(sizeof(int*) * n );
	for(i=0; i<segments; i++)
		column[i] = seglen[i];
	prepare_array(buffer, array, row, column);
	for(i=0; i<row; i++){
		for(j=0; j<column[i]; j++)
			array[i][j] = segval[i][j];
	}
	printf("%d\n", row);
	for(i=0; i<row; i++){
		printf("%d", column[i]);
		for(j=0; j<column[i]; j++)
			printf(" %d", array[i][j]);
		printf("\n");
	}
}
