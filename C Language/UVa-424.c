#include<stdio.h>
#include<string.h>
#define max(a,b) ((a>=b)?(a):(b))
void pick_zero(char list[]){
    char reverse[strlen(list)+1];
    memset(reverse,'\0',(strlen(list)+1)*sizeof(char));
    int zero=0;
    for(int x=0,cnt=0;x<strlen(list);x++){
        if(list[x]!='0'){
            zero=1;
        }
        if(zero==1){
            reverse[cnt++]=list[x];
        }
    }
    if(zero==0){
        reverse[0]=='0';
    }
    memset(list,'\0',sizeof(char)*9999);
    strcpy(list,reverse);
    return ;
}
void rev(char list[]){
    if(strlen(list)==0){
        return ;
    }
    char reverse[strlen(list)+1];
    memset(reverse,'\0',(strlen(list)+1)*sizeof(char));
    int cnt=0;
    for(int x=strlen(list)-1;x>=0;x--){
        reverse[cnt++]=list[x];
    }
    memset(list,'\0',sizeof(char)*9999);
    strcpy(list,reverse);
    return ;
}
void add(char answer[],char list[]){
    int max_size=max(strlen(answer),strlen(list));
    int carry=0;
    for(int x=0;x<=max_size;x++){
        if(x==max_size&&carry==0){
            continue;
        }
        int a=0,b=0;
        if(answer[x]>='0' && answer[x]<='9'){
            a=answer[x]-'0';
        }
        if(list[x]>='0' && list[x]<='9'){
            b=list[x]-'0';
        }
        answer[x]=(a+b+carry)%10+'0';
        carry=(a+b+carry)/10;
    }
    rev(answer);
    return ;
}
int main(){
    char save[99999]={'\0'};
    char answer[99999]={'\0'};
    while(scanf("%s",save)!=EOF){
        if(strlen(save)==1 && save[0]=='0'){
            break;
        }
        pick_zero(save);
        rev(save);
        rev(answer);
        add(answer,save);
        pick_zero(answer);
        memset(save,'\0',99999*sizeof(char));
//        printf("%s\n",answer);
    }
    printf("%s\n",answer);
    return 0;
}
