#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "good_info.txt"

int main(void){
	
	FILE *fp;
	
	fp = fopen(FILE_NAME, "r");
	
	if ( fp == NULL){
			printf("Can't open %s\n", FILE_NAME);
			exit(EXIT_FAILURE);
	}
	
	char s[10];
	int i;
	printf("Had open %s\n", FILE_NAME);
	
	do{fscanf(fp, "id:%s\n",s);
	if ( !strcmp(s,"end") )break;
	printf("  id:%s\n",s);
	fscanf(fp, "name:%s\n",s);
	printf("  name:%s\n",s);
	fscanf(fp, "price:%s\n",s);
	printf("\tprice:%s\n",s);
	fscanf(fp, "discount:%s\n",s);
	printf("\tdiscount:%s\n",s);
	fscanf(fp, "amount:%d\n",&i);
	printf("\tamount:%d\n",i);
	fscanf(fp, "remain:%d\n",&i);
	printf("\tremain:%d\n",i);
	}while(1);
	
	fclose(fp);
	return 0;
}