#include <stdio.h>
#include <string.h>

void build_index_url(const char *domain, char *index_url);


int main(void){
	char i_url[999];
	
	build_index_url("knking.com",i_url);
	printf("%s",i_url);	
	return 0;
}

void build_index_url(const char *domain, char *index_url){
		
	strcpy(index_url,"http://");	
	strcat(index_url,domain);	
	strcat(index_url,"/index");	
				
}	