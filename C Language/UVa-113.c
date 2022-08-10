#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int n;
    double p,k;
    while(scanf("%d%lf",&n,&p)!=EOF){
        k=exp(log(p)/n);
        printf("%.0f\n",k);
    }
    return 0;
}
