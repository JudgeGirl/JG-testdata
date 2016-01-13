#include <stdio.h>


void print(int board[100][100],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(board[i][j]>=100)
                printf("o");
            else
                printf(".");
        }
        printf("\n");
    }
    return;
}

int piece(int n,int m,int k,int board[100][100],int a[20],int b[20],int c[20],int d[20])
{
    int i,j,ii,jj,kk,ll;
    if(m==0)
        return 1;
    for(i=0;i<n;i++)
    {
       for(j=0;j<n;j++)
       {
           if(a[i]<k&&b[j]<k&&c[i-j+20]<k&&d[i+j]<k&&board[i][j]==0)
           {
               a[i]+=1;
               b[j]+=1;
               c[i-j+20]+=1;
               d[i+j]+=1;
               board[i][j]+=100;
               //printf("%d %d\n",i,j);
               if(piece(n,m-1,k,board,a,b,c,d)==1)
                   return 1;
               else
               {
                   a[i]-=1;
                   b[j]-=1;
                   c[i-j+20]-=1;
                   d[i+j]-=1;
                   board[i][j]-=100;
               }

           }
       }
    }
    return 0;
}

int main()
{
    int n,m,k;
    int board[100][100];
    int a[20];
    int b[20];
    int c[40];
    int d[40];
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<20;i++)
        {
            a[i]=0;
            b[i]=0;
        }
        for(i=0;i<40;i++)
        {
            c[i]=0;
            d[i]=0;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
               board[i][j]=0;
        }
        scanf("%d",&m);
        scanf("%d",&k);
        if(piece(n,m,k,board,a,b,c,d)==1)
            print(board,n);
        else
        {
            printf("N");
            printf("\n");
        }
    }
    return;
}



