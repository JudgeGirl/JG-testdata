#include <stdio.h>
#include <string.h>
#include <ctype.h>
int n, arr[26]={0}, book[26][26]={{0}}, ans[40], count[26]={0};

void sort(int k, int len)
{
  if (k==len)
  {
    for (int i=0; i<len; i++)
      printf("%c", (char)(ans[i]+'a'));
    printf("\n");
    return;
  }


  for (int i=0; i<26; i++)
  {

    if (arr[i]>0)
    {
      int flag = 0;
      if (k>0)
        for (int j=0; j<count[ans[k-1]]; j++)
          if (book[ans[k-1]][j]==i)
          {
            flag = 1;
            break;
          }
      if (!flag)
      {
        ans[k] = i;
        arr[i]--;
        sort(k+1, len);
        arr[i]++;
      }

    }
  }
  return;
}

int main(void)
{
  char temp1[40],tmp1,tmp2, tmp3;
  int len, c1, c2;
  gets(temp1);
  len = strlen(temp1);
  for (int i=0; i<len; i++)
  {
      if( temp1[i] == '\r' ){
        printf("XX\n");
      }
      int k=temp1[i]-'a';
      arr[k]++;
  }
  scanf("%d", &n);
  for (int i=0; i<n; i++)
  {
    scanf("%c%c%c", &tmp1, &tmp2, &tmp3);
    c1=tmp2-'a';
    c2=tmp3-'a';
    book[c1][count[c1]] = c2;
    count[c1]++;
  }

  sort(0, len);
  //printf("%d %d\n",c1, c2);
  //for (int i=0; i<26; i++) 
  //printf("%d ", arr[i]);
  return 0;
}

