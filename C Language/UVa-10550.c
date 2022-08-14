#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int a,b,c,d;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF){
        if(! a&& !b && !c && !d){
            break;
        }
        int degree=1080;
        degree+=(a-b+40)%40*9;
        degree+=(c-b+40)%40*9;
        degree+=(c-d+40)%40*9;
        printf("%d\n",degree);
    }
    return 0;
}
