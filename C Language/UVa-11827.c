#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define big(a,b) ((a>=b)?a:b)
int gcd(int a,int b){
  if( a != 0 && b != 0 ){
    while((a %= b) && (b %= a));
  }
  return a + b;
}
int main(){
    int n;
    scanf("%d%*c",&n);
    while(n--){
        char set[9999]={'\0'};
        char cut[999][99]={'\0'};
        int cnt=0;
        scanf("%[^\n]%*c",set);
        char *pick=strtok(set," ");
        while(pick!=NULL){
            strcpy(cut[cnt++],pick);
            pick=strtok(NULL," ");
        }
        int *list=(int *)calloc(cnt,sizeof(int));
        for(int x=0;x<cnt;x++){
            list[x]=atoi(cut[x]);
        }
        int max=-1;
        for(int x=0;x<cnt;x++){
            for(int y=x+1;y<cnt;y++){
                max=big(max,gcd(list[x],list[y]));
            }
        }
        printf("%d\n",max);
        free(list);
    }
    return 0;
}
