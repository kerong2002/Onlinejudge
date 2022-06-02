#include<stdio.h>
#include<stdlib.h>
int main(){
    int run;
    scanf("%d",&run);
    while(run--){
        int size;
        scanf("%d",&size);
        int *list=(int*)calloc(size,sizeof(int));
        for(int x=0;x<size;x++){
            scanf("%d",&list[x]);
        }
        int sum=0;
        for(int j=1;j<size;j++){
            for(int i=0;i<j;i++){
                if(list[j]>=list[i]){
                    sum+=1;
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
