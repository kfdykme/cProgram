#include <stdio.h>

int main(void){
	float Commission;
	float trade;
	//define variables
	
while( trade != 0){	
	
	printf("Enter value of trade: ");
	scanf("%f", &trade);
	//enter trade 
  		
	if( trade < 2500){
		Commission = 30 + 0.017f * trade;} else if ( trade >= 2500 && trade < 6250){
			Commission = 56 + 0.0066f * trade;
			 } else if ( trade >= 6250 && trade < 20000){
			Commission = 76 + 0.0034f * trade;
			} else if ( trade >= 20000 && trade < 50000){
			Commission = 100 + 0.0022f * trade;
			}  else if ( trade >= 50000 && trade < 500000){
			Commission = 155 + 0.0011f * trade;
			} else if ( trade >= 500000){
			Commission = 255 + 0.0009f * trade;
			};
	//the main part 		
			
	if(Commission <= 39){
		Commission = 39;
	}
	//set the lowest commission
	
	printf("Commission: $%9.2f\n", Commission);
	//print the commission
   }	
	return 0;
	
}