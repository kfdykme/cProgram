#include <stdio.h>
#include <ctype.h>

int main(void){
	char  s[100];
	int n = 0;
	char c;
	printf("Enter a message: ");
	while ((c = toupper(getchar())) != '\n'){
		//printf("c = %c\n",c);
		if (c >= 'A' && c <='Z')
			s[n++] = c;
	}
	n--;
	//printf("n = %d\n",n);
	for (int i = 0; i <= n; i++){
		//printf("s[%d] = %c\ts[%d] = %c\n",i,s[i],n-i,s[n-i]);
		if ( s[i] != s[n-i]){
			printf("Not a palindrome");
			return 0;
		}
	}
	
	printf("Palindrome");
	return 0;	
}
	
	