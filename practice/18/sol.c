#include <stdio.h>
const int INF = 2147483647;
 
int map[1010][1010];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int main(){
    int res = 0;
    int y,x;
    scanf("%d %d",&y,&x);
    for(int i=1;i<=y;i++)
        for(int j=1;j<=x;j++)
            scanf("%d",&map[i][j]);
    for(int i=0;i<=y+1;i++)
        map[i][x+1] = map[i][0] = -100;
    for(int i=0;i<=x+1;i++)
        map[y+1][0] = map[0][i] = -100;
    for(int i=1;i<=y;i++)
        for(int j=1;j<=x;j++){
            int high = 1;
            for(int d=0;d<4;d++)
                if(map[i+dy[d]][j+dx[d]] >= map[i][j])
                    high = 0;
            if(high) res++;
        }
    printf("%d\n",res);
    return 0;
}
