/*
 * d673 11608 - No Problem.c
 *
 *  Created on: 2022年7月19日
 *      Author: KeRong
 */
#include<stdio.h>
#include<stdlib.h>
int main(){
	int cnt=1;
	int S;
	while(scanf("%d",&S)!=EOF){
		if(S<0) break;
		printf("Case %d:\n",cnt++);
		int *month=(int *)calloc(12,sizeof(int));
		for(int x=0;x<12;x++){
			scanf("%d",&month[x]);
		}
		int now;
		for(int x=0;x<12;x++){
			scanf("%d",&now);
			if(S>=now){
				printf("No problem! :D\n");
				S-=now;
			}
			else{
				printf("No problem. :(\n");
			}
			S+=month[x];
		}
		free(month);
	}

	return 0;
}

