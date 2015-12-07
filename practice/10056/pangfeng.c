#include "pangfeng.h"
#include <string.h>
#include <stdlib.h>

void init(ExamTable *self, int dim) {
	self->row_n = 0, self->dim_n = dim;
}
void addrow(ExamTable *self, char *sid, int score[]) {
	Row *r = &(self->dat[self->row_n]);
	strcpy(r->sid, sid);
	for (int i = 0; i < self->dim_n; i++)
		r->score[i] = score[i];
	(self->row_n)++;
}
static int _sort[128], _sort_dim;
static int cmp(const void *a, const void *b) {
	Row *x = *(Row **)a, *y = *(Row **)b;
	for (int i = 0, s; i < _sort_dim; i++) {
		s = _sort[i];
		if (x->score[s] != y->score[s])
			return y->score[s] - x->score[s];
	}
	return strcmp(x->sid, y->sid);
}
void print(ExamTable *self, int sort_order[]) {
	Row *a[256];
	for (int i = 0; i < self->row_n; i++)
		a[i] = &(self->dat[i]);
	for (int i = 0; i < self->dim_n; i++)
		_sort[i] = sort_order[i];
	_sort_dim = self->dim_n;
	qsort(a, self->row_n, sizeof(Row*), cmp);
	puts("----- table begin -----");
	for (int i = 0; i < self->row_n; i++) {
		printf("%s", a[i]->sid);
		for (int j = 0; j < self->dim_n; j++)
			printf(", %d", a[i]->score[j]);
		puts("");
	}
	puts("----- end         -----");
}
