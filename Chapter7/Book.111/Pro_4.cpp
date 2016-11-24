#include <stdio.h>

int main(void){
	char c;
	printf("Enter phone number: ");
	scanf("%c",&c);
	while(c != '\n'){
		scanf("%c",&c);
		switch(c){
			case 'A' : case 'B': case 'C': 
				printf("2");
				break;
			case 'D': case 'E': case 'F':
				printf("3");
				break;
			case 'G': case 'H': case 'I':
				printf("4");
				break;
			case 'J': case 'K': case 'L':
				printf("5");
				break;
			case 'M': case 'N': case 'O':
				printf("6");
				break;
			case 'P': case 'Q': case 'R': case 'S':
				printf("7");
				break;
			case 'T': case 'U': case 'V': 
				printf("8");
				break;
			case 'W': case 'X': case 'Y': case 'Z':   
				printf("9");
				break;
			case '-' :
			case '1' :
			case '2' :
			case '3' :
			case '4' :
			case '5' :
			case '6' :
			case '7' :
			case '8' :
			case '9' :
			 printf("%c",c);
			 break;
		}	
	}
			printf("\nThis program is stoped");
		
	return 0;
}
	
	