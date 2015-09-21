#include <stdio.h>
#include <assert.h>

int main() {
	int h, w, a;
	while (scanf("%d %d %d", &h, &w, &a) == 3) {
		assert(h > w && w >= 3 * a && h >= 5 * a);
		int c, s, i, e;
		c = h * a + 2 * w * a - 2 * a * a;
		s = h * a + 3 * w * a - 3 * a * a;
		i = h * a;
		e = h * a + 3 * w * a - 3 * a * a;
		fprintf(stderr, "%d %d %d %d\n", c, s, i, e);
		printf("%d\n", c+s+i+e);
		c = 2 * h + 2 * w + 2 * (w - a);
		s = 2 * h + 2 * w + 4 * (w - a);
		i = 2 * h + 2 * a;
		e = 2 * h + 2 * w + 4 * (w - a);
		fprintf(stderr, "%d %d %d %d\n", c, s, i, e);
		printf("%d\n", c+s+i+e);
	}
	return 0;
}
/*
 * 5 3 1
 * *** ***  *  ***
 * *   *    *  *
 * *   ***  *  ***
 * *     *  *  *
 * *** ***  *  ***
 * */

