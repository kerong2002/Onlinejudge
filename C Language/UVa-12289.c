#include<stdio.h>
#include<string.h>
int main(){
    int n;
    char word[10]={'\0'};
    scanf("%d",&n);
    while(n--){
        scanf("%s",word);
        if(strlen(word)==5){
            printf("3\n");
        }
        else{
            int one=0;
            if(word[0]=='o'){
                one+=1;
            }
            if(word[1]=='n'){
                one+=1;
            }
            if(word[2]=='e'){
                one+=1;
            }
            if(one>=2){
                printf("1\n");
            }
            else{
                printf("2\n");
            }
        }
    }
    return 0;
}
