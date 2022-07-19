/*
 * a521 12414 - Calculating Yuan Fen.c
 *
 *  Created on: 2022年7月18日
 *      Author: KeRong
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	setbuf(stdout,NULL);
	char list[20]={'\0'};
	while(scanf("%s",list)!=EOF){
		int *number=(int *)calloc(100,sizeof(int));
		int *calute=(int *)calloc(100,sizeof(int));
		int find=0;
		for(int ST=1;ST<=10000;ST++){
			int cnt=0;
			for(int x=0;x<strlen(list);x++){
				int set[9]={0};
				int run=0;
				int pick=list[x]-'A'+ST;
				while(pick>0){
					set[run++]=pick%10;
					pick/=10;
				}
				for(int y=run-1;y>=0;y--){
					number[cnt++]=set[y];
				}
			}
			while(cnt>2){

				for(int x=0;x<cnt-1;x++){
					calute[x]=(number[x]+number[x+1])%10;
					number[x]=0;
				}

				for(int x=0;x<cnt-1;x++){
					number[x]=calute[x];
				}
				if(cnt==3 && number[0]==1 && number[1]==0 && number[2]==0){
                    find=ST;
//                    printf("@%d %d %d@",number[0],number[1],number[2]);
                    break;
				}
				cnt-=1;
			}
			if(find!=0){
				break;
			}
			memset(number,0,100*sizeof(int));
			memset(calute,0,100*sizeof(int));
		}
		if(find==0){
			printf(":(\n");
		}
		else{
			printf("%d\n",find);
		}
		free(number);
		free(calute);
	}
	return 0;
}

