#include <stdio.h>

int read_line(char str[], int n);


int main(void){
	char a[100] ={' '};
  printf("get: ");
  read_line(a,10);
 
   printf("put: ");
  	 	puts(a);
	
	return 0;
	
}

int read_line(char str[], int n){
	int ch, i = 0;
	
	while((ch = getchar()) != '\n'
			)
		if ( i < n)
			if ( ch == ' '&&i>0)
				return i;
			else
				str[i++] = ch;
	str[i] = '\0';
	
	return i;

}