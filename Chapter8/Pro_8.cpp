#include <stdio.h>

int main(void){
	float scores[5][5];
	float stuAvrS[5],stuSumS[5] = {0};
	float exaAvrS[5],exaMaxS[5],exaMinS[5];
	
	for ( int r = 0 ; r < 5;r++){
		printf("Enter student1's scores: ");
		for ( int c = 0;c< 5 ; c++){
			scanf(" %f",&scores[r][c]);
			stuSumS[r] += scores[r][c];
			stuAvrS[r] = c == 4 ? sutSumS[r]/5 :0;
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
	
	return 0;
}