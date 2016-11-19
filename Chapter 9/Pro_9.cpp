#include <stdio.h>

#define false 0
#define true 1
#define isRepeat 2

typedef int isre

int main(void){
	isre nA[10] = {0};
	int c=0;
	printf("Enter a number: ");
	
	while(c != '\n'){	
		nA[c] ++;
		printf("\nc = %c , nA[c] = %d",c,nA[c]);
		c = getchar();
	}
	
	printf("Repeated digit(s):");
	
	for(int i = 0;i <10;i++){
		if (nA[i] > 1)
			printf("%d ",i);
	}
	
	return 0;
}