#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int T,n,cnt=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        char *input=(char *)malloc((n+1)*sizeof(char));
        scanf("%s",input);
        int answer=0;
        int go=-1;
        for(int x=0;x<n;x++){
            if(input[x]=='.'&&x>go){
                go=x+2;
                answer+=1;
            }
        }
        printf("Case %d: %d\n",cnt++,answer);
        free(input);
    }
    return 0;
}
