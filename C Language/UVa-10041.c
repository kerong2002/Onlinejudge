#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int r;
        scanf("%d",&r);
        int *relative=(int *)calloc(r,sizeof(int));
        int distant=0;
        int midden=0;
        for(int x=0;x<r;x++){
            scanf("%d",&relative[x]);
        }
        for(int y=0;y<r;y++){
            for(int x=y+1;x<r;x++){
                if(relative[y]>relative[x]){
                    int tmp=relative[y];
                    relative[y]=relative[x];
                    relative[x]=tmp;
                }
            }
        }
        midden=(r%2==0)?((relative[r/2]+relative[r/2-1])/2):(relative[r/2]);
        for(int x=0;x<r;x++){
            distant+=abs(relative[x]-midden);
        }
        printf("%d\n",distant);
        free(relative);
    }
    return 0;
}
