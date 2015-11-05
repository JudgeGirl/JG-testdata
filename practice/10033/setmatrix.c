#include <stdio.h>

void processSetMatrix(int ***ptr){
  int isPrint = 0;
  for( int i = 0 ; ptr[i] != NULL ; i++ ){
    for( int j = 0 ; ptr[i][j] != NULL ; j++ ){
      for( int k = 0 ; ptr[i][j][k] != 0 ; k++ ){
        if( isPrint ){
          printf(" ");
        }
        printf("%d", ptr[i][j][k]);
        isPrint = 1;
      }
    }
  }
  printf("\n");

}
