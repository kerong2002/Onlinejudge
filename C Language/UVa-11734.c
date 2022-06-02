#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int n;
    scanf("%d%*c",&n);
    int case_n=1;
    while(n--){
        char team[999]={'\0'};
        char judge[999]={'\0'};
        scanf("%[^\n]",team);
        getchar();
        scanf("%[^\n]",judge);
        getchar();
        printf("Case %d: ",case_n++);
        if(strcmp(team,judge)==0){
            printf("Yes\n");
        }
        else if(strcmp(team,judge)!=0 && (strlen(team)==strlen(judge))){
            printf("Wrong Answer\n");
        }
        else if(strcmp(team,judge)!=0 && (strlen(team)>strlen(judge))){
            char save_sentence[999]={'\0'};
            char *cut=" ";
            char *set=team;
            char *token=strtok(set,cut);
            while(token!=NULL){
                strcat(save_sentence,token);
                token=strtok(NULL,cut);
            }
            if(strlen(save_sentence)==strlen(judge)){
                if(strcmp(save_sentence,judge)==0){
                    printf("Output Format Error\n");
                }
                else{
                    printf("Wrong Answer\n");
                }
            }
            else{
                printf("Wrong Answer\n");
            }
        }
        else{
            printf("Wrong Answer\n");
        }
    }
    return 0;
}
