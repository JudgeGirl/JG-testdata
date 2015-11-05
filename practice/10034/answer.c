#include <stdio.h>

int main(){
	int n, k, m, d;
	scanf("%d%d%d%d", &n, &k, &m, &d);
	
	int matrix[15][15];
	int submatrix[15][15];
	
	for( int i = 0 ; i < n ; i++ ){
		for( int j = 0 ; j < n ; j++ ){
			scanf("%d", &matrix[i][j]);
		}
	}
	
	for( int i = 0 ; i < k ; i++ ){
		for( int j = 0 ; j < k ; j++ ){
			scanf("%d", &submatrix[i][j]);
		}
	}
	
	for( int i = n-k ; i >= 0 ; i-- ){
		for( int j = n-k ; j >= 0 ; j-- ){
			int error = 0;
			int sumA = 0, sumB = 0;
			for( int w = 0 ; w < k ; w++ ){
				for( int h = 0 ; h < k ; h++ ){
					sumA += matrix[i+w][j+h];
					sumB += submatrix[w][h];
					if( matrix[i+w][j+h] != submatrix[w][h] ){
						error++;
					}
				}
			}
			
			if( error <= m && (sumA - sumB >= -d && sumA - sumB <= d)){
				printf("%d %d\n", i, j);
				return 0;
			}			
		}
	}
	
	printf("-1 -1\n");
	
	return 0;
}
