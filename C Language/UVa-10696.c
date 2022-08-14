#include<stdio.h>
int main(int argc,char *argv[]){
    int n;
    while(scanf("%d",&n)!=EOF&&n){
        if(n<=100){
            printf("f91(%d) = %d\n",n,91);
        }
        else{
            printf("f91(%d) = %d\n",n,n-10);
        }
    }
    return 0;
}
