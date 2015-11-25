#include <stdio.h>
#include "set.h"

static char nextChar() {
	char c;
	return scanf(" %c",&c)==1?c:'Q';
}

static int nextInt() {
	int x;
	return scanf("%d",&x)==1?x:0;
}

int main() {
	static Set s[1024];
	for(int i=1;i<1024;i++)s[i]=(s[i-1]*7+99999999977)%1000000000000037;
	for(;;) {
		int a,c;
		switch(nextChar()) {
			case 'Z':
				init(s+nextInt());
				break;
			case 'A':
				a=nextInt();
				add(s+a,nextInt());
				break;
			case 'H':
				a=nextInt();
				has(s[a],nextInt());
				break;
			case 'U':
				c=nextInt();
				a=nextInt();
				s[c]=setUnion(s[a],s[nextInt()]);
				break;
			case 'I':
				c=nextInt();
				a=nextInt();
				s[c]=setIntersect(s[a],s[nextInt()]);
				break;
			case 'D':
				c=nextInt();
				a=nextInt();
				s[c]=setDifference(s[a],s[nextInt()]);
				break;
			default:
				puts("END");
				return 0;
		}
	}
}
