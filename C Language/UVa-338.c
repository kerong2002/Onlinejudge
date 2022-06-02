#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max(a,b) ((a>b)?(a):(b))
void reverse(char list[],char rev[]){
    int count=0;
    for(int x=strlen(list)-1;x>=0;x--){
        rev[count]=list[x];
        count+=1;
    }
}
int main(){
    char first[999]={'\0'};
    char second[999]={'\0'};
    while(scanf("%s %s",first,second)==2){//偵測是否開始
        int f_size=strlen(first);
        int s_size=strlen(second);
        int max_input_size=max(f_size,s_size);
        int out_offset=0;
        char R_first[999]={'\0'}; //反轉陣列
        char R_second[999]={'\0'};//反轉陣列
        reverse(first,R_first);
        reverse(second,R_second);
        int answer[99][99]={0};
        memset(answer,-1,99*99*sizeof(int));
        for(int y=0;y<s_size;y++){//乘數挑選
            int carry=0;
            for(int x=0;x<=f_size;x++){//被乘數挑選
                if(x==f_size){
                    if(carry==0){
                        break;
                    }
                    answer[y][y+x]=carry;
                    break;
                }
                int s_int,f_int;
                if(R_second[y]>='0'){
                    s_int=R_second[y]-'0';
                }
                if(R_first[x]>='0'){
                    f_int=R_first[x]-'0';
                }
//                printf("(%d,%d)",s_int,f_int);
                if(s_int*f_int+carry>=10){
                    answer[y][y+x]=(s_int*f_int+carry)%10;
                    carry=(s_int*f_int+carry)/10;
                }
                else{
                    answer[y][y+x]=(s_int*f_int+carry)%10;
                    carry=0;
                }
                if(y==s_size-1){
                    out_offset+=1;
                }
//                printf("   @%d@\n",carry);
            }
        }
//        printf("%d@\n",out_offset);
        int total[999]={0};
        for(int x=0;x<=(s_size-1+f_size);x++){
            for(int y=0;y<s_size;y++){
                if(answer[y][x]!=-1){
//                    printf("%d",answer[y][x]);
                    total[x]+=answer[y][x];
                }
            }
        }
        for(int x=0;x<=(s_size-1+f_size);x++){
            if(total[x]>=10){
                int carry_out=total[x]/10;
                total[x]%=10;
                total[x+1]+=carry_out;
            }
        }
        int set[999]={0};
        int set_cnt=0;
        int ok_out=0;
        for(int x=(s_size-1+f_size);x>=0;x--){
            if(total[x]!=0){
                ok_out=1;
            }
            if(ok_out==1){
                set[set_cnt]=total[x];
                set_cnt+=1;
            }
        }
        //統計輸出
//        for(int x=0;x<set_cnt;x++){
//            printf("%d",set[x]);
//        }
        //======<特別處理>=====
        int zero_problem=0;
        for(int x=0;x<s_size;x++){
            if(second[x]!='0'){
                zero_problem+=1;
            }
        }
        //====================
//        printf("@%d@",zero_problem);
        long long int INT_first=atoll(first);
        long long int INT_second=atoll(second);
        //印出被乘數
        if(f_size==1 && first[0]=='0'){
            for(int x=0;x<max_input_size-1;x++){
                printf(" ");
            }
        }
        else{
            for(int x=0;x<set_cnt-f_size;x++){
                printf(" ");
            }
        }
        printf("%lld\n",INT_first);
        //印出乘數
        if(s_size==1 && second[0]=='0'){
            for(int x=0;x<max_input_size-1;x++){
                printf(" ");
            }
        }
        else{
            for(int x=0;x<set_cnt-s_size;x++){
                printf(" ");
            }
        }
        printf("%lld\n",INT_second);
        for(int x=0;x<set_cnt-max_input_size;x++){
            printf(" ");
        }
        for(int x=0;x<max_input_size;x++){
            printf("-");
        }
        printf("\n");
//        printf("@%d,%d@\n",set_cnt,s_size-1+f_size);
        if((f_size==1&& first[0]=='0')||s_size==1&&second[0]=='0'){
            for(int x=0;x<max_input_size-1;x++){
                printf(" ");
            }
            printf("0\n");
        }
        else if(s_size==1){
            for(int y=0;y<s_size;y++){
                for(int x=(s_size-1+f_size);x>=0;x--){
                    if(answer[y][x]==-1){
                        printf("");
                    }
                    else{
                        printf("%d",answer[y][x]);
                    }
                }
                printf("\n");
            }
        }
        else{
            if(zero_problem==1){
                //印出結果
                for(int x=0;x<set_cnt;x++){
                    printf("%d",set[x]);
                }
                printf("\n");
            }
            else{
                for(int y=0;y<s_size;y++){
                    int is_zero=0;
                    for(int x=set_cnt-1;x>=0;x--){
                        if(answer[y][x]>0){
                            is_zero=1;
                            break;
                        };
                    }
                    if(is_zero==0){
                        continue;
                    }
                    for(int x=set_cnt-1;x>=y;x--){
                        if(answer[y][x]==-1){
                            printf(" ");
                        }
                        else{
                            printf("%d",answer[y][x]);
                        }
                    }
                    printf("\n");
                }
                //印出結果
                for(int x=0;x<set_cnt;x++){
                    printf("-");
                }
                printf("\n");
                for(int x=0;x<set_cnt;x++){
                    printf("%d",set[x]);
                }
                printf("\n");
            }
        }
        memset(first,'\0',999*sizeof(char));
        memset(second,'\0',999*sizeof(char));
        printf("\n");
    }
    return 0;
}
/*
121 100
*/

