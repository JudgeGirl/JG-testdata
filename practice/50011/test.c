#include<stdio.h>
#include<string.h>
char data[202][102];
int datal[202];
char set[202];
int main()
{
  int datan;
  int wordl;
  int wordn;
  int i;
  int j;
  int k;
  int check;
  int head;
  char word[102];
  int c=0;
  char ans[102];
  scanf("%d",&datan);
  {
    for(i=0;i< datan;i++)
    {
      scanf("%s",data[i]);
      datal[i]=strlen(data[i]);
    }
  }
  scanf("%d",&wordn);
  {
    for(i=0;i< wordn;i++)
    {
      scanf("%s",word);
      c=0;
      wordl=strlen(word);
      printf("word: %s\n", word);
      for(j=0;j< wordn;j++)
      {
        printf("dict[%d]: %s\n", j, data[j]);
        set[j]=0;
        if (!strcmp(word,data[j])&&(c==0||c==2))
        {
          strcpy(ans,word);
          c=1;
        }
        else if (wordl==datal[j]&&c!=1)
        {
          check=0;
          for(k=0;k< wordl;k++)
          {
            if (data[j][k]!=word[k]) check++;
          }
          if (check<=1)
          {
            set[j]=1;
            c=2;
          }
        }
        else if (wordl-datal[j]==1&&c!=1)
        {
          check=0;
          head=0;
          for(k=0;k< wordl-1;k++)
          {
            if (head==0&&word[k]!=data[j][k])
            {
              check++;
              head++;
            }
            if (head&&word[k+1]!=data[j][k])
            {
              check++;
            }
          }
          if (check<=1)
          {
            set[j]=1;
            c=2;
          }
        }    
        else if (wordl-datal[j]==-1&&c!=1)
        {
          check=0;
          head=0;
          for(k=0;k< wordl;k++)
          {
            if (head==0&&word[k]!=data[j][k])
            {
              check++;
              head++;
            }
            if (head&&word[k]!=data[j][k+1])
            {
              check++;
            }
          }
          if (check<=1)
          {
            set[j]=1;
            c=2;
          }
        }    
      }
      if (c==1)   printf(">%s\n",ans);
      else if (c==0) printf("!%s\n",word);
      else if (c==2)
      {
        check=0;
        printf("?");
        for(j=0;j< datan;j++)
        {
          if (set[j]==1)
          {
            if (check) printf(" ");
            check++;
            printf("%s",data[j]);
          }
        }
        printf("\n");
      }
    }
  }
  return 0;
}
