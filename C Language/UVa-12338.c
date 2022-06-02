#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define min(a,b) ((a>=b)?(b):(a))
#define max(a,b) ((a>=b)?(a):(b))
long long int binary_search(char first[],char second[],long long int low,long long int high){
    long long int middle=0;
    long long int max_run=0;
    while(low<=high){
        if( high-low<=2){
//            printf("%lld %lld %lld\n",low,middle,high);
            max_run=max(max(low,middle),max(high,middle));
            if(strncmp(first,second,max_run)==0){
//                    printf("high=%d\n",max_run);
                return max_run;
            }
            else if(strncmp(first,second,high)==0){
//                    printf("high=%lld\n",high);
                return high;
            }
            else if(strncmp(first,second,high-1)==0){
//                printf("middle=%lld\n",middle);
                return high-1;
            }
            else if(strncmp(first,second,low)==0){
//                printf("low=%lld\n",low);
                return low;
            }
        }
        middle=(long long int)((low+high)/2.0+0.5);
        if(first[middle]==second[middle]){
            if(strncmp(first,second,middle)==0){
                low=middle;
            }
            else{
                high=middle;
            }
        }
        else{
            high=middle;
        }
    }
}
int main(){
    long long int case_run;
    scanf("%d",&case_run);
    int count=1;
    while(case_run--){
        int Y_list;
        scanf("%d",&Y_list);
        char **data=(char **)malloc(Y_list*sizeof(char *));
        for(int y=0;y<Y_list;y++){
            data[y]=(char *)malloc(999999*sizeof(char));
            scanf("%s",data[y]);
        }
        int active;
        scanf("%d",&active);
        printf("Case %lld:\n",count++);
        while(active--){
            int chose[2]={0};
            scanf("%d%d",&chose[0],&chose[1]);
            if(chose[0]==chose[1]){
                printf("%lld\n",strlen(data[chose[0]-1]));
            }
            else{
                long long int min_size=min(strlen(data[chose[0]-1]),strlen(data[chose[1]-1]));
                printf("%lld\n",binary_search(data[chose[0]-1],data[chose[1]-1],0,min_size));
            }
        }
        for(int y=0;y<Y_list;y++){
            free(data[y]);
        }
        free(data);
    }
    return 0;
}

