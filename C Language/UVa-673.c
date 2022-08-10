#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int n;
    scanf("%d%*c",&n);
    while(n--){
        char stack[1000]={'\0'};
        char save[1000]={'\0'};
        gets(save);
        if(strlen(save)==1 && save[0]==' '){
            printf("Yes\n");
            continue;
        }
        int cnt=0;
        int not_ok=0;
        for(int x=0;x<strlen(save);x++){
            if(save[x]=='('){
                stack[cnt++]='(';
            }
            else if(save[x]=='['){
                stack[cnt++]='[';
            }
            else if(save[x]==')'){
                if(stack[cnt-1]=='('){
                    stack[--cnt]='\0';
                }
                else{
                    not_ok=1;
                    break;
                }
            }
            else if(save[x]==']'){
                if(stack[cnt-1]=='['){
                    stack[--cnt]='\0';
                }
                else{
                    not_ok=1;
                    break;
                }
            }
        }
        printf("%s\n",not_ok==1 || cnt!=0?"No":"Yes");
    }
    return 0;
}
