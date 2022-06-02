#include<stdio.h>
int main(){
    int list[1001]={0};
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=i;j++){
            if(i%j==0){
                list[i]+=j;
            }
        }
    }
    int n,i=1;
    while(scanf("%d",&n)!=EOF){
        if (n==0) break;
        int find=0;
        for(int j=1000;j>0;j--){
            if(list[j]==n){
                printf("Case %d: %d\n",i,j);
                find=1;
                break;
            }
        }
        if(find==0) printf("Case %d: -1\n",i);
        i++;
    }
    return 0;
}
