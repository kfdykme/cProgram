/* display a single month calendar */

#include <stdio.h>

int main(void){
	int days,dayOfWeek;
	
	printf("Enter number of days in month:" );
	scanf("%d", &days);
	while (days < 28){
		printf("Please enter a currect days: ");
		scanf("%d", &days);
	};
	
	printf("Enter starting day of the week ( 1 = Sun, 7 = Sat): ");
	scanf("%d", &dayOfWeek);
	
	for (int i = 1 ; i < dayOfWeek ; i++){
		printf("    ");
	}
	
	for (int d = 1; d <= days; d++){
		
		dayOfWeek += 1;
		
		if ( dayOfWeek == 7){
			printf("%4d\n", d);
			dayOfWeek = 1;
		} else {
			printf("%4d", d);
		}
	}
	
	return 0;
}