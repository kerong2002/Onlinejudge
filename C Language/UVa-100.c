#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a>b)?(a):(b))
int cycle(int n,int count){
    if(n==1){
        return ++count;
    }
    else{
        if(n%2!=0){
            return cycle(3*n+1,++count);
        }
        else{
            return cycle(n/2,++count);
        }
    }
}
int main(){
    int i,j;
    while(scanf("%d %d",&i,&j)!=EOF){
        int max_cycle=-1;
        int ii,jj;
        ii=(i>j)?(j):(i);
        jj=(i>j)?(i):(j);
        for(int x=ii;x<=jj;x++){
            int round_cycle=cycle(x,0);
            if(max_cycle<round_cycle){
                max_cycle=max(max_cycle,round_cycle);
            }
        }
        printf("%d %d %d\n",i,j,max_cycle);
    }
    return 0;
}
