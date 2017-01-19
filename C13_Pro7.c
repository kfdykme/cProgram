#include <stdio.h>
#include <string.h>

int main(void){
	
	char *first_digit[] = {"twenty","thirty","furty",	                        			"fifty","sixty","seventy",
					 	 	"eighty","nighty"};
	/*
	0 2
	1 3
	2 4
	
	7 9
	*/
	
	char *ten_number[] = {"eleven","twenteen","thirteen",
	                      "fourteen","fifteen","sixteen",
	                      "seventeen","eighteen","ninteen"};
	// 1~9 ~ 0~8
	
	char *under_ten[] = {"one","two","three","four","five",
						"six","seven","eight","nine","ten"};
					
	int a, b;	
	printf("Enter a two-digit number: ");
	scanf("%2d", &a);
	
	printf("You entered the number ");
	if (a <= 10)
		printf("%s",under_ten[a-1]);
	else if (10 < a && a <= 20){
		printf("%s",ten_number[a%10 - 1]);}
	else if (20 < a && a < 100)
		printf("%s-%s",first_digit[a/10 - 2],under_ten[a%10 - 1]);
	else;	
	printf(".");
	return 0;
}