#include <stdio.h>
#include <stdbool.h>

int main(void){
	 long n;
	 bool nB[10] = {false};
	 int c;
	
	 
	back: 
	 printf("\n\nEnter a number: \n(enter 0 to stop this program)\n");
	 scanf("%ld", &n);
	
	if (n <= 0){
	  return 0;}
	 while ( n > 0){
	 	c = n % 10;
	 	if (nB[c]){
	 		break;
	 	}
	 	nB[c] = true;
	 	n = n / 10;
	 }
	 
	 if (n > 0)
	 	printf("Repeated digit.");
	 else 
	 	printf("No repeated digit.");
	 //test1
	 //printf("%ld", n);
	 
	 goto back;
}
	 