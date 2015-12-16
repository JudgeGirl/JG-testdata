#include <stdio.h>

int find(int matrix[][100], const int n, const int m , int chosen, int check[], int people[]) {
  if (chosen == m+1) {
    for (int i = 1 ; i < m+1 ; i++)
      printf("%d%c", people[i], " \n" [i == m]) ;
    return 1 ;
  }
  if (m-chosen+1 > n-people[chosen-1]-1)
    return 0 ;
  for (int i = people[chosen-1]+1 ; i < n ; i++) {
    /*        for (int i = 0 ; i < chosen-1 ; i++)
     *                    printf("//%d%c", people[i], " \n" [i == chosen-1]) ;
     *                            printf("%d\n", people[chosen-1]) ;
     *                            */        if (!check[i]) {
       int flag = 1 ;
       for (int j = 1 ; j < chosen ; j++) {
         if (matrix[i][people[j]]) {
           flag = 0 ;
           break ;
         }
       }
       if (flag) {
         check[i] = 1 ;
         people[chosen] = i ;
         if (find(matrix, n, m, chosen+1, check, people))
           return 1 ;
         check[i] = 0 ;
         people[chosen] = 0 ;
       }
     }
  }
  return 0 ;
}

int main() {
  int m, n ;
  int matrix[100][100] ;
  while(scanf("%d %d", &n, &m) == 2) {
    //        printf(":))\n") ;
    //                int check[100] = {0} ;
    //                        int people[101] ;
    //                                for (int i = 0 ; i < 101 ; i++)
    //                                            people[i] = -1 ;
    //                                                    for (int i = 0 ; i < n ; i++)
    //                                                                for (int j = 0 ; j < n ; j++)
    //                                                                                scanf("%d", &matrix[i][j]) ;
    //                                                                                        if (!find(matrix, n, m, 1, check, people))
    //                                                                                                    printf("no solution\n") ;
    //                                                                                                        }
    //                                                                                                            return 0 ;
    //                                                                                                            }
