#include<stdio.h>
#include<string.h>
int main(){
    int n;
    while(scanf("%d",&n)!=EOF && n){
        char binary[1000]={'\0'};
        int cnt=0;
        while(n>0){
            binary[cnt++]=n%2+'0';
            n/=2;
        }
        printf("The parity of ");
        int one=0;
        for(int x=cnt-1;x>=0;x--){
            printf("%c",binary[x]);
            if(binary[x]=='1'){
                one+=1;
            }
        }
        printf(" is %d (mod 2).\n",one);

    }
    return 0;
}
