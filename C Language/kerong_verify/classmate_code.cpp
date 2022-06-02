#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 200
char all_table[200][999];
int all_table_cnt=0;
/*=========<存儲資料>============*/
typedef struct{                //名稱為student的結構
    char table_name[999];      //資料表名稱
    int  id;                   //索引
    char data_list[200][999];  //橫向標題
    char format[200][999];     //出入格式
    char document[200][200][999];   //資料
    int y_list;                //總共資料高度
    int x_list;                //總共長度
}table;
/*===============================*/
int main(){
    table *Table=(table *)malloc(MAX*sizeof(table));
    char active[1][999]={'\0'};
    while(scanf("%s",active[0])!=EOF){
        //建立
        if(strcmp(active[0],"createTable")==0){
            char name[99]={'\0'};
            scanf("%s",name);
            int not_ok=0;
            for(int x=0;x<all_table_cnt;x++){
                if(strcmp(name,all_table[x])==0){
                    printf("Table name duplicated\n");
                    not_ok=1;
                    break;
                }
            }
            if(not_ok==1){
                continue;
            }
            if(not_ok==0){
                int N;
                scanf("%d",&N);
                char input[999]={'\0'};
                scanf("%[^\n]%*c",input);
//                printf("%s",input);
                char **data=(char **)malloc(200*sizeof(char *));
                for(int x=0;x<200;x++){
                    data[x]=(char *)malloc(999*sizeof(char));
                }
                char *d=" ";
                char *pick = strtok(input, d);
                int data_cnt=0;
                while (pick != NULL) {
                    strcpy(data[data_cnt++],pick);
                    pick = strtok(NULL, d);
                }
                int not_command=0;
                if(data_cnt/2>N){
                    not_command=1;
                    printf("Incorrect command\n");
                    continue;
                }
                for(int x=1;x<2*N;x+=2){
//                    printf("%s ",data[x]);
                    int not_type=0;
                    if(strcmp(data[x],"INTEGER")==0){
                        not_type+=1;
                    }
                    if(strcmp(data[x],"STRING")==0){
                        not_type+=1;
                    }
                    if(strcmp(data[x],"FLOATING")==0){
                        not_type+=1;
                    }
                    if(not_type==0){
                        printf("Field type incorrect\n");
                        not_command=1;
                        break;
                    }
                }
                if(not_command==1){
                    continue;
                }
                for(int x=0;x<2*N;x+=2){
                    for(int y=x+2;y<2*N;y+=2){
//                        printf("%s,%s\n",data[x],data[y]);
                        if(strcmp(data[x],data[y])==0){
                            printf("Field name duplicated\n");
                            not_command=1;
                            break;
                        }
                    }
                    if(not_command==1){
                        break;
                    }
                }
                if(not_command==1){
                    continue;
                }
                if(not_command==0){
                    strcpy(Table[all_table_cnt].table_name,name);
                    strcpy(all_table[all_table_cnt],name);
                    Table[all_table_cnt].id=N;
                    int list_cnt=0;
                    for(int x=0;x<2*N;x+=2){
                        strcpy(Table[all_table_cnt].data_list[list_cnt],data[x]);
                        list_cnt+=1;
                    }
                    int format_cnt=0;
                    for(int x=1;x<2*N;x+=2){
                        if(strcmp(data[x],"INTEGER")==0){
                            strcpy(Table[all_table_cnt].format[format_cnt],data[x]);
                            format_cnt+=1;
                            continue;
                        }
                        if(strcmp(data[x],"STRING")==0){
                            strcpy(Table[all_table_cnt].format[format_cnt],data[x]);
                            format_cnt+=1;
                            continue;
                        }
                        if(strcmp(data[x],"FLOATING")==0){
                            strcpy(Table[all_table_cnt].format[format_cnt],data[x]);
                            format_cnt+=1;
                            continue;
                        }
                    }
                    Table[all_table_cnt].x_list=N;
                    Table[all_table_cnt].y_list=0;
//                    /*===========<顯示>=========*/
//                    printf("%s\n",Table[all_table_cnt].table_name);
//                    for(int x=0;x<N;x++){
//                        for(int row=0;row<Table[x].x_list;row++){
//                            printf("%s %s\n",Table[x].data_list[row],Table[x].format[row]);
//                        }
//
//                    }
//                    printf("%d",Table[all_table_cnt].x_list);
//                    /*==========================*/
                    all_table_cnt+=1;
//                    printf("%d",all_table_cnt);
                }

                for(int x=0;x<200;x++){
                    free(data[x]);
                }
                free(data);
            }
        }
        //顯示
        else if(strcmp(active[0],"showTableList")==0){
            for(int x=0;x<all_table_cnt;x++){
                printf("%s [",all_table[x]);
                for(int row=0;row<Table[x].x_list;row++){
                    printf("(%s, %s)",Table[x].data_list[row],Table[x].format[row]);
                }
                printf("]\n");
            }
        }
        else if(strcmp(active[0],"insert")==0){
            char garbage[99]={'\0'};
            scanf("%s",garbage);
            if(strcmp(garbage,"into")!=0){
                continue;
            }
            char find[99]={'\0'};
            scanf("%s%*c",find);
            char want_insert[9999]={'\0'};
            scanf("%[^\n]%*c",want_insert);
            int ok=-1;
            for(int x=0;x<all_table_cnt;x++){
                if(strcmp(all_table[x],find)==0){
                    ok=x;
                    break;
                }
            }
            if(ok==-1){
                printf("Table does not exist\n");
                continue;
            }
            if(ok>=0){
                char put[200][9999]={'\0'};
                int want_insert_cnt=0;
                char *d=" ";
                char *pick = strtok(want_insert, d);
                while (pick != NULL) {
                    strcpy(put[want_insert_cnt++],pick);
                    pick = strtok(NULL, d);
                }
                if(want_insert_cnt!=Table[ok].x_list){
                    printf("Number of fields is not consistent\n");
                    continue;
                }
                for(int x=0;x<=Table[ok].x_list;x++){
                    strcpy(Table[ok].document[Table[ok].y_list][x],put[x]);
                }
                Table[ok].y_list+=1;
//                printf("%d",Table[ok].y_list);
            }
        }
        else if(strcmp(active[0],"showTableContent")==0){
            char find[99]={'\0'};
            scanf("%s",find);
            int ok=-1;
            for(int x=0;x<all_table_cnt;x++){
                if(strcmp(all_table[x],find)==0){
                    ok=x;
                    break;
                }
            }
            if(ok==-1){
                printf("Table does not exist\n");
                continue;
            }
//            if(Table[ok].y_list==0){
//                printf("Table does not exist\n");
//                continue;
//            }
            if(ok>=0){
                for(int x=0;x<Table[ok].x_list;x++){
                    printf("%s\t",Table[ok].data_list[x]);
                }
                printf("\n");
                for(int y=0;y<Table[ok].y_list;y++){
                    for(int x=0;x<Table[ok].x_list;x++){
                        if(strcmp(Table[ok].format[x],"FLOATING")==0){
                            double float_thing=atof(Table[ok].document[y][x]);
                            printf("%.1f\t",float_thing);
                        }
                        else if(strcmp(Table[ok].format[x],"INTEGER")==0){
                            int  int_thing=atoi(Table[ok].document[y][x]);
                            printf("%d\t",int_thing);
                        }
                        else{
                            printf("%s\t",Table[ok].document[y][x]);
                        }
                    }
                    printf("\n");
                }
            }
        }
        else if(strcmp(active[0],"exit")==0){
            break;
        }
    }
    return 0;
}
/*
createTable C 3 id INTEGER name STRING weight FLOATING birthday STRING
createTable C 5 id INTEGER name STRING weight FLOATING birthday STRING high INTEGER
createTable B 4 id INTEGER name STRING weight FLOATING birthday STRING
createTable B 4 id INTEGER name STRING weight FLOATING birthday integer
createTable A 4 id INTEGER name STRING weight FLOATING birthday DATE
createTable A 4 id INTEGER name STRING weight FLOATING birthday STRING
createTable B 4 id INTEGER name STRING high FLOATING weight STRING
createTable D 4 id INTEGER id STRING weight FLOATING birthday STRING
showTableList
insert into AA 3 ABC 71.8 2000/01/09
insert into A 5 ABC 77.8 2000/01/09
insert into A 4 ABC 72.8 2000/01/09
insert into A 3 ABC 71.8 2000/01/09
insert into A 6 ABC 71.8
insert into B 5 ABC 77.8 2000/01/09
insert into B 4 DEF 67.3 2001/02/19
insert into B 3 GH 66.6 2001/06/10
insert into B 2 IJK 67.3 2001/02/19
insert into B 1 MN 67.3 2001/02/19
insert into C 5 ABC 77.8 2000/01/09
insert into C 4 DEF 67.3 2001/02/19
insert into D 99 ABC 77.8 2000/01/09
insert into D 95 DEF 67.3 2001/02/19
showTableContent A
showTableContent B
showTableContent C
showTableContent D
showTableContent DE
exit
*/
