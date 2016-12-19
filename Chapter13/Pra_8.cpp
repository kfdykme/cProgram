#include <string.h>
#include <stdio.h>

int main(void){
	char str[100];
	strcpy(str, "tire_bouchon");
	strcpy(&str[4],"d-or0wi");
	strcat(str,"red?");
	
	printf("%s",str);
	
	return 0;
	
}