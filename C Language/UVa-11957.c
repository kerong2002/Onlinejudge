#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//void search(int x_pos,int y_pos,char **map){
////    printf("(%d,%d)\n",y_pos,x_pos);
////    printf("------<test>-----\n");
////    for(int y=0;y<n;y++){
////        for(int x=0;x<n;x++){
////            printf("%c ",map[y][x]);
////        }
////        printf("\n");
////    }
//    map[y_pos][x_pos]='@';
//    if(y_pos==0){
//        ans+=1;
//        map[y_pos][x_pos]='.';
//        return;
//    }
//    if(x_pos>0&&y_pos>0 && map[y_pos-1][x_pos-1]=='.'){
////            printf("@1\n");
//        search(x_pos-1,y_pos-1,map);
//    }
//    if(x_pos<n-1&&y_pos>0 && map[y_pos-1][x_pos+1]=='.'){
////        printf("@2\n");
//        search(x_pos+1,y_pos-1,map);
//    }
//    if(x_pos>0&&y_pos>0 && map[y_pos-1][x_pos-1]=='B'){
//        if(x_pos>1&&y_pos>1 && map[y_pos-2][x_pos-2]=='.'){
////            printf("@3");
//            search(x_pos-2,y_pos-2,map);
//        }
//    }
//    if(x_pos<n-1&&y_pos>0 && map[y_pos-1][x_pos+1]=='B'){
//        if(x_pos+1<n-1&&y_pos>1 && map[y_pos-2][x_pos+2]=='.'){
////            printf("@4");
//            search(x_pos+2,y_pos-2,map);
//        }
//    }
//map[y_pos][x_pos]='.';
////     return ;
//}
int main(){
    int run;
    long long int ans=0;
    int n;
    scanf("%d",&run);
    for(int tt=1;tt<=run;tt++){
        scanf("%d",&n);

        char **map=(char **)calloc(n,sizeof(char *));
        for(int y=0;y<n;y++){
            map[y]=(char *)calloc(n+1,sizeof(char));
            scanf("%s",map[y]);
        }
        ans=0;
        int dp[110][110]={0};
        for(int y=n-1;y>=0;y--){
            for(int x=0;x<n;x++){
                if(map[y][x]=='W'){
//                        printf("@@%d,%d@@",y,x);
                    dp[y][x]=1;
                    continue;
                }
                if(map[y][x]=='B'){
                    continue;
                }
                if(x+1<n && y+1<n && map[y+1][x+1]!='B'){
                    dp[y][x]+=dp[y+1][x+1];
                }
                if(x>0 && y+1<n && map[y+1][x-1]!='B'){
                    dp[y][x]+=dp[y+1][x-1];
                }
                if(x+1<n && y+1<n && map[y+1][x+1]=='B'){
                    if(x+2<n && y+2<n && map[y+2][x+2]!='B'){
                        dp[y][x]+=dp[y+2][x+2];
                    }
                }
                if(x>0 && y+1<n && map[y+1][x-1]=='B'){
                    if(x>1 && y+2<n && map[y+2][x-2]!='B'){
                        dp[y][x]+=dp[y+2][x-2];
                    }
                }
                dp[y][x] %= 1000007;
            }
        }
//        for(int y=0;y<n;y++){
//            for(int x=0;x<n;x++){
//                printf("%d ",dp[y][x]);
//            }
//            printf("\n");
//        }
        for(int x=0;x<n;x++){
//            printf("%d ",dp[0][x]);
            ans += dp[0][x] % 1000007;
        }
         printf("Case %d: %lld\n",tt,ans%1000007);
        for(int y=0;y<n;y++){
            free(map[y]);
        }
        free(map);

    }
    return 0;
}
