#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool test_extension( 
	const char *file_name,
	const char *extension){
	
	
	while(*file_name++ != '.');
//	printf("%c",*file_name);	
//	printf("%c",*extension);	
	while(toupper(*(file_name++))
	 == toupper(*(extension++))){
		//printf("%c",*file_name);	
		if ( *(file_name) == '\0')
			return true;
	}
	return false;
	}

int main(void){
	char a[] = "kfd.ykme"; 
	printf("%d",test_extension(a,"ykME"));
	
	
	return 0;
}