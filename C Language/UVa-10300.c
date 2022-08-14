#include<stdio.h>
int main(){
    long long int n,people,sum,mul,money;
    scanf("%lld",&n);
    while(n--){
        scanf("%lld",&people);
        sum=0;
        while(people--){
            mul=1;
            scanf("%lld%*lld",&money);
            mul*=money;
            scanf("%lld",&money);
            mul*=money;
            sum+=mul;
        }
        printf("%lld\n",sum);
    }

    return 0;
}
