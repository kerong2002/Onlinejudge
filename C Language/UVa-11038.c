#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max(a,b) ((a>=b)?(a):(b))
#define min(a,b) ((a>=b)?(b):(a))
long long int count(long long int number){
    long long int total=0;
    long long int set=number;
    long long int run;
    long long int bonus=1;
    while(set>=10){
        run=set%10;
        set/=10;
        total+=(run>0)?(set*bonus):((set-1)*bonus+number%bonus+1);
        bonus*=10;
    }
    return total;
}
int main(){
    long long int f,s,m,n;
    while(scanf("%lld%lld",&f,&s)!=EOF){
        if(f==-1 && s==-1){
            break;
        }
        n=max(f,s);
        m=min(f,s);
//        long long int M_count=count(m);
//        long long int N_count=count(n);
//        printf("%lld ",N_count);
//        printf("%lld",M_count);
        long long int answer=count(n)-count(m-1);
        if(m==0){
            answer+=1;
        }
    //    printf("%lld %lld\n",count(n),count(m-1));
        printf("%lld\n",answer);
    }
    return 0;
}
//
