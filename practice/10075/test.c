#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct account {
    int balance;
    int accountNum;
    int zipcode;
    int age;
} Account;


int compare1 (const void *data1 ,const void *data2)
{
    Account *ptr1 = (Account *) data1 ;
    Account *ptr2 = (Account *) data2 ;
    if(ptr1->accountNum > ptr2->accountNum)
        return 1 ;
     if(ptr1->accountNum < ptr2->accountNum)
        return -1 ;
         return 0 ;
}
int compare2 (const void *data1 ,const void *data2)
{
    Account *ptr1 = (Account *) data1 ;
    Account *ptr2 = (Account *) data2 ;
    if(ptr1->zipcode > ptr2->zipcode)
        return 1 ;
     if(ptr1->zipcode < ptr2->zipcode)
        return -1 ;
        return 0 ;
}


int compare3 (const void *data1 ,const void *data2)
{
    Account *ptr1 = (Account *) data1 ;
    Account *ptr2 = (Account *) data2 ;
    if(ptr1->age > ptr2->age)
        return 1 ;
     if(ptr1->age < ptr2->age)
        return -1 ;
         return 0 ;
}



int main()
{
    int i ,k  ;
    char n[100] ;
    scanf("%s",&n) ;
    FILE *fp ;
    Account a[100000] ;
    fp= fopen(n,"rb") ;
    assert(fp!=NULL) ;
    k= sizeof(fp)  ;
    fread (a,sizeof(Account),100000,fp);
    fclose(fp) ;
    qsort(a,k+1,sizeof(Account),compare1);
    printf("account, age, zipcode, balance\n");
    for(i=0 ; i<k+1 ;i++)
    {
        printf("%d, %d, %d, %d\n",a[i].accountNum , a[i].age ,a[i].zipcode,a[i].balance);

    }
    int sum[k+1] , zipnumber[k+1];
    int l ;
    #if SORTBY == ZIPCODE
    l=0 ;
    qsort(a,k+1,sizeof(Account),compare2);
    sum[0]= a[0].balance ;
    zipnumber[0] = a[0].zipcode ;

    for(i=1 ;i< k+2 ;i++){
        if(a[i].zipcode == a[i-1].zipcode){
            sum[l] +=  a[i].balance;
        }
        else
        {
            l++ ;
            sum[l] =  a[i].balance ;
            zipnumber[l] = a[i].zipcode ; }
    }
    printf("zipcode, sum_balance\n");
    for(i=0 ; i <l ; i++ ){
        printf("%d, %d\n",zipnumber[i], sum[i]);
    }

    #endif // SORTBY

    #if SORTBY == AGE
     l=0 ;
    qsort(a,k+1,sizeof(Account),compare3);
    sum[0]= a[0].balance ;
    zipnumber[0] = a[0].age ;

    for(i=1 ;i< k+2 ;i++){
        if(a[i].age == a[i-1].age){
            sum[l] +=  a[i].balance ;
        }
        else
        {
            l++ ;
            sum[l] =  a[i].balance ;
            zipnumber[l] = a[i].age ; }
    }
    printf("age, sum_balance\n");
    for(i=0 ; i <l ; i++ ){
        printf("%d, %d\n",zipnumber[i], sum[i]);
    }
    #endif // AGE
    return 0 ;
}



