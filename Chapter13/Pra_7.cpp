#include <stdio.h>
#include <string.h>


int main(void){
	char str[4] = "kfd";

	strcat(str,"");
	//strcpy(str,"");	
	//str[0] = '\0';
	printf("%s",str);
	
	return 0;
}