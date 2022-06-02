#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char square[70][999];
int main(){
    int count=0;
    for(int x=32;x<100;x++,count++){
        sprintf(square[count],"%d",(int)(x*x));
    }
//    for(int x=0;x<count;x++){
//        printf("%s\n",square[x]);
//    }
    int n;
    int case_n=1;
    scanf("%d",&n);
    while(n--){
        char number[9]={'\0'};
        char change[4][9]={'\0'};
        scanf("%s",number);
        for(int y=0;y<4;y++){
            strcpy(change[y],number);
        }
        int find=0;
        int offset=0;
        for(int y=0;y<4;y++){
            if(y==0){
                offset=1;
            }
            else if(y>0){
                offset=0;
            }
            for(int x=0+offset;x<=9;x++){
                change[y][y]='0'+x;
                for(int s=0;s<count;s++){
                    if(strcmp(square[s],change[y])==0 && strcmp(change[y],number)!=0){
                        find+=1;
                    }
                }
//                printf("%s\n",change[y]);
            }
        }
        printf("Case %d: %d\n",case_n++,find);
    }
    return 0;
}
/*8980
4489
6668
4021*/
