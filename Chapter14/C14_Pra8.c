#include <stdio.h>

#define LINE_FILE "Line of %d of file %s",__LINE__, __FILE__

int main(void){
	
	 printf(LINE_FILE);
	 return 0 ;
	 } 