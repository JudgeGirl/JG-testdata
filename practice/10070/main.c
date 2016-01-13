#include "subtree.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static Node* build(int *n) {
	int label;
	if (scanf("%d", &label) != 1)
		return NULL;
	if (label == -1)	return NULL;
	Node *u = (Node *) malloc(sizeof(Node));
	u->label = label, u->left = u->right = NULL;
	u->left = build(n);
	u->right = build(n);
	(*n)++;
	return u;
}
static int cmp(const void *x, const void *y) {
	if (*(int *) x < *(int *) y)
		return -1;
	if (*(int *) x > *(int *) y)
		return 1;
	return 0;
}
int main() {
	while (1) {
		int n = 0, m, k;
		Node *root = build(&n);
		if (n == 0)
			return 0;
		assert(n <= 10000);
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d", &k);
			int *buf = (int*) malloc(sizeof(int)*n);
			int f = getNode(root, buf, k);
			assert(f >= 0 && f < n);
			qsort(buf, f, sizeof(int), cmp);
			printf("%d\n", f);
			for (int j = 0; j < f; j++)
				printf("%d%s", buf[j], j == f-1 ? "" : " ");
			puts("");
			free(buf);
		}
	}
	return 0;
}
/*
10 5 3 1 -1 -1 1 -1 -1 7 -1 -1 1 -1 -1
*/
