#include<stdio.h>
#include<stdlib.h>
void fibonacci(int *list,long long int *bee){
    list[0]=1;
    list[1]=1;
    for(int x=2;x<46;x++){
        list[x]=list[x-1]+list[x-2];
    }
    bee[0]=0;
    for(int x=1;x<46;x++){
        bee[x]=bee[x-1]+list[x-1];
    }
}
int main(){
    int *list=(int *)calloc(46,sizeof(int));
    long long int *bee=(long long int *)calloc(46,sizeof(long long int));
    fibonacci(list,bee);
    int N;
    while(scanf("%d",&N)!=EOF){
        if(N<0) break;
        printf("%lld %lld\n",bee[N],bee[N+1]);
    }
    return 0;
}
