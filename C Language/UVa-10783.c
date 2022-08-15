#include<stdio.h>
#include<math.h>
int main(){
    int T,a,b,N1,N2;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d%d",&a,&b);
        N2=pow((b+1)/2,2);
        N1=pow(a/2,2);
        printf("Case %d: %d\n",t,N2-N1);
    }
    return 0;
}
