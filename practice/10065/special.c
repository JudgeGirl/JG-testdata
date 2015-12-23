#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

int fsize(FILE *fp) {
    int prev = ftell(fp);
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    fseek(fp, prev, SEEK_SET);
    return size;
}

typedef struct {
    int balance;
    char name[128];
    int gender;
} Account;

int main(int argc, char *argv[]) {
    assert(argc >= 4);
    FILE *fin0 = fopen(argv[1], "r"),  // testdata in
    	*fin1 = fopen(argv[2], "r"),   // testdata out
        *fin2 = fopen(argv[3], "r");   // user output
        
    assert(fsize(fin1) == fsize(fin2));
    int n = fsize(fin1) / sizeof(Account);
    for (int i = 0; i < n; i++) {
    	Account t1, t2;
    	fread(&t1, sizeof(t1), 1, fin1);
    	fread(&t2, sizeof(t2), 1, fin2);
    	assert(t1.balance == t2.balance);
    	assert(strcmp(t1.name, t2.name) == 0);
    	assert(t1.gender == t2.gender);
	}
    return 0;
}
