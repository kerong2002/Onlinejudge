#include<stdio.h>
int main(){
    int n,sum,minus,a,b;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&sum,&minus);
        a=(sum+minus)/2;
        b=(sum-minus)/2;
        if(b<0||a<0 ||(a+b)!=sum){
            printf("impossible\n");
        }
        else{
            printf("%d %d\n",a,b);
        }
    }
    return 0;
}
