#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define big 99
int main(){
    int n,run;
    int case_cnt=1;
    while(scanf("%d%d",&n,&run)!=EOF){
        if(n==0 && run==0){
            break;
        }
        char **people=(char **)malloc(n*sizeof(char *));
        for(int y=0;y<n;y++){
            people[y]=(char *)malloc(big*sizeof(char));
        }
        int check[n];
        memset(check,0,n*sizeof(int));
        //確定所有人
        for(int x=0;x<n;x++){
            scanf("%s",people[x]);
        }
        //借款紀錄
        for(int x=0;x<run;x++){
            int money=0;
            char borrower[big];
            char repayer[big];
            scanf("%s%s%d",borrower,repayer,&money);
            for(int x=0;x<n;x++){
                if(strcmp(borrower,people[x])==0){
                    check[x]-=money;
                    break;
                }
            }
            for(int x=0;x<n;x++){
                if(strcmp(repayer,people[x])==0){
                    check[x]+=money;
                    break;
                }
            }
        }
        printf("Case #%d\n",case_cnt);
        char **output=(char **)malloc(n*sizeof(char *));
        for(int y=0;y<n;y++){
            output[y]=(char *)malloc(999*sizeof(char));
        }
        //先以最大金額還款做處理
        int money_run=0;
        for(int x=0;x<n;x++){
            int max=-1;
            int min=INT_MAX;
            int first;
            int second;
            for(int x=0;x<n;x++){
                if(check[x]>max){
                    max=check[x];
                    first=x;
                }
                if(check[x]<min){
                    min=check[x];
                    second=x;
                }
            }
            if(min!=0 && max!=0){
                if(max>=abs(min)){
                    sprintf(output[money_run],"%s %s %d\n",people[first],people[second],abs(min));
                    check[first]+=min;
                    check[second]-=min;
                    money_run+=1;
                }
                else{
                    sprintf(output[money_run],"%s %s %d\n",people[first],people[second],abs(max));
                    check[first]-=max;
                    check[second]+=max;
                    money_run+=1;
                }
            }
        }
        //按照輸入人名做依序輸出
        for(int y=0;y<n;y++){
            int size=strlen(people[y]);
            for(int x=0;x<money_run;x++){
                if(strncmp(output[x],people[y],size)==0){
                    printf("%s",output[x]);
                }
            }
        }
        case_cnt+=1;
        printf("\n");
        for(int y=0;y<n;y++){
            free(people[y]);
            free(output[y]);
        }
        free(output);
        free(people);
    }
    return 0;
}
/*
2 1
Donald
Dagobert
Donald Dagobert 15
4 4
John
Mary
Cindy
Arnold
John Mary 100
John Cindy 200
Cindy Mary 40
Cindy Arnold 150
*/
