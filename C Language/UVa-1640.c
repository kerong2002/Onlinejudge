#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#define swap(a,b){\
    a=a^b;\
    b=a^b;\
    a=a^b;}
void caculate(int num,int *answer){
    int save_num=num;
    int size=0;
    while(save_num>0){
        save_num/=10;
        size+=1;
    }
    int *list=(int *)calloc(size,sizeof(int));
    save_num=num;
    for(int x=size-1;x>=0;x--){
        list[x]=save_num%10;
        save_num/=10;
    }
    int bonus = pow(10,size-1);
    for(int y=0;y<size;y++){
        //===========<膀セ┏计瞷计秖>==============
        for(int x=0;x<list[y];x++){
            answer[x] += bonus;
//            for(int x=0;x<=9;x++){
//                printf("%d ",answer[x]);
//            }puts("A");
        }
        //===========<碭糤Ω计>==============
        for(int x=0;x<10;x++){
            answer[x] += bonus/10*(size-y-1)*list[y];
        }
//        for(int x=0;x<=9;x++){
//                printf("%d ",answer[x]);
//            }puts("B");
        //===========<计瞷Ω计>==============
        if(y+1<size){
            answer[list[y]] += num % bonus;
//            printf("(%d,%d,%d,%d)\n",list[y],y,num,bonus);
//            for(int x=0;x<=9;x++){
//                printf("%d ",answer[x]);
//            }puts("C");
//            printf("%d %d %d\n",list[y],y,num%bonus);
        }
        answer[list[y]]++;
//        for(int x=0;x<=9;x++){
//                printf("%d ",answer[x]);
//            }puts("D");
        //============<矪瞶0>===============
        answer[0] -= bonus;
//        for(int x=0;x<=9;x++){
//                printf("%d ",answer[x]);
//            }puts("E");
        bonus /= 10;
    }
}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)&&n&&m){
        int *big=(int *)calloc(10,sizeof(int));
        int *small=(int *)calloc(10,sizeof(int));
        if(n>m) swap(n,m);
        caculate(n-1,small);
        caculate(m,big);
//        printf("index\t");
//        for(int x=0;x<=9;x++){
//            printf("[%d]\t",x);
//        }
//        printf("\nanswer\t");
        for(int x=0;x<9;x++){
            printf("%d ",big[x]-small[x]);
        }
        printf("%d",big[9]-small[9]);
        puts("");
        free(big);
        free(small);
    }
    return 0;
}
