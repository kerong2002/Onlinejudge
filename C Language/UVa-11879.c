#include<stdio.h>
#include<string.h>
int main(){
    char n[200]={'\0'};
    while(scanf("%s",n)!=EOF){
        if(n[0]=='0' && strlen(n)==1){
            break;
        }
        int divide=0;
        for(int x=0;x<strlen(n);x++){
            divide=divide * 10 +(n[x]-'0');
            divide%=17;
        }
        printf("%d\n",divide?0:1);
    }
    return 0;
}
