#include <stdio.h>

#define M 999

void encrypt(char *message, int shift);

int main(void){
	char string[M], *str = string;
	int shiftAmount;
	printf("Enter message to be encrypted: ");
	
	while((*str++ = getchar())!= '\n');
	*(str-1) = '\0';
	printf("Enter shift amount (1-25): ");
	
	scanf("%d",&shiftAmount);
	
	encrypt(string,shiftAmount);
	
	printf("Encrypted message: %s",string);
	

	return 0;
}

void encrypt(char *message, int shift){
	while ( *message != '\0'){
		if (*message <='z'&&*message>='a'){
		*message = *message + shift;
		*message = *message > 'z' ? *message - 26:*message;
	} else if (*message <='Z'&&*message>='A'){
		*message = *message + shift;
		*message = *message > 'Z' ? *message - 26:*message;
	}
	*message++ ;
	}
	*message = '\0' ;
}	

	

