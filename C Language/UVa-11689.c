#include<stdio.h>
#include<stdlib.h>
int main(){
    int N;
    scanf("%d",&N);
    while(N--){
        int e,f,c;
        scanf("%d%d%d",&e,&f,&c);
        int bottle=e+f;
        int drink=0;
        while(bottle>=c){
            bottle-=c;
            bottle+=1;
            drink+=1;
        }
        printf("%d\n",drink);
    }
    return 0;
}
