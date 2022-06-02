#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max_size 1000001
int mu[max_size], M[max_size],check[max_size];
void Riemann(){
    for(long long int y=2;y<max_size;y++){
        if(check[y]==0){
            long long int set=y*y;
            for(long long int x=y;x<max_size;x+=y){
                check[x]+=1;
                if(x%set==0){
                    mu[x]=-1;        //平方倍數關係
                }                   //not square free

            }
        }
        if(mu[y]==0 && check[y]%2==1){//square free
            mu[y]=-2;                 //針對偶數做更改
        }
        M[y]=M[y-1]+mu[y]+1;
    }
}

int main(){
    Riemann();
    int input;
    while(scanf("%d",&input)&&input){
        printf("%8d%8d%8d\n",input,mu[input]+1,M[input]+1);
    }
    return 0;
}
