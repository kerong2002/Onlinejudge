#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<limits.h>
#include<math.h>
int max=1;
int prime[5000];
void pick(){
    prime[0]=2;
    for(int x=3;x<2001;x++){
        int found=0;
        for(int y=0;y<max;y++){
            if(x%prime[y]==0){
                found=1;
                break;
            }
            if(found!=1 && y==max-1){
                prime[max]=x;
                max++;
            }
        }
    }
}
//0-9,17-42,49-74
//0-9, A-Z, a-z
//303
int main(){
    pick();
    int T;
    int run=1;
    scanf("%d",&T);
    while(T--){
        int *list=(int *)calloc(75,sizeof(int));
        char save[2020]={'\0'};
        scanf("%s",save);
        for(int x=0;x<strlen(save);x++){
            if(save[x]>='0' && save[x]<='9'){
                list[save[x]-'0']+=1;
            }
            else if(save[x]>='A' && save[x]<='Z'){
                list[save[x]-'0']+=1;
            }
            else if(save[x]>='a' && save[x]<='z'){
                list[save[x]-'0']+=1;
            }
        }
        int find=0;
        for(int x=0;x<75;x++){
            if(list[x]>=2 &&find==0){
                for(int s=0;s<max;s++){
                    if(prime[s]>list[x]){
                        continue;
                    }
                    if(list[x]==prime[s]){
                        printf("Case %d: %c",run++,x+'0');
                        find=1;
                    }
                }
            }
            else if(list[x]>=2&&find==1){
                for(int s=0;s<max;s++){
                    if(prime[s]>list[x]){
                        continue;
                    }
                    if(list[x]==prime[s]){
                        printf("%c",x+'0');
                    }
                }

            }
        }
        if(find==0){
            printf("Case %d: empty\n",run++);
        }
        else{
            puts("");
        }
        free(list);
    }
    return 0;
}
