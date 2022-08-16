#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    int run=1;
    while(scanf("%d",&n)!=EOF && n){
        int *list=(int *)calloc(n,sizeof(int));
        int sum=0;
        for(int x=0;x<n;x++){
            scanf("%d",&list[x]);
            sum+=list[x];
        }
        sum/=n;
        int cnt=0;
        for(int x=0;x<n;x++){
            if(list[x]>sum){
                cnt+=list[x]-sum;
            }
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",run++,cnt);
        free(list);
    }
    return 0;
}
