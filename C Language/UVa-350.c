#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int Z,I,M,L;
    int case_cnt=1;
    while(scanf("%d%d%d%d",&Z,&I,&M,&L)==4 && (Z||I||M||L)){
        int list[10000]={0};
        int cycle=0;
        int length=0;
        while(list[L]==0){
            list[L]=cycle;
            L=(Z*L+I)%M;
            cycle+=1;
        }
        printf("Case %d: %d\n",case_cnt++,cycle-list[L]);
    }
    return 0;
}
