#include<stdio.h>
#include<string.h>
#define max(a,b) ((a>=b)?a:b)
int main(){
    char save[1001]={'\0'};
    int run=0;
    while(gets(save)){
        if(run) puts("");
        run=1;
        int list[130]={0};
        for(int x=0;x<strlen(save);x++){
            list[save[x]]+=1;
        }
        for(int y=1;y<=strlen(save);y++){
            for(int x=127;x>=32;x--){
                if(list[x]==y){
                    printf("%d %d\n",x,list[x]);
                }
            }
        }
    }
    return 0;
}
