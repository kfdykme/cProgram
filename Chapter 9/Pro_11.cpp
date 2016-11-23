#include <stdio.h>
#include <ctype.h>

int main(void){
	
	char frontChar[15];
	int i;
	printf("Enter phone number: ");
	
	for ( i = 0; i<15;i++){
		
		frontChar[i] = getchar();
		frontChar[i] = toupper(frontChar[i]);
		if ( frontChar[i] == '\n')
			break;
		switch(frontChar[i]){
			case 'A' : case 'B': case 'C': 
				frontChar[i] = '2';
				break;
			case 'D': case 'E': case 'F':
				frontChar[i] = '3';
				break;
			case 'G': case 'H': case 'I':
				frontChar[i] = '4';
				break;
			case 'J': case 'K': case 'L':
				frontChar[i] = '5';
				break;
			case 'M': case 'N': case 'O':
				frontChar[i] = '6';
				break;
			case 'P': case 'Q': case 'R': case 'S':
				frontChar[i] = '7';
				break;
			case 'T': case 'U': case 'V': 
				frontChar[i] = '8';
				break;
			case 'W': case 'X': case 'Y': case 'Z':   
				frontChar[i] = '9';
				break;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '0':
			case '-':
				break;
			default:
				printf("Error!");
				return 0;
				
			
		}
				
	}
	
	printf("In number form: ");
	for(int j = 0; j <=i;j++){
		printf("%c",frontChar[j]);
	}
	
	return 0;
	
}
	
	
	       