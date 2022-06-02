#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int *list=(int *)calloc(n,sizeof(int));
        for(int x=0;x<n;x++){
            scanf("%d",&list[x]);
        }
        int not_ok=0;
        int *save=(int *)calloc(n+1,sizeof(int));
        for(int x=0;x<(n-1);x++){
            if(abs(list[x]-list[x+1])>(n-1)){
                not_ok=1;
                break;
            }
            else if(abs(list[x]-list[x+1])==0){
                not_ok=1;
                break;
            }
            else{
                save[abs(list[x]-list[x+1])]+=1;
            }
        }
        for(int x=1;x<n;x++){
            if(save[x]==0){
                not_ok=1;
                break;
            }
        }
        printf("%s",not_ok==1?"Not jolly\n":"Jolly\n");
        free(list);
        free(save);
    }
    return 0;
}
