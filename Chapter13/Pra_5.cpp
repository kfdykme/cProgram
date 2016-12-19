#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void capitalize(char str[]);

void capitalize2(char str[]);

int main(void){
	
	char a[100];
	
	scanf("%s",a);
	
	capitalize2(a);
	
	printf("You have entered: %s",a);
	
	return 0;
}

void capitalize(char str[]){
	
	for (int i = 0 ; str[i] != '\0'; i++){
		if (str[i] <= 'z' 
			&& str[i] >= 'a'){
			
			str[i] =  toupper(str[i]);
		}
	} 
	
}

void capitalize2(char str[]){
	int l = sizeof(str) / sizeof(str[0]);
	char *p = str;
	for (; *p != '\0'; *p++){
		if (*p <= 'z' 
		&& *p >= 'a'){
			*p =  toupper(*p);
		}
	} 
	
}
