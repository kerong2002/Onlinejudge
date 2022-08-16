#include<stdio.h>
#include<string.h>
int main(){
    //(')ascii=39
    char english[90]={";@@@@M0,.9`12345678@L@-@@@@VXSWDFGUHJKNBIO@EARYCQZT@P]["};
    char save[999]={'\0'};
    while(scanf("%[^\n]%*c",save)!=EOF){
        for(int x=0;x<strlen(save);x++){
            if(save[x]>='\''){
                printf("%c",english[save[x]-'\'']);
            }
            else{
                printf("%c",save[x]);
            }
        }
        puts("");
    }
    return 0;
}
