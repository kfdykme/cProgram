#include <stdio.h>
#include <ctype.h>

int main(void){
	int h2,h1,m;
	char c;
	
	printf("Time is:");
	scanf("%d:%d %c",&h1,&m,&c);
	
	h2 = h1 %12;
	c = toupper(c);
	if (c == 'P'){
		h2 += 12;
	}
	
	printf("%d:%d",h2,m);
	
	return 0;
}