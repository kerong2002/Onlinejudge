#include<stdio.h>
#include<stdlib.h>
#define swap(a,b) {a=a^b;b=a^b;a=a^b;}
int main(){
    int N;
    while(scanf("%d",&N)!=EOF){
        int *list=(int *)calloc(N,sizeof(int));
        for(int x=0;x<N;x++){
            scanf("%d",&list[x]);
        }
        int cnt=0;
        for(int y=0;y<N;y++){
            for(int x=N-1;x>y;x--){
                if(list[x]<list[x-1]){
                    swap(list[x],list[x-1]);
                    cnt+=1;
                }
            }
        }
        printf("Minimum exchange operations : %d\n",cnt);
    }
}
