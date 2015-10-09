#include <bits/stdc++.h>
using namespace std;

int main() {
        srand(time(NULL));
        int n = rand()%100+1, m = rand()%100+1;
        printf("%d %d\n", n, m);
        for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
	                int x = rand()%1000 + 1;
                	printf("%d%c", x, i == m-1 ? '\n' : ' ');
		}
        }
        return 0;
}

