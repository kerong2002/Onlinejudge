#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char N[1002]={'\0'};
    while(scanf("%s",N)!=EOF){
        if(strlen(N)==1 &&N[0]=='0') break;
        int minus=0;
        for(int x=0;x<strlen(N);x++){
            if(x%2==0){
                minus-=(N[x]-'0');
            }
            else{
                minus+=(N[x]-'0');
            }
        }
        if(abs(minus)%11==0){
            printf("%s is a multiple of 11.\n",N);
        }
        else{
            printf("%s is not a multiple of 11.\n",N);
        }

    }
    return 0;
}
