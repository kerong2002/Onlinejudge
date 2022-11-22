#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a,const void *b){
    return (*(int *)a-*(int *)b);
}
int main(){
    char one[99]={'\0'};
    char two[99]={'\0'};
    while(scanf("%s",one)!=EOF){
        scanf("%s",two);
        int o[26]={0};
        int t[26]={0};
        for(int x=0;x<strlen(one);x++){
            o[one[x]-'A']+=1;
            t[two[x]-'A']+=1;
        }

        qsort(o,26,sizeof(int),cmp);
        qsort(t,26,sizeof(int),cmp);
        int nn=0;
        for(int y=25;y>=0;y--){
//            printf("%d %d\n",o[y],t[y]);
            if(o[y]!=t[y]){
                 nn=1;
                 break;
            }
        }
        if(nn==0){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
