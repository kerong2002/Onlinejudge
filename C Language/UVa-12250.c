#include<stdio.h>
#include<string.h>
int main(){
    char input[30]={'\0'};
    int cnt=1;
    while(scanf("%s",input)!=EOF){
        if(strcmp("#",input)==0){
            break;
        }
        printf("Case %d: ",cnt++);
        if(strcmp("HELLO",input)==0){
            printf("ENGLISH\n");
        }
        else if(strcmp("HOLA",input)==0){
            printf("SPANISH\n");
        }
        else if(strcmp("HALLO",input)==0){
            printf("GERMAN\n");
        }
        else if(strcmp("BONJOUR",input)==0){
            printf("FRENCH\n");
        }
        else if(strcmp("CIAO",input)==0){
            printf("ITALIAN\n");
        }
        else if(strcmp("ZDRAVSTVUJTE",input)==0){
            printf("RUSSIAN\n");
        }
        else{
            printf("UNKNOWN\n");
        }
    }
    return 0;
}
