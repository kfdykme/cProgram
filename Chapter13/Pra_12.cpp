#include <stdio.h>
#include <string.h>


void get_extension(
	const char *file_name, 
	char *extension);

	
	
int main(void) {

	char ex[100];
	char s[100];
	printf("Please enter the file name: ");
	
	scanf("%s",s);
		get_extension(s,ex);
	
	printf("%s",ex);
			
	return 0;
}


void get_extension(
	const char *file_name, 
	char *extension){
	
	int currentL = sizeof (file_name) / sizeof(file_name[0]);
//	printf("%s\n",file_name);
//	printf("%d",currentL);
	
	for ( ;currentL >= 0; currentL--)
		if ( file_name[currentL] == '.')
			break;
		else if ( currentL == 0)
			return; 
			
	currentL++;
	
	while ( file_name[currentL] != '\0')
		*extension++ = file_name[currentL++];
	*extension = '\0';	
		}
