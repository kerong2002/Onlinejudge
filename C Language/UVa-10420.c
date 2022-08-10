#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int N;
    scanf("%d",&N);
    char country[2001][76]={'\0'};
    char name[76]={'\0'};
    int cnt[2001]={0};
    int run=0;
    for(int y=0;y<N;y++){
        scanf("%s",name);
        int find=0;
        for(int x=0;x<run;x++){
            if(strcmp(country[x],name)==0){
                cnt[x]+=1;
                find=1;
                break;
            }
        }
        if(find==0){
            strcpy(country[run],name);
            cnt[run++]+=1;
        }
        gets(name);
    }
    for(int y=0;y<run;y++){
        for(int x=y+1;x<run;x++){
            if(strcmp(country[y],country[x])>0){
                strcpy(name,country[y]);
                strcpy(country[y],country[x]);
                strcpy(country[x],name);
                N=cnt[y];
                cnt[y]=cnt[x];
                cnt[x]=N;
            }
        }
    }
    for(int x=0;x<run;x++){
        printf("%s %d\n",country[x],cnt[x]);
    }
    return 0;
}
