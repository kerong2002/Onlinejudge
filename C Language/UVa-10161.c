#include<stdio.h>
#include<math.h>
int main(){
    int n;
    while(scanf("%d",&n)!=EOF && n){
        int s=ceil(sqrt(n));
        int m=s*(s-1)+1;
        if(s%2){
            if(n>=m){
                printf("%d %d\n",s-(n-m),s);
            }
            else{
                printf("%d %d\n",s,s-(m-n));
            }
        }
        else{
            if(n>=m){
                printf("%d %d\n",s,s-(n-m));
            }
            else{
                printf("%d %d\n",s-(m-n),s);
            }
        }
    }
    return 0;
}
