#include <stdio.h>

#define SLH 999

int main(void){
	char string[SLH];
	int shiftAmount;
	int i = 0;
	printf("Enter message to be encrypted: ");
	
	do{
		string[i++] = getchar();
	}while(string[i-1] != '\n');
	
	printf("Enter shift amount (1-25): ");
	scanf("%d",&shiftAmount);
	
	printf("Encrypted message: ");
	
	for(int j = 0; j<i;j++){
		if (string[j] <='z'&&string[j]>='a'){
		string[j] = string[j] + shiftAmount;
		string[j] = string[j] > 'z' ? string[j] - 26:string[j];
	} else if (string[j] <='Z'&&string[j]>='A'){
		string[j] = string[j] + shiftAmount;
		string[j] = string[j] > 'Z' ? string[j] - 26:string[j];
	}
}	
	for(int j = 0; j<i;j++){
		printf("%c",string[j]);
	}
	
	return 0;
	
}
	