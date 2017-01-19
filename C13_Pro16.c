#include  <stdio.h>
#define M 110

void reverse(char *message);

int main(void){
	char c , s[100], *cs = s;
	printf("Enter a message:");
	while ((c = getchar()) != '\n')
		*(cs++) = c;
	*cs = '\0';
	
	reverse(s);
	printf("Reversal is: %s",s);
	return 0;
}

void reverse(char *message){
	char *f = message, *l = message, c2;
	while (*(++l) != '\0');
	//printf("%d\n",*l);
	l--;
	while (f <= l){
		c2 = *f;
		*f++ = *l;
		*l-- = c2;
	}
	
}