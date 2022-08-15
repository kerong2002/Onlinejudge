#include<stdio.h>
#include<math.h>
int main(){
    int n,A,F;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&A,&F);
        while(F--){
            for(int h=1;h<A*2;h++){
                for(int x=A;x>abs(A-h);x--){
                    printf("%d",A-abs(A-h));
                }
                printf("\n");
            }
            if(F){
                puts("");
            }
        }
        if(n){
            puts("");
        }
    }
    return 0;
}
