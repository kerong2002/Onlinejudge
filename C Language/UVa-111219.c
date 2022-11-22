#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int run;
    scanf("%d",&run);
    char data1[99]={'\0'};//current
    char data2[99]={'\0'};//birth
    for(int t=1;t<=run;t++){
        scanf("%s",data1);
        scanf("%s",data2);
        int y=0;
        int check=0;
        int mon1=(data1[3]-'0')*10+(data1[4]-'0');
        int mon2=(data2[3]-'0')*10+(data2[4]-'0');
        int day1=(data1[0]-'0')*10+(data1[1]-'0');
        int day2=(data2[0]-'0')*10+(data2[1]-'0');
        int year1=(data1[6]-'0')*1000+(data1[7]-'0')*100 + (data1[8]-'0')*10 + (data1[9]-'0');
        int year2=(data2[6]-'0')*1000+(data2[7]-'0')*100 + (data2[8]-'0')*10 + (data2[9]-'0');
        int bang=0;
        printf("Case #%d: ",t);
//        printf("%d",year1-year2);
        if(year2>year1){
            bang=1;
        }
        else if(year1==year2){
            if(mon2>mon1){
                bang=1;
            }
            else if(mon1==mon2){
                if(day2>day1){
                    bang=1;
                }
            }
        }
        if(bang==1){
            printf("Invalid birth date\n");
            continue;
        }

        if(mon1>mon2){
            check=1;
        }
        else if(mon1==mon2){
            if(day1>=day2){
                check=1;
            }
        }
// printf("@%d@\n",check);
        if(check==1){
            y=(year1-year2);
        }
        else {
            y=(year1-year2)-1;
        }
        if((year1-year2)==131 &&check==1){
            printf("Check birth date\n");
        }
        else if((year1-year2)>131){
            printf("Check birth date\n");
            continue;
        }
        else
//        if(strcmp(data1,data2)==0){
//            y+=1;
//        }
        printf("%d\n",y);
    }
    return 0;
}
