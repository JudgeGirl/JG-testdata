#include <bits/stdc++.h>
using namespace std;
vector< pair<int, int> > path;
const int ddx[] = {0, 0, 1, 1, 1, -1, -1, -1};
const int ddy[] = {1, -1, 0, 1, -1, 0, 1, -1};
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const char ds[4][16] = {"north", "east", "south", "west"};
int a, b, c, d, e;
int p, q, r, s, x, y, F;
int _dir(int x, int y, int a, int b) {
	return abs(a * x + b * y)%4;
}
int _gold(int x, int y, int c, int d, int e) {
	if (x == p && y == q)	{
		return 0; 
	}
	if (x == r && y == s)	{
		return 0; 
	}
	return abs(c * x + d * y)%e;
}
int _sim() {
	int dir = _dir(x, y, a, b);
	x += dx[dir], y += dy[dir];
	if (x == p && y == q) {
		x = r, y = s;
	} else if (x == r && y == s) {
		x = p, y = q;
	}
	return _gold(x, y, c, d, e);
}
void work() {
	int ret = _gold(x, y, c, d, e);
	for (int i = 0; i < F; i++)
		ret += _sim(), path.push_back(make_pair(x, y));
}
int main() {
	srand(time(NULL));
	int testcase = 1;
	while (testcase--) {
		a = rand()%10, b = rand()%10, c = rand()%10, d = rand()%10, e = rand()%10;
		x = rand()%100, y = rand()%100, F = 100;
		p = q = r = s = 10000;
		int tx = x, ty = y, tF = F;
		work();
		printf("%d %d %d %d %d\n", a, b, c, d, e);
		while (true) {
			pair<int, int> pp = path[rand()%path.size()];
			p = pp.first, q = pp.second;
			r = rand()%100, s = rand()%100;
			p = q = r = s = 10000;
			if (p == tx && q == ty)
				continue;
			if (r == tx && s == ty)
				continue;
			int ok = 1;
			for (int i = 0; i < 8; i++) {
				int tx, ty;
				tx = p + ddx[i], ty = q + ddy[i];
				if (tx == r && ty == s)
					ok = 0;
			}
			if (ok)
				break;
		}
		printf("%d %d %d %d\n", p, q, r, s);
		printf("%d %d %d\n", tx, ty, tF);
	}
	return 0;
}

