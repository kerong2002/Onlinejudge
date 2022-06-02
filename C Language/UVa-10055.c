#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main(){
    long long int a,b;
    while(scanf("%lld %lld",&a,&b)!=EOF){
        printf("%lld\n",llabs(b-a));
    }
    return 0;
}
