#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max(a,b) ((a>=b)?a:b)
int main(){
    int N;
    while(scanf("%d",&N)!=EOF && N){
        int input[10001]={0};
        for(int x=1;x<=N;x++){
            scanf("%d",&input[x]);
        }
        int dp[10001]={0};
        int win=0;
        for(int x=1;x<=N;x++){
            dp[x]=max(input[x],dp[x-1]+input[x]);
//            for(int y=1;y<=N;y++){
//                printf("%d ",dp[y]);
//            }
//            puts("");
            win=max(win,dp[x]);
        }
        if(win>0){
            printf("The maximum winning streak is %d.\n",win);
        }
        else{
            printf("Losing streak.\n");
        }
    }
    return 0;
}
