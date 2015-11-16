#include <stdio.h>
// #include <inttypes.h>	// standard PRIu64 output format
#define PRIu64 "llu"
#include "blockmover.h"

#define VERT(x, y) ((x)*8+(y))
void printBlock(uint64_t *block) {
	for (int i = 0; i < 8; i++, puts("")) {
		for (int j = 0; j < 8; j++)
			printf("%" PRIu64 "", (*block)>>(VERT(i, j))&1);
	}
}
void initialize(uint64_t *block, int row, int col, int size) {
	*block = 0;
	for (int i = row; i < row+size; i++) {
		for (int j = col; j < col+size; j++) 
			*block |= 1LLU<<VERT(i, j);
	}
}
int moveLeft(uint64_t *block) {
	if ((*block) & 0x0101010101010101LLU)	return 0;
	*block >>= 1;
	return 1;
}
int moveRight(uint64_t *block) {
	if ((*block) & 0x8080808080808080LLU)	return 0;
	*block <<= 1;
	return 1;
}
int moveUp(uint64_t *block) {
	if ((*block) & 0x00000000000000FFLLU)	return 0;
	*block >>= 8;
	return 1;
}
int moveDown(uint64_t *block) {
	if ((*block) & 0xFF00000000000000LLU)	return 0;
	*block <<= 8;
	return 1;
}
#undef VERT
