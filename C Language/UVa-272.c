#include<stdio.h>
#include<string.h>
int main(){
    char save[9999]={'\0'};
    int find=0;
    while(scanf("%[^\n]%*c",save)!=EOF){
        for(int x=0;x<strlen(save);x++){
            if(save[x]=='"'&&find==0){
                printf("``");
                find=1;
            }
            else if(save[x]=='"'&&find==1){
                printf("''");
                find=0;
            }
            else{
                printf("%c",save[x]);
            }
        }
        puts("");
    }
    return 0;
}
