#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int x=0;x<n;x++){
        char *list=(char *)malloc(99*sizeof(char));
        scanf("%s",list);
        long long int sum=1;
        int english[26]={0};
        for(int x=0;x<strlen(list);x++){
            sum*=(x+1);
            english[list[x]-'A']+=1;
        }
        for(int x=0;x<26;x++){
            long long int div=1;
            if(english[x]>=2){
                for(int y=1;y<=english[x];y++){
                    div*=y;
                }
                sum/=div;
            }
        }
        printf("Data set %d: %lld\n",x+1,sum);
        free(list);
    }
    return 0;
}
