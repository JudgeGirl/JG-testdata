#include "pair.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct E {
	int key, value;	
} E;
typedef struct R {
	int sum, a, b;
} R;
static int cmpE(const void *x, const void *y) {
	E *a = (E *) x, *b = (E *) y;
	if (a->key < b->key)	return -1;
	if (a->key > b->key)	return 1;
	if (a->value < b->value)	return -1;
	if (a->value > b->value)	return 1;
	return 0;
}
static int cmpR(const void *x, const void *y) {
	R *a = (R *) x, *b = (R *) y;
#ifdef INC
	if (a->sum < b->sum)	return -1;
	if (a->sum > b->sum)	return 1;
	if (a->a < b->a)	return -1;
	if (a->a > b->a)	return 1;
	if (a->b < b->b)	return -1;
	if (a->b > b->b)	return 1;
#else
	if (a->sum > b->sum)	return -1;
	if (a->sum < b->sum)	return 1;
	if (a->a > b->a)	return -1;
	if (a->a < b->a)	return 1;
	if (a->b > b->b)	return -1;
	if (a->b < b->b)	return 1;
#endif
	return 0;
}
void pairPrint(int A[], int n) {
	E *e = (E*) malloc(sizeof(E) * n);
	R *r = (R*) malloc(sizeof(R) * n/2);
	for (int i = 0; i < n; i++)
		e[i].key = A[i], e[i].value = i;
	qsort(e, n, sizeof(E), cmpE);
	
	int m = 0;
	for (int i = 0, j = n-1; i < j; i++, j--) {
		r[m].sum = e[i].key + e[j].key;
		r[m].a = e[i].value, r[m].b = e[j].value;
		if (r[m].a > r[m].b) {
			int t = r[m].a;
			r[m].a = r[m].b;
			r[m].b = t;
		}
		m++;
	}	
	qsort(r, m, sizeof(R), cmpR);
	
	for (int i = 0; i < m; i++) {
#ifdef INC
		printf("%d = numbers[%d] + numbers[%d]\n", r[i].sum, r[i].a, r[i].b);
#else
		printf("%d = numbers[%d] + numbers[%d]\n", r[i].sum, r[i].b, r[i].a);
#endif
	}
}
