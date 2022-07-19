#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d%*c",&n);
    while(n--){
        char list[30]={'\0'};
        scanf("%[^\n]%*c",list);
        int sum=0;
        int cnt=0;
        for(int x=0;x<strlen(list);x++){
            if(list[x]==32) continue;
            if(cnt%2==0){
                int pick=2*(list[x]-'0');
                while(pick>0){
                    sum+=pick%10;
                    pick/=10;
                }
            }
            else{
                sum+=list[x]-'0';
            }
            cnt+=1;
        }
        printf("%s\n",((sum)%10==0)?"Valid":"Invalid");
    }
    return 0;
}
