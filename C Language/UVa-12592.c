#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int N,Q;
    while(scanf("%d%*c",&N)!=EOF){
        char **list=(char **)calloc(2*N,sizeof(char *));
        char *ask=(char *)calloc(30,sizeof(char));
        for(int y=0;y<2*N;y++){
            list[y]=(char *)calloc(30,sizeof(char));
            scanf("%[^\n]%*c",list[y]);
        }
        scanf("%d%*c",&Q);
        while(Q--){
            scanf("%[^\n]%*c",ask);
            for(int x=0;x<2*N;x+=2){
                if(strlen(list[x])==strlen(ask)){
                    if(strcmp(list[x],ask)==0){
                        printf("%s\n",list[x+1]);
                    }
                }
            }
        }
        for(int y=0;y<2*N;y++){
            free(list[y]);
        }
        free(ask);
        free(list);
    }
    return 0;
}
