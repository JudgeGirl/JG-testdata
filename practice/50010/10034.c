#include <stdio.h>

int main(){

    int i,j;
        char s[2000000];
            char replace[]="replace";
                char end[]="end";
                    char remove[]="remove";
                        char addhead[]="addhead";
                            char addtail[]="addtail";

                                scanf("%s",&s);

                                    while(1){
                                        //printf("enter\n");
                                        //
                                        //    char command[15];
                                        //        char *com_star=command;
                                        //            scanf("%s",&command);
                                        //                //printf("command=%s\n",command);
                                        //
                                        //                        if(strncmp(command,end,3)==0){
                                        //                                    break;
                                        //                                            }
                                        //                                                    else if(strncmp(command,replace,7)==0){
                                        //                                                                char a[2];
                                        //                                                                            char b[2];
                                        //
                                        //                                                                                        scanf("%s",&a);
                                        //                                                                                                    scanf("%s",&b);
                                        //
                                        //                                                                                                                int n = strlen(s);
                                        //                                                                                                                            for (i = 0; i < n; i++) {
                                        //                                                                                                                                            if(s[i]==a[0]){
                                        //                                                                                                                                                                s[i]=b[0];
                                        //                                                                                                                                                                                }
                                        //                                                                                                                                                                                            }
                                        //                                                                                                                                                                                                    }
                                        //                                                                                                                                                                                                            else if(strncmp(command,remove,6)==0){
                                        //                                                                                                                                                                                                                        char a[2];
                                        //
                                        //                                                                                                                                                                                                                                    scanf("%s",&a);
                                        //
                                        //                                                                                                                                                                                                                                                int n = strlen(s);
                                        //
                                        //                                                                                                                                                                                                                                                            for (i = 0; i < n; i++) {
                                        //                                                                                                                                                                                                                                                                            if(s[i]==a[0]){
                                        //                                                                                                                                                                                                                                                                                                j=i;
                                        //                                                                                                                                                                                                                                                                                                                    while(j<n-1){
                                        //                                                                                                                                                                                                                                                                                                                                            s[j]=s[j+1];
                                        //                                                                                                                                                                                                                                                                                                                                                                    j++;
                                        //                                                                                                                                                                                                                                                                                                                                                                                            //printf("s[j]=%c s[j+1]=%c n=%d j=%d",s[j],s[j+1],n,j-1);
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                    if((j+1)==n){
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                s[j]='\0';
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                            //printf("here\n");
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    }
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        }
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            i--;
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            }
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        }
                                        //
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                }
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        else if(strncmp(command,addhead,7)==0){
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    char a[2];
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                char temp[2];
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            scanf("%s",&a);
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        int n = strlen(s);
                                        //
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    for(i=n-1;0<=i;i--){
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    //temp[0]=s[i];
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    s[i+1]=s[i];
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    //printf("s[i]=%c\n",s[i]);
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                }
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            s[0]=a[0];
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    }
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            else if(strncmp(command,addtail,7)==0){
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        char a[2];
                                        //
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    scanf("%s",&a);
                                        //
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                int n = strlen(s);
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            //printf("n=%d",n);
                                        //
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            s[n]=a[0];
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            s[n+1]='\0';
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            //printf("ac\n");
                                        //
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        //int k = strlen(s);
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    //printf("k=%d",k);
                                        //
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            }
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    else{
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                printf("invalid command %s\n",command);
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            break;
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    }
                                        //
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        }
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            printf("%s\n",s);
                                        //
                                        //
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                return 0;
                                        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                }
                                        //
