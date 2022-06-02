#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max(a,b) ((a>b)?(a):(b))
void reverse(char list[],char rev[]){
    int count=0;
    for(int x=strlen(list)-1;x>=0;x--){
        rev[count]=list[x];
        count+=1;
    }
}
int add(char f[],char s[]){
    int f_size=strlen(f);
    int s_size=strlen(s);
    int max_size=max(f_size,s_size);
    int done=0;
    int carry=0;
    int f_int=0;
    int s_int=0;
    for(int x=0;x<max_size+2;x++){
        if(f[x]=='\0' && s[x]=='\0' && carry==0){
            break;
        }
        else{
            if(f[x]>='0'){
                f[x]=f[x]-'0';
            }
            if(s[x]>='0'){
                s[x]=s[x]-'0';
            }
            carry=(f[x]+s[x]+carry)/10;
            if(carry>0){
                done+=1;
            }
        }
    }
    return done;
}
int main(){
    char f[999]={'\0'};
    char s[999]={'\0'};
    while(scanf("%s %s",f,s)!=EOF){
        if(strlen(f)==1 && strlen(s)==1 && f[0]=='0' && s[0]=='0'){
            break;
        }
        char rev_f[999]={'\0'};
        char rev_s[999]={'\0'};
        reverse(f,rev_f);
        reverse(s,rev_s);
        int set_done=add(rev_f,rev_s);
        if(set_done==0){
            printf("No carry operation.\n");
        }
        else{
            if(set_done==1){
                 printf("%d carry operation.\n",set_done);
            }
            else{
                printf("%d carry operations.\n",set_done);
            }
        }
    }
    return 0;
}
