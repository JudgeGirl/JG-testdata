#include <stdio.h>
#include <stdlib.h>

int main(){
	int a, b, c, d, e, p, q, r, s, x, y, F;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	scanf("%d %d %d %d", &p, &q, &r, &s);
	scanf("%d %d %d", &x, &y, &F);
	int res=abs(c*x+d*y)%e;
	while(F--){
		int dir = abs(a*x+b*y)%4;
		if(dir==0) {
			y += 1;
		} else if (dir==1) {
			x += 1;
		} else if (dir==2) {
			y -= 1;
		} else {
			x -= 1;
		}
		if (x==p && y==q) {
			x=r; y=s;
		} else if (x==r && y==s) {
			x=p; y=q;
		} else {
			res += abs(c*x + d*y) % e;
		}
	}
	printf("%d\n", res);
	printf("%d %d\n", x, y);
	return 0;
}
