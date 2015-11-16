#include <stdio.h>
#include <assert.h>
#include "myint.h"

static void test_heart() {
	printf("run test heart\n");
	assert(madd(5, 6) == 11);
	assert(msub(1024, 512) == 512);
}

static void secret() {
	puts("You are such a good guy.");
	puts("119dae60924f19b85056d74df06e6327");
}
