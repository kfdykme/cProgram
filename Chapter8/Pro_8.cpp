#include <stdio.h>

int main(void){
	float scores[5][5];
	float stuAvrS[5],stuSumS[5] = {0};
	float exaAvrS[5] = {0},exaMaxS[5] = {0},exaMinS[5];
	
	for ( int r = 0 ; r < 5;r++){
		printf("Enter student1's scores: ");
		for ( int c = 0;c< 5 ; c++){
			scanf(" %f",&scores[r][c]);
			stuSumS[r] += scores[r][c];
			stuAvrS[r] = c == 4 ? stuSumS[r]/5 :0;
		}
	}
	for ( int r = 0 ; r < 5;r++){
		for ( int c = 0;c< 5 ; c++){
			exaAvrS[r] += scores[c][r];
			exaAvrS[r] = c == 4 ? exaAvrS[r]/5 :exaAvrS[r];
			exaMaxS[r] = scores[c][r] > exaMaxS[r] ? scores[c][r]:exaMaxS[r];
			exaMinS[r] = c == 0 ? scores[c][r]:exaMinS[r];  
			exaMinS[r] = scores[c][r] < exaMinS[r] ? scores[c][r]:exaMinS[r];
		}
	}
	
	printf("\nThe students Avr scores: ");
	for (int i = 0;i < 5;i++){
		printf("%.2f ",stuAvrS[i]);
	}
	printf("\nThe students Sum scores: ");
	for (int i = 0;i < 5;i++){
		printf("%.2f ",stuSumS[i]);
	}
	printf("\nThe exames Avr scores: ");
	for (int i = 0;i < 5;i++){
		printf("%.2f ",exaAvrS[i]);
	}
	printf("\nThe exames Min scores: ");
	for (int i = 0;i < 5;i++){
		printf("%.2f ",exaMinS[i]);
	}
	printf("\nThe exames Max scores: ");
	for (int i = 0;i < 5;i++){
		printf("%.2f ",exaMaxS[i]);
	}
	
	return 0;
}