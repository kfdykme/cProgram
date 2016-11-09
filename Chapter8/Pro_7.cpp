#include <stdio.h>

int main(void){
	int number[5][5];
	int rT[5] = {0},cT[5] = {0};
	
	for (int r = 0 ; r < 5; r++){
		printf("Enter row %d: ", r+1);     
		for( int c = 0 ; c < 5; c++){
			scanf("%d",&number[r][c]);
		}
	}
	for (int r = 0 ; r < 5; r++){
		for( int c = 0 ; c < 5; c++){
			rT[r] += number[r][c]; 
			cT[r] += number[c][r];
		}
	}
	
	printf("\nRow totals: ");
	for (int i = 0; i < 5; i++){
		printf("%d ", rT[i]);
	}

	
	printf("\nColumn totals: ");
	for (int i = 0; i < 5; i++){
		printf("%d ", cT[i]);
	}	
	
	return 0;
}
	