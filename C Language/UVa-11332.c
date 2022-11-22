#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char list[99]={'\0'};
    while(scanf("%s",list)!=EOF){
        if(strlen(list)==1 && list[0]=='0'){
            break;
        }
        int sum=0;
        int take=0;
        for(int x=0;x<strlen(list);x++){
            sum+=list[x]-'0';
            if(sum>=10){
                take=sum/10;
                sum%=10;
                sum+=take;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
