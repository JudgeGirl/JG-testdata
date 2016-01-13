#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printAndFree(Node *u) {
	if (u == NULL)	return ;
	printf("%d ", u->label);
	printAndFree(u->left);
	printAndFree(u->right);
	free(u);
}

int main() {
	int cases = 0;
	int A[32767], n;
	Node *root[32];
	while (scanf("%d", &n) == 1 && n != 0) {
		for (int i = 0; i < n; i++)
			scanf("%d", &A[i]);
		root[cases] = construct(A, n);
		cases++;
	}
	for (int i = 0; i < cases; i++) {
		int rid;
		scanf("%d", &rid);
		printAndFree(root[rid]);
		puts("");
	}
	return 0;
}
