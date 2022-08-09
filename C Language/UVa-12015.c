#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int c=1;c<=T;c++){
        char **web=(char **)malloc(10*sizeof(char*));
        int *view=(int *)calloc(10,sizeof(int));
        int max=-1;
        for(int y=0;y<10;y++){
            web[y]=(char *)malloc(105*sizeof(char));
            scanf("%s",web[y]);
            scanf("%d",&view[y]);
            if(view[y]>max){
                max=view[y];
            }
        }
        printf("Case #%d:\n",c);
        for(int x=0;x<10;x++){
            if(view[x]==max){
                printf("%s\n",web[x]);
            }
        }
        for(int y=0;y<10;y++){
            free(web[y]);
        }
        free(view);
        free(web);
    }
    return 0;
}
