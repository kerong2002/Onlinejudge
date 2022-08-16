#include<stdio.h>
#include<math.h>
int main(){
    int list[9]={0};
    while(scanf("%d",&list[8])!=EOF){
        for(int x=7;x>=0;x--){
            scanf("%d",&list[x]);
        }
        int final_int=-1;
        for(int x=0;x<=8;x++){
            if(list[x]!=0){
                final_int=x;
                break;
            }
        }
        int first=0;
        for(int x=8;x>=1;x--){
            if(x==1){
                if(x!=final_int){
                    if(list[x]!=0 &&first==0){
                        first=1;
                        if(list[x]==1){
                            printf("x ");
                        }
                        else if(list[x]==-1){
                            printf("-x ");
                        }
                        else if(list[x]>1){
                            printf("%dx ",list[x]);
                        }
                        else if(list[x]<0){
                            printf("-%dx ",abs(list[x]));
                        }
                    }
                    else if(first==1){
                        if(list[x]==1){
                            printf("+ x ");
                        }
                        else if(list[x]==-1){
                            printf("- x ");
                        }
                        else if(list[x]>1){
                            printf("+ %dx ",list[x]);
                        }
                        else if(list[x]<0){
                            printf("- %dx ",abs(list[x]));
                        }
                    }
                }
                else if(x==final_int){
                    if(list[x]!=0 &&first==0){
                        first=1;
                        if(list[x]==1){
                            printf("x");
                        }
                        else if(list[x]==-1){
                            printf("-x");
                        }
                        else if(list[x]>1){
                            printf("%dx",list[x]);
                        }
                        else if(list[x]<0){
                            printf("-%dx",abs(list[x]));
                        }
                    }
                    else if(first==1){
                        if(list[x]==1){
                            printf("+ x");
                        }
                        else if(list[x]==-1){
                            printf("- x");
                        }
                        else if(list[x]>1){
                            printf("+ %dx",list[x]);
                        }
                        else if(list[x]<0){
                            printf("- %dx",abs(list[x]));
                        }
                    }
                }
                continue;
            }
            if(x!=final_int){
                if(list[x]!=0 &&first==0){
                    first=1;
                    if(list[x]==1){
                        printf("x^%d ",x);
                    }
                    else if(list[x]==-1){
                        printf("-x^%d ",x);
                    }
                    else if(list[x]>1){
                        printf("%dx^%d ",list[x],x);
                    }
                    else if(list[x]<0){
                        printf("-%dx^%d ",abs(list[x]),x);
                    }
                }
                else if(first==1){
                    if(list[x]==1){
                        printf("+ x^%d ",x);
                    }
                    else if(list[x]==-1){
                        printf("- x^%d ",x);
                    }
                    else if(list[x]>1){
                        printf("+ %dx^%d ",list[x],x);
                    }
                    else if(list[x]<0){
                        printf("- %dx^%d ",abs(list[x]),x);
                    }
                }
            }
            else if(x==final_int){
                if(list[x]!=0 &&first==0){
                    first=1;
                    if(list[x]==1){
                        printf("x^%d",x);
                    }
                    else if(list[x]==-1){
                        printf("-x^%d",x);
                    }
                    else if(list[x]>1){
                        printf("%dx^%d",list[x],x);
                    }
                    else if(list[x]<0){
                        printf("-%dx^%d",abs(list[x]),x);
                    }
                }
                else if(first==1){
                    if(list[x]==1){
                        printf("+ x^%d",x);
                    }
                    else if(list[x]==-1){
                        printf("- x^%d",x);
                    }
                    else if(list[x]>1){
                        printf("+ %dx^%d",list[x],x);
                    }
                    else if(list[x]<0){
                        printf("- %dx^%d",abs(list[x]),x);
                    }
                }
            }
        }
        if(first==0){
            if(list[0]==0){
                printf("0");
            }
            else if(list[0]>0){
                printf("%d",list[0]);
            }
            else if(list[0]<0){
                printf("-%d",abs(list[0]));
            }
        }
        else{
            if(list[0]>0){
                printf("+ %d",list[0]);
            }
            else if(list[0]<0){
                printf("- %d",abs(list[0]));
            }
        }
        printf("\n");
    }
    return 0;
}
