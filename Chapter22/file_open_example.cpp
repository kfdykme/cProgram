#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "good_info.txt"

int main(void){
	
	FILE *fp;
	
	fp = fopen(FILE_NAME, "r");
	
	if ( fp == NULL){
			printf("Can't open %s\n", FILE_NAME);
			exit(EXIT_FAILURE);
	}
	printf("Had open %s\n", FILE_NAME);
	
	fclose(fp);
	return 0;
}