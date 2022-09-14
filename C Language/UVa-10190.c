#include<stdio.h>
#include<stdbool.h>
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0 || m==0 || m==1 || n<m){
            printf("Boring!\n");
            continue;
        }
        int save_n=n;
        bool boring=false;
        while(n>0){
            if(n%m!=0 && n!=1){
                printf("Boring!");
                boring=true;
                break;
            }
            n/=m;
        }
        if(!boring){
            while(save_n>0){
                printf(save_n!=1?"%d ":"%d",save_n);
                save_n/=m;
            }
        }
        printf("\n");
    }
    return 0;
}
