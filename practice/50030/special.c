#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

void cformat(const char const *buf, int n, int A[]) {
	// n variable separate by spaces
    int c = 0, toks = 0;
    char *ptr = strtok(buf, " \t\n\r");;
    while (ptr) {
        assert(sscanf(ptr, "%d", &A[toks]) == 1);
		toks++, ptr = strtok(NULL, " \t\n\r");
        assert(toks <= n);
    }
    assert(toks == n);
}
typedef struct activity {
    int start;
    int end;
} Activity;

int cmp(const void *x, const void *y) {
	Activity *a = (Activity *) x;
	Activity *b = (Activity *) y;
	if (a->end < b->end)
		return -1;
	if (a->end > b->end)
		return 1;
	if (a->start < b->start)
		return -1;
	if (a->start > b->start)
		return 1;
	return 0;
}

Activity A[262144], B[262144];

int main(int argc, char *argv[]) {
    assert(argc >= 4);
    FILE *fin0 = fopen(argv[1], "r"),  // testdata in
        *fin1 = fopen(argv[2], "r"),   // testdata out
        *fin2 = fopen(argv[3], "r");   // 
    int SPEC = strcmp(argv[4], "-DPRINT") == 0;
    
    int n, m, ret, test_ret;
    char buf[1024];
    while (fscanf(fin0, "%d", &n) == 1) {
    	for (int i = 0; i < n; i++) {
			int l, r;		
    		fscanf(fin0, "%d %d", &l, &r);
    		A[i].start = l, A[i].end = r;
		}
		fscanf(fin1, "%d", &ret);
		qsort(A, n, sizeof(Activity), cmp);
		if (SPEC == 1) {
			for (int i = 0; i < ret; i++) {
				fgets(buf, 1024, fin2);
				int lr[1024];
				cformat(buf, 2, lr);
				B[i].start = lr[0], B[i].end = lr[1];
				assert(lr[0] <= lr[1]);
			}
			fgets(buf, 1024, fin2);
			sscanf(buf, "%d", &test_ret);
			assert(test_ret == ret);
			qsort(B, ret, sizeof(Activity), cmp);
			
			int it = 0, jt = 0;
			while (it < n && jt < ret) {
				if (A[it].end < B[jt].end) {
					it++;
				} else if (A[it].start < B[jt].start) {
					it++;
				} else if (A[it].start == B[jt].start && 
					A[it].end == B[jt].end) {
					it++, jt++;
				} else {
					assert(0);
				}
			}
			assert(jt == ret);
			for (int i = 1; i < ret; i++)
				assert(B[i-1].end <= B[i].start);
		} else {
			int test_ret;
			fscanf(fin2, "%d", &test_ret);
			assert(test_ret == ret);
		}
	}
    return 0;
}
