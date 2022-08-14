#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char save[999]={'\0'};
    int n;
    while(scanf("%s",save)!=EOF){
        if(save[0]=='-') break;
        if(save[1]=='x'){
            sscanf(save,"%x",&n);
            printf("%d\n",n);
        }
        else{
            printf("0x%X\n",atoi(save));
        }
    }
    return 0;
}
