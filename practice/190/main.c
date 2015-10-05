#include<stdio.h>
#include<stdlib.h>
#include"evaluate_f.h"

int main(){
	int n, sep, seg;
	int **iptr;
	int i, j, k;
	scanf("%d %d", &n, &sep);
	iptr = (int**)malloc(sizeof(int*)*n);
	i = 0;
	while(i<n){
		seg = (n-i>=sep?sep:n-i);
		iptr[i] = (int*)malloc(sizeof(int)*2*seg);
		i ++;
		seg --;
		while(seg>0){
			iptr[i] = iptr[i-1] + 2;
			i++;
			seg --;
		}
	}
	for(i=0; i<n; i++)
		scanf("%d %d", &iptr[i][0], &iptr[i][1]);
	j = evaluate_f( iptr, n, &k );
	printf("%d %d\n", j, k);
}
