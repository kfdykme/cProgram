#include <stdio.h>

int count_space(const char s[]){
	int count = 0,i;
	
	for ( i = 0; s[i] != '\0' ; i++)
		if ( s[i] == ' ')
			count++;
	return count;
}

int count_space2(const char s[]){
	int count = 0;
	
	for (; *s != '\0'; s++)
		if (*s == ' ')
			count++;
	return count;
}

int count_space3(const char s[]){
	int count = 0;
	
	while(*s)
		if (*s++ == ' ')
			count++;
	return count;
}


int main(void){

	
	printf("%d\n",count_space3("kfd askhdka alksjdkl"));
	
	return 0;
	
}