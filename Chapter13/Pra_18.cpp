#include <stdio.h>
#include <string.h>
void remove_filename(char *url){
	for (int i = strlen(url); i >=0;i--)
		if (url[i] == '/'){
			url[i] = '\0';
			return;
	
	}
}
		
int main(void){
	
	char url[] = "http://www.knking.com/index.html";
	remove_filename(url);
	printf("%s",url);
	
	return 0;
	
	  }  