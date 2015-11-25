#include <stdio.h>

int subset(int numbers[], int n, int K, int S){
  int i;
  int temp[30];

  if(S==0 && K==0){
    return 1;
  }

  for(i=0;i<n;i++){
    if(numbers[i]){
      if((K-numbers[i])>=0){
        K-=numbers[i];
        temp[i]=numbers[i];
        numbers[i]=0;

        /*printf("Got %d\n",temp[i]);
         *                 printf("Now have");
         *                                 for(j=0;j<=i;j++){
         *                                                     if(!numbers[j]){
         *                                                                             printf(" %d",temp[j]);
         *                                                                                                 }
         *                                                                                                                 }
         *                                                                                                                                 printf("\n");
         *                                                                                                                                                 printf("S-1=%d K=%d\n",S-1,K);*/

        if(subset(numbers, n, K, S-1) && K>=0 && (S-1)>=0){
          return 1;
        }

        numbers[i]=temp[i];
        K+=numbers[i];

        /*printf("Decard %d\n",temp[i]);
         *                 printf("Now have");
         *                                 for(j=0;j<=i;j++){
         *                                                     if(!numbers[j]){
         *                                                                             printf(" %d",temp[j]);
         *                                                                                                 }
         *                                                                                                                 }
         *                                                                                                                                 printf("\n");
         *                                                                                                                                                 printf("S-1=%d K=%d\n",S-1,K);*/

      }
    }
  }
  return 0;
}


int main() {
  int  i,n, K, S;

  while (scanf("%d %d %d", &n, &K, &S) == 3) {
    int A[128];
    for (i = 0; i < n; i++)
      scanf("%d", &A[i]);
    printf("%d\n", subset(A, n, K, S ));
  }
  return 0;
}

